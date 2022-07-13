//
// Created by Mati on 27/6/2022.
//

#ifndef TPFINALMENU_ESTRUCTURAS_H
#define TPFINALMENU_ESTRUCTURAS_H

///ESTRUCTURAS
typedef struct {
    char nombre[30];
    char marca[30];
    int estado; //0 ->Solido (medido en kilos). 1->Liquido (medido en litros)
    float volumen_peso;
    int precio;
    int cantidad; //cantidad de producto q hay disponibles
    char detalle[100];
}Producto;

typedef struct {
    int iDTicket;
    Producto carrito[100];
    int validos;
    float precioTotal;
} Compra;

typedef struct {
    char dni[10];//documento de identidad
    char nombre[20];
    char contrasena[20];
}Usuario;

#endif //TPFINALMENU_ESTRUCTURAS_H
