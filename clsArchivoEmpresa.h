#pragma once

class ArchivoEmpresas{
    private:
        char nombre[30];
    public:
        ArchivoEmpresas(const char *n="empresas.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        void grabarRegistro(Empresa obj);
        void modificarRegistro(Empresa obj, int pos);
        Empresa leerRegistro(int pos);
        void listarArchivo();
        int contarRegistros();
        int buscarRegistro(int num);
        bool copiaSeguridad(const char *nombreAr="empresas.bkp");
        bool cargarCopia();
        bool listarCopiaSeguridad(const char *nombreAr="empresas.bkp");
        Empresa listarPorNumero(int numemp);

};

Empresa ArchivoEmpresas::listarPorNumero(int numemp){
    Empresa obj;
    FILE *pemp=fopen(nombre,"rb");
    if(pemp==nullptr){
        obj.setNumEmp(-1);
        return obj;
    }
    while(fread(&obj,sizeof(Empresa),1,pemp)==1){
    if(numemp==obj.getNumEmp()){
        fclose(pemp);
        return obj;
    }
    }
fclose(pemp);
obj.setNumEmp(-2);
return obj;

}

//void modificarFechaDeCreacion(){
//ArchivoEmpresas archivo;
//Empresa empresa;
//Fecha aux;
//int numeroEmpresa;
//cout<<"Numero de empresa a modificar: "<<endl;
//cin>>numeroEmpresa;
//int pos=archivo.PosicionRegistro(numeroEmpresa);
//empresa=archivo.buscarRegistro(numeroEmpresa);
//if(empresa.getCategoria()>0){
//    cout<<"Ingresar nueva fecha: "<<endl;
//    aux.Cargar();
//    empresa.setFecha(aux);
//    if(archivo.modificarRegistro(empresa,pos)){
//    cout<<"Fecha Actualizada"<<endl;
//    }
//}else{
//cout<<"ERROR AL MODIFICAR FECHA"<<endl;
//}
//}

bool ArchivoEmpresas::listarCopiaSeguridad(const char *nombreAr){
    FILE *p=fopen(nombreAr,"rb");
    Empresa reg;
    if(p==nullptr){
    cout<<"No se pudo abrir"<<endl;
    return false;
}
    while(fread(&reg,sizeof reg,1,p)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
}

bool ArchivoEmpresas::copiaSeguridad(const char *nombreAr){
    FILE *pBak;
    Empresa reg;
    pBak=fopen(nombreAr,"wb");
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

bool ArchivoEmpresas::cargarCopia(){
    FILE *p;
    Empresa reg;
    ArchivoEmpresas arcEmp("empresas.bkp");
    p=fopen(nombre,"wb");
    if(p==nullptr){
    cout<<"No se pudo abrir"<<endl;
    return false;
}
    int cantReg = arcEmp.contarRegistros();
    for(int i=0;i<cantReg;i++){
    reg=arcEmp.leerRegistro(i);
    fwrite(&reg,sizeof reg,1,p);
}
    fclose(p);
}

void ArchivoEmpresas::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

void ArchivoEmpresas::grabarRegistro(Empresa obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoEmpresas::modificarRegistro(Empresa obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

Empresa ArchivoEmpresas::leerRegistro(int pos){
    Empresa obj;
    obj.setNumEmp(-1);
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setNumEmp(-2);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoEmpresas::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Empresa);
}

void ArchivoEmpresas::listarArchivo(){
    int cant=contarRegistros();
    Empresa obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()==true){cout<<endl;}
    }
}

int ArchivoEmpresas::buscarRegistro(int num){
    int cant=contarRegistros();
    Empresa obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(num==obj.getNumEmp()){
            return i;
        }
    }
    return -1;
}
