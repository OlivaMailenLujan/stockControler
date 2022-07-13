//
// Created by Mati on 27/6/2022.
//

#ifndef TPFINALMENU_PRODUCTO_H
#define TPFINALMENU_PRODUCTO_H

#include "estructuras.h"

Producto cargarProducto();
void mostrarProducto(Producto aux);//muestra producto... modularizado
void mostrarUnProducto(char archivo[], int pos);//muestra un producto especifico
void mostrarProductosNumerados(char archivo[], int max);//muestra los productos enumerados
#endif //TPFINALMENU_PRODUCTO_H
