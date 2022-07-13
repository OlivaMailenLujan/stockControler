//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include <conio.h>//esta libreria la incluimos para que pueda funcionar correctamente la funcion "gotoxy"
#include <windows.h>
#include "estructuras.h"
#include "menus.h"
#include "usuarios.h"
#include "archivos.h"
#include "empleado.h"
#include "compra.h"

///FUNCIONES MENU
void menu(){
    system("color 1");
    printf("            __________________________________________________________________________________________________________________\n");
    printf("           |                                                                                                                  |\n");
    sleep(1);
    printf("           |   ¦¦¦¦¦¦  ¦¦¦¦¦¦¦ ¦¦¦    ¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦     ¦¦¦    ¦¦¦  ¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦  |\n");
    printf("           |   ¦¦   ¦¦ ¦¦      ¦¦¦¦   ¦¦ ¦¦    ¦¦ ¦¦      ¦¦      ¦¦     ¦¦¦¦  ¦¦¦¦ ¦¦   ¦¦ ¦¦   ¦¦ ¦¦  ¦¦  ¦¦         ¦¦     |\n");
    sleep(1);
    printf("           |   ¦¦ ¦¦   ¦¦¦¦¦¦  ¦¦¦¦   ¦¦ ¦¦    ¦¦ ¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦     ¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦  ¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦     ¦¦     |\n");
    printf("           |   ¦¦   ¦¦ ¦¦      ¦¦  ¦¦ ¦¦ ¦¦    ¦¦ ¦¦      ¦¦      ¦¦     ¦¦  ¦¦  ¦¦ ¦¦   ¦¦ ¦¦   ¦¦ ¦¦  ¦¦  ¦¦         ¦¦     |\n");
    sleep(1);
    printf("           |   ¦¦¦¦¦¦  ¦¦¦¦¦¦¦ ¦¦   ¦¦¦¦  ¦¦¦¦¦¦  ¦¦      ¦¦      ¦¦     ¦¦      ¦¦ ¦¦   ¦¦ ¦¦   ¦¦ ¦¦   ¦¦ ¦¦¦¦¦¦¦    ¦¦     |\n");
    printf("           |                                                                                                                  |\n");
    printf("           |                                                                                                                  |\n");
    printf("           |   *    *   *   *      *   *   *   *   *         *  *        *  *            *  *        *  *     *  *            |\n");
    printf("           |      *    *   *  * *     *   *   *                  *   *  *       *    *   *  * *     *   *   *                 |\n");
    printf("           |      *    *     *      *  * *     *   *   *      *        *  *  * *     *   *   *      *        *                |\n");
    printf("           |           *        *   *               *      *      * *        *        *   *               *      *      * *   |\n");
    printf("           |                          *  *    *     *                                                                         |\n");
    printf("           |      *    *    *  *    *  *         *  *               *     *             *  *    *  *         *  *      *   *  |\n");
    printf("           |      *    *    *   *    *       *    *  *      *           *  *                                                  |\n");
    printf("           |__________________________________________________________________________________________________________________|\n");
    printf("           |                                                                                                                  |\n");
    printf("           |                                                                                                                  |\n");
    printf("           |                                                                                                                  |\n");
    printf("           |                                                                                                                  |\n");
    printf("           |                                                                                                                  |\n");
    printf("           |                                                                                                                  |\n");
    printf("           |                                                                                                                  |\n");
    printf("           |                                                                                                                  |\n");
    printf("           |                                                                                                                  |\n");
    printf("           |------------------------------------------------------------------------------------------------------------------|\n");
    printf("           |                                      | 1- Ingresar como empleado |                                               |\n");
    printf("           |------------------------------------------------------------------------------------------------------------------|\n");
    printf("           |                                      | 2- Ingresar como cliente  |                                               |\n");
    printf("           |------------------------------------------------------------------------------------------------------------------|\n");
    printf("           |                                      |       3- Salir            |                                               |\n");
    printf("           |------------------------------------------------------------------------------------------------------------------|\n");
    printf("           |                                      |     Opcion :              |                                               |\n");
    printf("           |__________________________________________________________________________________________________________________|\n");
}
void mostrarOpcionesEmpleado(){
    int opcion1;
    int flag=0;

    do{

        printf("  _________________________________________\n");
        printf(" |                                         |\n");
        printf(" | 1-Agregar cantidad o precio a stock     |\n");
        printf(" |_________________________________________|\n");
        printf(" |                                         |\n");
        printf(" | 2-Buscar compra por Num de ticket       |\n");
        printf(" |_________________________________________|\n");
        printf(" |                                         |\n");
        printf(" | 3-Mirar todas las compras               |\n");
        printf(" |_________________________________________|\n");
        printf(" |                                         |\n");
        printf(" | 4-Volver al menu                        |\n");
        printf(" |_________________________________________|\n");
        printf(" |                                         |\n");
        printf(" | Opcion :                                |\n");
        printf(" |_________________________________________|\n");
        gotoxy(14,13);scanf("%d",&opcion1);//usamos esta funcion para ubicar un texto en las coordenadas de la consola que se envian por parametro
        system("cls");

        switch(opcion1){

            case 1:
                verTipoProductoEmpleado();
                printf("\n");
                system("cls");
                ImagenDeCarga();//Hace una transicion de carga para que no sea tan brusco
                break;

            case 2:
                buscarCompraPorID();//busca la compra por el ticket generado cuando se finaliza la compra
                printf("\n");
                system("pause");
                system("cls");
                ImagenDeCarga();
                break;

            case 3:
                leerArchivoDeCompra();//muestra las compras realizadas, o sea muestra ticket, productos, etc
                printf("\n");
                system("pause");
                system("cls");
                ImagenDeCarga();
                break;

            case 4:
                flag = 1;
                break;
        }


    }while(flag == 0);
}
void verTipoProductoEmpleado(){
    ImagenDeCarga();
    system("cls");
    int opcion;
    int opcion1;
    system("color 1");
    system("cls");
    // sleep(2);
    while(opcion != 0){
        printf("            _______________________________________________________ \n");
        printf("           |  _              _       _       _                     | \n");
        printf("           | | |__     ___  | |__   (_)   __| |   __ _   ___       | \n");
        printf("    1      | | '_ |   / _ | | '_ |  | |  / _` |  / _` | / __|      | \n");
        printf("           | | |_) | |  __/ | |_) | | | | (_| | | (_| | *__ *      | \n");
        printf("           | |_.__/   *___| |_.__/  |_|  *__,_|  *__,_| |___/      | \n");
        printf("           |_______________________________________________________| \n");
        printf("           |  _                                                    | \n");
        printf("           | | |   __ _    ___   _____   ___    ___    ___         | \n");
        printf("    2      | | |  / _` |  / __| |_   _| / _ |  / _ *  / __|        | \n");
        printf("           | | | | (_| | | (__    | |  |  __/ | (_) | *__ *        | \n");
        printf("           | |_|  *__,_|  *___|   |_|   *___|  *___/  |___/        | \n");
        printf("           |_______________________________________________________| \n");
        printf("           |   ___    __ _   _ __   _ ___     ___   ___            | \n");
        printf("           |  / __|  / _` | | '__| | '__ *   / _ | / __|           | \n");
        printf("    3      | | (__  | (_| | | |    | |  | | |  __/ *__ *           | \n");
        printf("           |  *___|  *__,_| |_|    |_|  |_|  *___| |___/           | \n");
        printf("           |                                                       | \n");
        printf("           |_______________________________________________________| \n");
        printf("           |          _                                            | \n");
        printf("           |   __ _  | |  _ __ ___     __ _    ___    ___   _ __   | \n");
        printf("    4      |  / _` | | | | '_ ` _ *   / _` |  / __|  / _ | | '_ *  | \n");
        printf("           | | (_| | | | | | | | | | | (_| | | (__  |  __/ | | | | | \n");
        printf("           |  *__,_| |_| |_| |_| |_|  *__,_|  *___|  *___| |_| |_| | \n");
        printf("           |_______________________________________________________| \n");
        printf("           |  _ __     __ _   ___   _____    __ _   ___            | \n");
        printf("           | | '_ *   / _` | / __| |_   _|  / _` | / __|           | \n");
        printf("    5      | | |_) | | (_| | *__ *   | |   | (_| | *__ *           | \n");
        printf("           | | .__/   *__,_| |___/   |_|    *__,_| |___/           | \n");
        printf("           | |_|                                                   | \n");
        printf("           |_______________________________________________________| \n");
        printf("           |         _                  _               _          | \n");
        printf("           |   __ _ | |   ___    ___   | |__     ___   | |         | \n");
        printf("    6      |  / _` || |  / __|  / _ *  | '_ *   / _ *  | |         | \n");
        printf("           | | (_| || | | (__  | (_) | | | | | | (_) | | |         | \n");
        printf("           |  *__,_||_|  *___|  *___/  |_| |_|  *___/  |_|         | \n");
        printf("           |_______________________________________________________| \n");
        printf("\n");
        printf("   |Presione 0 para volver                 | \n");
        printf("   |Eliga una opcion segun el numero :     | \n" );
        gotoxy(39,39); scanf("%d",&opcion);
        printf("\n");

        system("cls");
        ImagenDeCarga();

        switch (opcion){

            case 0 :
                break;

            case 1:
                mostrarTitulos();
                mostrarProductosNumerados(BEBIDAS,5);//muestra el archivo de productos q se seleccione, se envia por parametro
                opcion1 = menuCantidadPrecioEmpleado();
                if(opcion1 == 1){
                    modificarCantidadesEmpleado(BEBIDAS);
                }
                else if(opcion1 == 2){
                    modificarPreciosEmpleado(BEBIDAS);
                }
                else{
                    break;
                }
                system("cls");
                break;

            case 2 :
                mostrarTitulos();
                mostrarProductosNumerados(LACTEOS,5);
                opcion1 = menuCantidadPrecioEmpleado();
                if(opcion1 == 1){
                    modificarCantidadesEmpleado(LACTEOS);
                }
                else if(opcion1 == 2){
                    modificarPreciosEmpleado(LACTEOS);
                }
                else{
                    break;
                }
                system("cls");
                break;

            case 3:
                mostrarTitulos();
                mostrarProductosNumerados(CARNES,5);
                opcion1 = menuCantidadPrecioEmpleado();
                if(opcion1 == 1){
                    modificarCantidadesEmpleado(CARNES);
                }
                else if(opcion1 == 2){
                    modificarPreciosEmpleado(CARNES);
                }
                else{
                    break;
                }
                system("cls");
                break;

            case 4 :
                mostrarTitulos();
                mostrarProductosNumerados(ALMACEN,5);
                opcion1 = menuCantidadPrecioEmpleado();
                if(opcion1 == 1){
                    modificarCantidadesEmpleado(ALMACEN);
                }
                else if(opcion1 == 2){
                    modificarPreciosEmpleado(ALMACEN);
                }
                else{
                    break;
                }
                system("cls");
                break;

            case 5 :
                mostrarTitulos();
                mostrarProductosNumerados(PASTAS,5);
                opcion1 = menuCantidadPrecioEmpleado();
                if(opcion1 == 1){
                    modificarCantidadesEmpleado(PASTAS);
                }
                else if(opcion1 == 2){
                    modificarPreciosEmpleado(PASTAS);
                }
                else{
                    break;
                }
                system("cls");
                break;

            case 6 :
                mostrarTitulos();
                mostrarProductosNumerados(ALCOHOL,5);
                opcion1 = menuCantidadPrecioEmpleado();
                if(opcion1 == 1){
                    modificarCantidadesEmpleado(ALCOHOL);
                }
                else if(opcion1 == 2){
                    modificarPreciosEmpleado(ALCOHOL);
                }
                else{
                    break;
                }
                system("cls");
                break;
        }
    }
}
void verTipoProductoCliente(){
    ImagenDeCarga();
    int finCompra;
    float precioTotal;
    int opcion = 1;
    int opcion1 = 0;
    int banderin=0;
    Pila precio;
    inicpila(&precio);
    Producto carrito[100];
    system("color 1");
    int validos = 0;
    while(opcion != 0){

        printf("            _______________________________________________________ \n");
        printf("           |  _              _       _       _                     | \n");
        printf("           | | |__     ___  | |__   (_)   __| |   __ _   ___       | \n");
        printf("    1      | | '_ |   / _ | | '_ |  | |  / _` |  / _` | / __|      | \n");
        printf("           | | |_) | |  __/ | |_) | | | | (_| | | (_| | *__ *      | \n");
        printf("           | |_.__/   *___| |_.__/  |_|  *__,_|  *__,_| |___/      | \n");
        printf("           |_______________________________________________________| \n");
        printf("           |  _                                                    | \n");
        printf("           | | |   __ _    ___   _____   ___    ___    ___         | \n");
        printf("    2      | | |  / _` |  / __| |_   _| / _ |  / _ *  / __|        | \n");
        printf("           | | | | (_| | | (__    | |  |  __/ | (_) | *__ *        | \n");
        printf("           | |_|  *__,_|  *___|   |_|   *___|  *___/  |___/        | \n");
        printf("           |_______________________________________________________| \n");
        printf("           |   ___    __ _   _ __   _ ___     ___   ___            | \n");
        printf("           |  / __|  / _` | | '__| | '__ *   / _ | / __|           | \n");
        printf("    3      | | (__  | (_| | | |    | |  | | |  __/ *__ *           | \n");
        printf("           |  *___|  *__,_| |_|    |_|  |_|  *___| |___/           | \n");
        printf("           |                                                       | \n");
        printf("           |_______________________________________________________| \n");
        printf("           |          _                                            | \n");
        printf("           |   __ _  | |  _ __ ___     __ _    ___    ___   _ __   | \n");
        printf("    4      |  / _` | | | | '_ ` _ *   / _` |  / __|  / _ | | '_ *  | \n");
        printf("           | | (_| | | | | | | | | | | (_| | | (__  |  __/ | | | | | \n");
        printf("           |  *__,_| |_| |_| |_| |_|  *__,_|  *___|  *___| |_| |_| | \n");
        printf("           |_______________________________________________________| \n");
        printf("           |  _ __     __ _   ___   _____    __ _   ___            | \n");
        printf("           | | '_ *   / _` | / __| |_   _|  / _` | / __|           | \n");
        printf("    5      | | |_) | | (_| | *__ *   | |   | (_| | *__ *           | \n");
        printf("           | | .__/   *__,_| |___/   |_|    *__,_| |___/           | \n");
        printf("           | |_|                                                   | \n");
        printf("           |_______________________________________________________| \n");
        printf("           |         _                  _               _          | \n");
        printf("           |   __ _ | |   ___    ___   | |__     ___   | |         | \n");
        printf("    6      |  / _` || |  / __|  / _ *  | '_ *   / _ *  | |         | \n");
        printf("           | | (_| || | | (__  | (_) | | | | | | (_) | | |         | \n");
        printf("           |  *__,_||_|  *___|  *___/  |_| |_|  *___/  |_|         | \n");
        printf("           |_______________________________________________________| \n");
        printf("\n");
        printf("   |Presione 0 para volver                 | \n");
        printf("   |Eliga una opcion segun el numero :     | \n" );
        printf("   |Presione el 9 para finalizar la compra | \n");
        gotoxy(39,39); scanf("%d",&opcion);

        system("cls");
        ImagenDeCarga();

        switch (opcion){

            case 0 :
                if(validos>0){
                    banderin = eliminarCarrito(carrito,&precio,&validos);
                    system("cls");
                    if(banderin == 1){
                        opcion = 1;
                        break;
                    }
                    else{
                        printf("Carrito eliminado con exito.\n");
                        opcion = 0;
                    }
                    system("pause");
                    system("cls");
                }
                break;

            case 1:
                system("cls");
                mostrarTitulos();
                mostrarProductosNumerados(BEBIDAS,5);
                opcion1 = menuAgregarAlCarrito();
                if(opcion1 == 1){
                    comprar(carrito,&precio,&validos,BEBIDAS);
                }
                system("cls");
                break;

            case 2 :
                system("cls");
                mostrarTitulos();
                mostrarProductosNumerados(LACTEOS,5);
                opcion1 = menuAgregarAlCarrito();
                if(opcion1 == 1){
                    comprar(carrito,&precio,&validos,LACTEOS);
                }

                system("cls");
                break;

            case 3:
                mostrarTitulos();
                mostrarProductosNumerados(CARNES,5);
                opcion1 = menuAgregarAlCarrito();
                if(opcion1 == 1){
                    comprar(carrito,&precio,&validos,CARNES);
                }

                system("cls");
                break;

            case 4 :
                mostrarTitulos();
                mostrarProductosNumerados(ALMACEN,5);
                opcion1 = menuAgregarAlCarrito();
                if(opcion1 == 1){
                    comprar(carrito,&precio,&validos,ALMACEN);
                }

                system("cls");
                break;

            case 5 :
                mostrarTitulos();
                mostrarProductosNumerados(PASTAS,5);
                opcion1 = menuAgregarAlCarrito();
                if(opcion1 == 1){
                    comprar(carrito,&precio,&validos,PASTAS);
                }

                system("cls");
                break;

            case 6 :
                mostrarTitulos();
                mostrarProductosNumerados(ALCOHOL,5);
                opcion1 = menuAgregarAlCarrito();
                if(opcion1 == 1){
                    comprar(carrito,&precio,&validos,ALCOHOL);
                }
                system("cls");
                break;

            case 9 :
                if (validos>0){
                    mostrarTitulos();
                    mostrarCarrito(carrito,validos);
                    printf("\n");
                    eliminarProductoDelCarrito(carrito,&precio,&validos);
                    precioTotal = descuentoCompra(precio);
                    printf("\n");
                    system("pause");
                    system("cls");
                    finCompra =finalizarCompra(carrito,validos,precioTotal);
                    if(finCompra == 0){
                        opcion = 1;
                    } else if (finCompra == 1){
                        opcion = 0;
                    }
                } else {
                    printf("Su carrito esta vacio.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
        }
    }
}
int menuCantidadPrecioEmpleado(){

    int flag = 0 ;
    int opcion;
    printf("        |                                                                                                                    |\n");
    printf("        |--------------------------------------------------------------------------------------------------------------------|\n");
    printf("        |                                        |1- Agregar cantidad  |                                                     |\n");
    printf("        |--------------------------------------------------------------------------------------------------------------------|\n");
    printf("        |                                        |2- Cambiar precio    |                                                     |\n");
    printf("        |--------------------------------------------------------------------------------------------------------------------|\n");
    printf("        |                                        |3- Volver            |                                                     |\n");
    printf("        |--------------------------------------------------------------------------------------------------------------------|\n");
    printf("        |                                        | Opcion :            |                                                     |\n");
    printf("        |____________________________________________________________________________________________________________________|\n");
    printf("\n");
    gotoxy(23,60);scanf("%d",&opcion);
    system("cls");

    switch(opcion){

        case 1 :
            flag = 1;
            break;

        case 2 :
            flag = 2;
            break;

        case 3:
            break;
    }
    return flag;
}
int menuAgregarAlCarrito(){

    int flag = 0 ;
    int opcion;
    printf("        |                                                                                                                    |\n");
    printf("        |--------------------------------------------------------------------------------------------------------------------|\n");
    printf("        |                                        |1- Agregar al carrito|                                                     |\n");
    printf("        |--------------------------------------------------------------------------------------------------------------------|\n");
    printf("        |                                        |2- Volver            |                                                     |\n");
    printf("        |--------------------------------------------------------------------------------------------------------------------|\n");
    printf("        |                                        | Opcion :            |                                                     |\n");
    printf("        |____________________________________________________________________________________________________________________|\n");
    printf("\n");
    gotoxy(21,60);scanf("%d",&opcion);
    system("cls");

    switch(opcion){

        case 1 :
            flag = 1;
            break;

        case 2 :
            break;
    }
    return flag;
}
void mostrarTitulos(){

    printf("         ____________________________________________________________________________________________________________________\n");
    printf("        |                    |                    |                 |                  |                |                    |\n");
    printf("        |        MARCA       |       TIPO         |  PESO/VOLUMEN   |      PRECIO      |   CANTIDAD     |   DETALLE          | \n ");
    printf("       |                    |                    |  (KG)   (LT)    |                  |                |                    |  \n");
    printf("        |____________________|____________________|_________________|__________________|________________|____________________|  \n");

}
void gotoxy(int y, int x){ //Establecer posicion del nuevo cursor

    //Obtener handle de la consola
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Establecer posicion del nuevo cursor
    COORD pos;
    pos.X = x;
    pos.Y = y;

    //colocar cursor en el nuevo sitio
    SetConsoleCursorPosition(hConsole,pos);

}
void retardo(){
    int i = 0;
    int k=0;
    for(i; i<20000; i++)
    {
        for(k; k<10000; k++)
        {
        }
    }
}
void ImagenDeCarga(){
    int i = 0;
    while(i<5)
    {
        printf("Cargando.\n");
        retardo();
        system("cls");
        printf("Cargando..\n");
        retardo();
        system("cls");
        printf("Cargando...\n");
        retardo();
        system("cls");
        i++;
    }

}
void cerrarPrograma(){

    printf("\n    ___                                              _   ");
    printf("\n   / __*   ___    _ __   _ __    __ _    __ __     _| |    ___  ");
    printf("\n  / /     / _ *  |  '_| |  '_|  / _` |  | '_ *   / _` |   / _ *  ");
    printf("\n / /__   |  __/  | |    | |    | (_| |  | | | | | (_| |  | (_) | ");
    printf("\n *____/   *___|  |_|    |_|     *_,_ |  |_| |_|  *__,_|   *___/  ");

}
