#pragma once

class ArchivoMunicipio{

private:
    char nombre[30];

    public:
    ArchivoMunicipio(const char *n="municipios.dat"){strcpy(nombre,n);}
    void altaMunicipio();
    void grabarRegistro(Municipios obj);
    int buscarRegistro(int n);
    Municipios leerRegistro(int pos);
    void bajaMunicipio();
    int contarRegistros();
    void listarArchivo();
    void leerRegistros(int posicion);
    void modificarRegistro(Municipios obj, int pos);
    Municipios listarPorNumero(int num);
    void listarDeA1();
    void modificarCantidadHabitantes();
    bool copiaSeguridad(const char *nombreBkp="municipios.bkp");
    bool cargarCopia();
};



Municipios ArchivoMunicipio::listarPorNumero(int numemp){
    Municipios obj;
    FILE *pemp=fopen(nombre,"rb");
    if(pemp==nullptr){
        obj.setNumero(-1);
        return obj;
    }
    while(fread(&obj,sizeof(Municipios),1,pemp)==1){
    if(numemp==obj.getNumero()){
        fclose(pemp);
        return obj;
    }
    }
fclose(pemp);
obj.setNumero(-2);
return obj;
}


void ArchivoMunicipio::listarDeA1(){
    int numeroMun;
    cout<<"Ingresar numero de municipio a listar: ";
    cin>>numeroMun;
    ArchivoMunicipio obj;
    Municipios obje;
    obje=obj.listarPorNumero(numeroMun);
    if(obje.getNumero() == -1) {
    cout << "No se pudo abrir el archivo."<<endl;
    }else if (obje.getNumero() == -2) {
    cout << "No hay una empresa con ese numero."<<endl;
    }else{
    obje.Mostrar();
}
}

void ArchivoMunicipio::grabarRegistro(Municipios obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

int ArchivoMunicipio::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Municipios);
}

void ArchivoMunicipio::listarArchivo(){
    int cant=contarRegistros();
    Municipios obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()==true){cout<<endl;}
    }
}

Municipios ArchivoMunicipio::leerRegistro(int pos){
    Municipios obj;
    obj.setNumero(-1);
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setNumero(-2);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoMunicipio::copiaSeguridad(const char *nombreBkp){
    FILE *pBak;
    Municipios reg;
    pBak=fopen(nombreBkp,"wb");
    if(pBak==nullptr){
    cout<<"No se pudo abrir"<<endl;
    return false;
}
    int cantReg = contarRegistros();
    for(int i=0;i<cantReg;i++){
    reg=leerRegistro(i);
    fwrite(&reg,sizeof reg,1,pBak);
}

    fclose(pBak);
}


bool ArchivoMunicipio::cargarCopia(){
    FILE *p;
    Municipios reg;
    ArchivoMunicipio arcMun("empresas.bkp");
    p=fopen(nombre,"wb");
    if(p==nullptr){
    cout<<"No se pudo abrir"<<endl;
    return false;
}
    int cantReg = arcMun.contarRegistros();
    for(int i=0;i<cantReg;i++){
    reg=arcMun.leerRegistro(i);
    fwrite(&reg,sizeof reg,1,p);
}
    fclose(p);
}

int ArchivoMunicipio::buscarRegistro(int num){
    int cant=contarRegistros();
    Municipios obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(num==obj.getNumero()){
            return i;
        }
    }
    return -1;
}


void ArchivoMunicipio::modificarRegistro(Municipios obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoMunicipio::modificarCantidadHabitantes(){
int num;
cout<<"Ingresar el numero de municipio"<<endl;
cin>>num;
ArchivoMunicipio muni;
int posicion=muni.buscarRegistro(num);
if(posicion<0){
    cout<<"no se encontro municipio con ese numero"<<endl;
    return;
}
Municipios obj;
obj=muni.leerRegistro(posicion);
int cantidad;
cout<<"Introducir nueva cantidad de habitantes: "<<endl;
cin>>cantidad;
obj.setCantidadHabitantes(cantidad);
muni.modificarRegistro(obj,posicion);
}


void ArchivoMunicipio::bajaMunicipio(){
    ArchivoMunicipio arcEmp;
    int num;
    cout<<"INGRESE EL NUMERO DE MUNICIPIO A DAR DE BAJA: ";
    cin>>num;
    int pos=arcEmp.buscarRegistro(num);
    if(pos<0){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Municipios obj;
    obj = arcEmp.leerRegistro(pos);
    obj.setEstado(false);
    arcEmp.modificarRegistro(obj, pos);
}

void ArchivoMunicipio::altaMunicipio(){
    ArchivoMunicipio arcEmp;
    Municipios obj;
    obj.Cargar();
    int pos=arcEmp.buscarRegistro(obj.getNumero());
    if(pos != -1){
        cout<<"YA EXISTE UN MUNICIPIO CON ESE NUMERO EN EL ARCHIVO"<<endl;
        obj.setEstado(false);
    }
    if(obj.getEstado()==true){
        arcEmp.grabarRegistro(obj);
    }else{
        cout<<"NO SE PUDO GRABAR EL MUNI"<<endl;
    }
}

