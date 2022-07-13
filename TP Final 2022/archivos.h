//
// Created by Mati on 27/6/2022.
//

#ifndef TPFINALMENU_ARCHIVOS_H
#define TPFINALMENU_ARCHIVOS_H
///NOMBRES DE ARCHIVOS
#define CLIENTES "clientes.bin"
#define EMPLEADOS "empleados.bin"
#define LACTEOS "lacteos.bin"
#define CARNES "carnes.bin"
#define ALMACEN "almacen.bin"
#define PASTAS "pastas.bin"
#define BEBIDAS "bebidas.bin"
#define ALCOHOL "alcohol.bin"
#define COMPRA "compra.bin"
///FUNCIONES ARCHIVOS
void cargarArchivoDeProductos(char archivo[]);//carga los archivos
void leerArchivoDeStock(char archivo[]);//muestra los archivos stock
void leerArchivoDeCompra();//muestra la compra
#endif //TPFINALMENU_ARCHIVOS_H
