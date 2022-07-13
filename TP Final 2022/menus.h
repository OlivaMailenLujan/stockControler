//
// Created by Mati on 27/6/2022.
//

#ifndef TPFINALMENU_MENUS_H
#define TPFINALMENU_MENUS_H
//MENU
void menu();//es lo primero que vemos cuando ejecutamos el programa
void mostrarOpcionesEmpleado();//son las opciones del usuario cuando entra como empleado
void verTipoProductoEmpleado();//son las opciones que le aparecen al empleado, son de edicion
void verTipoProductoCliente();//son las opciones que le aparecen al cliente, en sus casos se ejecutan funciones de compra y no de edicion
int menuCantidadPrecioEmpleado();
int menuAgregarAlCarrito();
void mostrarTitulos();//muestra los atributos de la estructura producto, la marca, si es solido o no, etc
void gotoxy(int y, int x);//esta funcion la utilizamos para ubicar texto en unas coordenadas especificas q nosotros querramos, esas coordenadas son de la consola y se envian por parametro
void retardo();//retarda el tiempo de carga
void ImagenDeCarga();//printea un texto para que de la sensacion que esta cargando los datos a mostrar
void cerrarPrograma();//printea un texto que indica que el programa se esta cerrando, da la sensacion de que el programa esta por finalizar
#endif //TPFINALMENU_MENUS_H
