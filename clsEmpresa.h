#pragma once

class Empresa{

private:
    int numEmp;
    char nombre[30];
    int cantEmpleados;
    int numeroMunicipio;
    int categoria;
    Fecha fecha;
    float facturacionAnual;
    bool estado;

    public:
    Empresa(){estado=false;}
    int getNumEmp(){return numEmp;}
    const char *getNombre(){return nombre;}
    int getCantidadEmpleados(){return cantEmpleados;}
    int getCategoria(){return categoria;}
    int getNumeroMunicipio(){return numeroMunicipio;}
    float getFacturacionAnual(){return facturacionAnual;}
    bool getEstado(){return estado;}
    void setNumEmp(int newEmp){numEmp=newEmp;}
    void setNombre(const char *nom){strcpy(nombre,nom);}
    void setCategoria(int c){categoria=c;}
    void setCantidadEmpleados(int can){cantEmpleados=can;}
    void setNumeroMunicipio(int n){numeroMunicipio=n;}
    void setFacturacion(float fact){facturacionAnual=fact;}
    void setEstado(bool e){estado=e;}

    void Cargar();
    void Mostrar();
};


void Empresa::Cargar(){
cout<<"Ingresar numero de empresa: ";
cin>>numEmp;
cout<<"Ingresar nombre de empresa: ";
cargarCadena(nombre,29);
cout<<"Ingresar cantidad de empleados: ";
cin>>cantEmpleados;
if(cantEmpleados<0){
cout<<"No se admiten numeros inferiores a 0"<<endl;
    return;
}
cout<<"Ingresar categoria: ";
cin>>categoria;
cout<<"Ingrsar numero de municipio: ";
cin>>numeroMunicipio;
if(numeroMunicipio<1 || numeroMunicipio>135){
    return;
}
cout<<"Fecha de creacion "<<endl;
fecha.CargarFecha();
cout<<"Ingresar facturacion anual: ";
cin>>facturacionAnual;
estado=true;
}

void Empresa::Mostrar(){
if(estado==true){
    cout<<"Numero de empresa: "<<numEmp<<endl;
    cout<<"Nombre de empresa: "<<nombre<<endl;
    cout<<"Cantidad Empleados: "<<cantEmpleados<<endl;
    cout<<"Categoria: "<<categoria<<endl;
    cout<<"Numero de municipio: "<<numeroMunicipio<<endl;
    cout<<"Fecha "<<endl;
    fecha.MostrarFecha();
    cout<<endl;
    cout<<"Facturacion anual: "<<facturacionAnual;
}
}
