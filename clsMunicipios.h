#pragma once

class Municipios{
    private:
        int numero;
        char nombre[30];
        int seccion;
        int cantidadHabitantes;
        bool estado;

    public:
        Municipios(){bool estado=false;}
        void setNumero(int n){numero=n;}
        void setEstado(bool e){estado=e;}
        void setSeccion(int s){seccion=s;}
        void setCantidadHabitantes(int c){cantidadHabitantes=c;}
        void Cargar();
        void Mostrar();
        int getNumero(){return numero;}
        int getCantidadHabitantes(){return cantidadHabitantes;}
        int getSeccion(){return seccion;}
        bool getEstado(){return estado;}
        const char *getNombre(){return nombre;}

};

void Municipios::Cargar(){
cout<<"Ingresar numero de municipio: ";
cin>>numero;
if(numero<0 && numero>135){
cout<<"invalido";
}

cout<<"Ingresar nombre: ";
cargarCadena(nombre,29);

cout<<"Ingresar seccion: ";
cin>>seccion;
if(seccion<1 && seccion>9){
cout<<"Numero de seccion invalido"<<endl;
return;
}

cout<<"Ingresar cantidad habitantes: ";
cin>>cantidadHabitantes;
if(cantidadHabitantes<0){
cout<<"Solo se admiten valores positivos";
return;
}
estado=true;
}

void Municipios::Mostrar(){
if(estado==true){
    cout<<"Numero de municipio "<<numero<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Seccion: "<<seccion<<endl;
    cout<<"Cantidad de habitantes: "<<cantidadHabitantes<<endl;
}
}
