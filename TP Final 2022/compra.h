//
// Created by Mati on 27/6/2022.
//

#ifndef TPFINALMENU_COMPRA_H
#define TPFINALMENU_COMPRA_H

#include "producto.h"
#include "stdio.h"
#include "pila.h"

int agregarProductoAlCarrito(Producto compra[], Pila *precios, int validos, int posicion, char archivo[]);
void comprar(Producto compra[], Pila *precios, int *validos, char archivo[]);//en esta funcion se pide la cantidad del producto que queres y crea un arreglo con el mismo dato de producto solo que con la cantidad modificada que es la que escogio el usuario
void mostrarCarrito(Producto compra[], int validos);
void devolverAStock (char archivo[], char nombreProducto[], int cantidad);//devuelve la cantidad que eligio el usuario para q se pueda editar en el archivo
void eliminarProductoDelCarrito(Producto compra[], Pila *precios, int *validos);//elimina un producto del carrito y se llama al archivo para volverle a sumar la cantidad que el usuario eligio pq ya se habian restado cuando el usuario escogio la cantidad de ese producto
int precioTotalCarrito(Pila precios);
float descuentoCompra(Pila precios);//se envia por parametro el precio y se analiza, si es mayor a x precio entonces hay un descuento
int generarIDTicket();
int existeTicketEnArchivo(int iDTicket);//recorre el archivo, si encuentra el ticket retorna 1
int finalizarCompra(Producto compra[], int validos, float precio);//guarda en el archivo de compras la compra realizada y la muestra
void mostrarCompra(Compra aux);
int eliminarCarrito(Producto compra[], Pila *precios, int *validos);//en esta funcion si el cliente decide volver atras en mitad de una compra se le pregunta si desea eliminar su compra

#endif //TPFINALMENU_COMPRA_H
