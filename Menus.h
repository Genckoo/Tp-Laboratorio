#pragma once



void MenuConfiguracion(){
while(true){
    ArchivoEmpresas obj;
    ArchivoMunicipio sub;
    int opc;
    system("cls");
    cout<<"MENU EMPRESAS"<<endl;
     cout<<"---------------------------------------"<<endl;
    cout<<"1 - COPIA DE SEGURIDAD ARCHIVO EMPRESAS"<<endl;
    cout<<"2 - COPIA DE SEGURIDAD ARCHIVO MUNICIPIOS"<<endl;
    cout<<"3 - RESTAURAR EL ARCHIVO DE EMPRESAS"<<endl;
    cout<<"4 - RESTAURAR EL ARCHIVO DE MUNICIPIOS"<<endl;
    cout<<"5 - ESTABLECER DATOS DEL INICIO"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"0 - Salir"<<endl;
    cin>>opc;
    system("cls");
    switch(opc){

case 1:
    system("cls");
    obj.copiaSeguridad();
    cout<<"Copia realizada con exito"<<endl;
    break;

case 2:
    system("cls");
    sub.copiaSeguridad();
    cout<<"Copia realizada con exito"<<endl;
    break;

case 3:
    system("cls");
    bool op;
    cout<<"Estas seguro que queres cargar la copia de EMPRESAS? 1 - SI / 2 - NO: ";
    cin>>op;
    if(op==1){
    obj.cargarCopia();
    cout<<"Copia restaurada!"<<endl;
    }

    break;

case 4:
    system("cls");
    bool opi;
    cout<<"Estas seguro que queres cargar la copia de MUNICIPIOS? 1 - SI / 2 - NO: ";
    cin>>opi;
    if(op==1){
    sub.cargarCopia();
    cout<<"Copia restaurada!"<<endl;
    }
    break;

case 5:
//    EstablecerDatosI();
    break;


case 0:
    return;

default:
    cout<<"Opcion invalida";
    system("pause");


    }
system("pause");
}
}



void MenuEmpresa(){
while(true){
    ArchivoEmpresas obj;
    int opc;
    system("cls");
    cout<<"MENU EMPRESAS"<<endl;
     cout<<"---------------------------------------"<<endl;
    cout<<"1 - Agregar empresa"<<endl;
    cout<<"2 - Listar empresa por numero"<<endl;
    cout<<"3 - Listar todas las empresas"<<endl;
    cout<<"4 - Modificar fecha de creacion"<<endl;
    cout<<"5 - Eliminar registro"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"0 - Salir"<<endl;
    cin>>opc;
    system("cls");
    switch(opc){

case 1:
    system("cls");
    altaEmpresa();
    break;
case 2:
    listarDeA1();

    break;
case 3:
    obj.listarArchivo();
    break;
case 4:
//    modificarFecha();
    break;
case 5:
    system("cls");
    bajaLogica();
    break;

case 6:
    obj.limpiarArchivo();
    break;

case 0:
    return;

default:
    cout<<"Opcion invalida";
    system("pause");


    }
system("pause");
}
}


void MenuMunicipios(){
while(true){
    ArchivoMunicipio obj;
    int opc;
    system("cls");
    cout<<"MENU MUNICIPIOS"<<endl;
     cout<<"---------------------------------------"<<endl;
    cout<<"1 - Agregar municipios"<<endl;
    cout<<"2 - Listar municipio por numero"<<endl;
    cout<<"3 - Listar todos los municipios"<<endl;
    cout<<"4 - Modificar cantidad de habitantes"<<endl;
    cout<<"5 - Eliminar municipio"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"0 - Salir"<<endl;
    cin>>opc;
    system("cls");
    switch(opc){

case 1:
    system("cls");
    obj.altaMunicipio();

    break;
case 2:
    system("cls");
    obj.listarDeA1();

    break;
case 3:
    system("cls");
    obj.listarArchivo();
    break;

case 4:
    system("cls");
    obj.modificarCantidadHabitantes();
    break;

case 5:
    system("cls");
    obj.bajaMunicipio();
    cout<<"Se ha dado de baja con exito"<<endl;

    break;

//case 6:
//
//    break;

case 0:
    return;

default:
    cout<<"Opcion invalida";
    system("pause");


    }
system("pause");
}
}

void menuPrincipal(){
    while(true)
    {
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"1.MENU EMPRESAS"<<endl;
        cout<<"2.MENU MUNUCIPIOS"<<endl;
        cout<<"3.REPORTES"<<endl;
        cout<<"4.CONFIGURACION"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"0.FIN DEL PROGRAMA"<<endl;
        int op;
        cout<<"INGRESAR OPCION: ";
        cin>>op;
        switch(op)
        {
        case 1:
            MenuEmpresa();
            break;
        case 2:
            MenuMunicipios();
            break;
        case 3:
            //reportes();
            break;
        case 4:
            MenuConfiguracion();
            break;
        case 0:
            return;
            break;
        default:

            system("cls");
            cout<<"POR FAVOR INGRESE UNA OPCION VALIDA"<<endl;

            break;

        }
        system("pause");
    }
}

