#pragma once
#include <ctime>

class Fecha{

private:
    int dia;
    int mes;
    int anio;


public:
    Fecha(int d=0,int m=0,int a=0){
    dia=d;
    mes=m;
    anio=a;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    bool setDia(int d){
    if(d>0 && d<=31){
        dia=d;
        return true;
    }
    dia=-1;
    return false;
    }

    bool setMes(int m){
    if(m>0 && m<=12){
        mes=m;
        return true;
    }
    mes=-1;
    return false;
    }

    void setAnio(int a){anio=a;}
    void CargarFecha();
    void MostrarFecha();
    bool ValidarFecha();

};


void Fecha::CargarFecha(){
cout<<"Cargar anio: ";
cin>>anio;
cout<<"Cargar mes: ";
cin>>mes;
cout<<"Cargar dia: ";
cin>>dia;

while (ValidarFecha()==false) {
cout << "La fecha ingresada no es válida, por favor ingrese una fecha válida" << endl;
cout << "DIA: ";
cin >> dia;
cout << "MES: ";
cin >> mes;
cout << "ANIO: ";
cin >> anio;
}
}


void Fecha::MostrarFecha(){
 cout << dia << "/" << mes << "/" << anio;
}


bool Fecha::ValidarFecha() {
    time_t ahora = time(0);
    tm* tiempo_actual = localtime(&ahora);

    if (anio > (tiempo_actual->tm_year + 1970)) {
        return false;
    }
    if (mes > (tiempo_actual->tm_mon+1)) {
    return false;
    }
    if (dia > tiempo_actual->tm_mday) {
                return false;
    }
    return true;
}


void cargarCadena(char *pal, int tam){
    int i;
    fflush (stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}


