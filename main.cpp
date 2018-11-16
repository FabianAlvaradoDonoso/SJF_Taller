#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

COORD coord={0,0};
void gotoxy(int x,int y){
   coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
struct nodo{
    string Nombre;
    float tLlegada;
    float rafaga;
    struct nodo *link;
};
typedef struct nodo *Lista;

void cuadroPrincipal(){
    int i=0x00;
    printf("%c", 201);

    for(i=0;i<50;i++)
    {
        printf("%c", 205);
    }

    i = 0x00;
    printf("%c\n", 187);

    for(i=0;i<5;i++)
    {
        if(i==2){
           printf("%c\t\t  P R I N C I P A L  \t\t   %c\n", 186, 186);
        }else{
            printf("%c\t\t\t   \t\t\t   %c\n", 186, 186);
        }
    }

    i=0x00;
    printf("%c", 200);

    for(i=0;i<50;i++)
    {
        printf("%c", 205);

    }

    printf("%c\n", 188);
}
void cuadroIngresoDatos(){
    int i=0x00;
    printf("%c", 201);

    for(i=0;i<50;i++)
    {
        printf("%c", 205);
    }

    i = 0x00;
    printf("%c\n", 187);

    for(i=0;i<5;i++)
    {
        if(i==2){
           printf("%c\t      I N G R E S O    D A T O S  \t   %c\n", 186, 186);
        }else{
            printf("%c\t\t\t   \t\t\t   %c\n", 186, 186);
        }
    }

    i=0x00;
    printf("%c", 200);

    for(i=0;i<50;i++)
    {
        printf("%c", 205);

    }

    printf("%c\n", 188);
}
void cuadroVerDatos(){
    int i=0x00;
    printf("%c", 201);

    for(i=0;i<50;i++)
    {
        printf("%c", 205);
    }

    i = 0x00;
    printf("%c\n", 187);

    for(i=0;i<5;i++)
    {
        if(i==2){
           printf("%c\t\t  V E R   D A T O S  \t\t   %c\n", 186, 186);
        }else{
            printf("%c\t\t\t   \t\t\t   %c\n", 186, 186);
        }
    }

    i=0x00;
    printf("%c", 200);

    for(i=0;i<50;i++)
    {
        printf("%c", 205);

    }

    printf("%c\n", 188);
}
void cuadroNumeroDatos(float n){
    int i=0x00;
    printf("%c", 201);

    for(i=0;i<50;i++)
    {
        printf("%c", 205);
    }

    i = 0x00;
    printf("%c\n", 187);

    for(i=0;i<5;i++)
    {
        if(i==2){
           printf("%c\t\t    D A T O  %g  \t\t   %c\n", 186, n, 186);
        }else{
            printf("%c\t\t\t   \t\t\t   %c\n", 186, 186);
        }
    }

    i=0x00;
    printf("%c", 200);

    for(i=0;i<50;i++)
    {
        printf("%c", 205);

    }

    printf("%c\n", 188);
}
void dibujarHeadTabla(){
    cuadroVerDatos();
    int i=0x00;
    //Esquina superior izquierda
    printf("%c", 201);

    i=0x00;
    //Borde superior

    for(i=0;i<55;i++)
    {

        if(i == 25 || i == 40){
            printf("%c", 203);
        }else{
            printf("%c", 205);
        }

    }

    //Esquina superior derecha
    printf("%c\n", 187);

    i=0x00;
    //Bordes del medio
    for(i=0;i<10;i++)
    {
        for(i=0;i<57;i++)
        {
            if(i == 0 || i == 26 || i == 41 || i == 56){
                printf("%c", 186);
            }else{
                printf("%c", 32);
            }
        }
        printf("\n");
    }

    //Esquina inferior izquierda
    printf("%c", 204);

    i=0x00;
    //Borde Inferior
    for(i=0;i<55;i++)
    {
       if(i == 25 || i == 40){
            printf("%c", 206);
        }else{
            printf("%c", 205);
        }
    }

    //Esquina inferior derecha
    printf("%c\n", 185);

    gotoxy(10,8);
    printf("PROCESO");
    gotoxy(29,8);
    printf("T. LLEGADA");
    gotoxy(46,8);
    printf("RAFAGA");
    gotoxy(0,10);
}
void dibujarFooterTabla(){
    printf("%c", 200);
    for(int i=0;i<55;i++)
    {
       if(i == 25 || i == 40){
            printf("%c", 202);
        }else{
            printf("%c", 205);
        }
    }
    printf("%c\n", 188);
}
void insertarFinal(Lista &lista, string nombre, float tLlegada, float rafaga){
    Lista t, q = new(struct nodo);

    q->Nombre = nombre;
    q->tLlegada = tLlegada;
    q->rafaga = rafaga;
    q->link = NULL;

    if(lista==NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while(t->link!=NULL)
        {
            t = t->link;
        }
        t->link = q;
    }

}
void llenarTablaDatos(Lista &lista){

    bool flagStop = false;
    int numeroDato = 1;
    while(!flagStop){
        system("cls");
        cuadroNumeroDatos(numeroDato);
        string _nombre;
        float _tLlegada;
        float _rafaga;

        //------- SET NOMBRE ----------------
        cout << "Ingrese Nombre Proceso (-1 para finalizar): "; fflush(stdin); getline(cin, _nombre);
        if(_nombre == "-1") {
            flagStop = true;
            break;
        }

        //----------------------- SET TIEMPO LLEGADA --------------------------------
        string str;
        cout << "Ingrese Tiempo de Llegada: ";
        while( getline( cin, str ) ) {
            const char *idx = str.c_str( );
            while( (*idx && *idx >= '0' && *idx <= '9') || *idx == '.' || *idx == ' ') ++idx;
            if( !( *idx ) ) break;
            cout << "Entrada inválida.\n";
        }
        _tLlegada = atof( str.c_str( ) );

        //--------------------------- SET RAFAGA ------------------------------------
        string str1;
        cout << "Ingrese Rafaga: ";
        while( getline( cin, str1 ) ) {
            const char *idx = str1.c_str( );
            while( (*idx && *idx >= '0' && *idx <= '9') || *idx == '.' || *idx == ' ') ++idx;
            if( !( *idx ) ) break;
            cout << "Entrada inválida.\n";
        }
        _rafaga = atof( str1.c_str( ) );
        //----------------------------------------------------------------------------

        insertarFinal(lista, _nombre, _tLlegada, _rafaga);
        numeroDato++;

    }
    system("pause");

}
void imprimirTabla(Lista l){
    system("cls");


    dibujarHeadTabla();

    Lista q;
    q = l;
    if(q != NULL){
            int i = 0;
        while(q != NULL)
        {
            printf("%c\t%s", 186, q->Nombre.c_str()); gotoxy(26, i+10);
            printf("%c\t%g", 186, q->tLlegada); gotoxy(41, i+10);
            printf("%c\t%g", 186, q->rafaga); gotoxy(56, i+10);
            printf("%c\n", 186);
            q = q->link;
            i++;
        }
    }else{
        printf("%c\t%s", 186, "Lista Vacia"); gotoxy(26, 10);
        printf("%c\t%s", 186, "--"); gotoxy(41, 10);
        printf("%c\t%s", 186, "--"); gotoxy(56, 10);
        printf("%c\n", 186);
    }


    dibujarFooterTabla();

    //gotoxy(0, numeroDatos+11);

}
void mostrarMenuIngresoDatos(Lista &l){

    llenarTablaDatos(l);
    int opcionMenuIngresoDatos;

    while(opcionMenuIngresoDatos != 4){
        system("cls");
        cuadroIngresoDatos();
        cout << "1.- Ver datos" << endl;
        cout << "2.- SJF Apropiativo" << endl;
        cout << "3.- SJF NO Apropiativo" << endl;
        cout << "4.- Volver" << endl;
        cout << "Opcion Elegida: "; cin >> opcionMenuIngresoDatos;

        switch(opcionMenuIngresoDatos){
        case 1:
            system("cls");
            imprimirTabla(l);
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "SJF Apropiativo" << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "SJF NO Apropiativo" << endl;
            system("pause");
            break;
        case 4:
            break;
        }
    }
}
void mostrarMenuPrincipal(Lista &l){

    int opcionPrincipal = 0;


    while(opcionPrincipal != 3){
        system("cls");
        cuadroPrincipal();
        cout << "1.- Ingresar datos" << endl;
        cout << "2.- Borrar todos los datos guardados" << endl;
        cout << "3.- Salir" << endl;
        cout << "Opcion Elegida: "; cin >> opcionPrincipal;

        switch(opcionPrincipal){
        case 1:
            mostrarMenuIngresoDatos(l);
            break;
        case 2:
            system("cls");
            cout << "Datos Eliminados" << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "Hasta Pronto!!!" << endl;
            system("pause");
            break;
        }
    }

}
void imprimir(Lista l){
    system("cls");
    Lista q;
    q = l;
    if(q != NULL){
        while(q != NULL)
        {
            cout << "Nombre : " << q->Nombre << endl;
            cout << "Tiempo de Llegada: " << q->tLlegada << endl;
            cout << "Rafaga: " << q->rafaga << endl;
            q = q->link;
        }
    }else{
        cout << "Lista Vacia." << endl;
    }
}



int main()
{
    Lista lista = NULL;
    mostrarMenuPrincipal(lista);




    return 0;
}
