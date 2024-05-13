#pragma once

//void modificarFecha(){
//int numemp:
//cout<<"Numero de empresa a modificar fecha: ";
//cin>>numemp;
//
//
//
//}


void listarDeA1(){
    int numeroempresa;
    cout<<"Ingresar numero de empresa a listar: ";
    cin>>numeroempresa;
    ArchivoEmpresas obj;
    Empresa obje;
    obje=obj.listarPorNumero(numeroempresa);
    if(obje.getNumEmp() == -1) {
    cout << "No se pudo abrir el archivo."<<endl;
    }else if (obje.getNumEmp() == -2) {
    cout << "No hay una empresa con ese numero."<<endl;
    }else{
    obje.Mostrar();
}
}

void altaEmpresa(){
    ArchivoEmpresas arcEmp("empresas.dat");
    Empresa obj;
    obj.Cargar();
    int pos=arcEmp.buscarRegistro(obj.getNumEmp());
    if(pos != -1){
        cout<<"YA EXISTE UNA EMPRESA CON ESE NUMERO EN EL ARCHIVO"<<endl;
        obj.setEstado(false);
    }
    if(obj.getEstado()==true){
        arcEmp.grabarRegistro(obj);
    }else{
        cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
    }
}

void buscarRegistro(){
    int num;
    cout<<"INGRESE EL NUMERO DE LA EMPRESA A BUSCAR: ";
    cin>>num;
    ArchivoEmpresas arcEmp;
    Empresa obj;
    int pos = arcEmp.buscarRegistro(num);
    if(pos<0){
        cout<<"NO EXISTE UNA EMPRESA CON ESE NUMERO EN EL ARCHIVO"<<endl;
        return;
    }
    obj = arcEmp.leerRegistro(pos);
    system("cls");
    obj.Mostrar();
}

void bajaLogica(){
    ArchivoEmpresas arcEmp;
    int num;
    cout<<"INGRESE EL NUMERO DE EMPRESA A DAR DE BAJA: ";
    cin>>num;
    int pos=arcEmp.buscarRegistro(num);
    if(pos<0){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Empresa obj;
    obj = arcEmp.leerRegistro(pos);
    obj.setEstado(false);
    arcEmp.modificarRegistro(obj, pos);
}
