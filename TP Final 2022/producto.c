//
//
#include <stdio.h>
#include "estructuras.h"
#include "compra.h"


///FUNCIONES PRODUCTOS
Producto cargarProducto(){
    Producto aux; //Este es el producto q voy a retornar
    printf("\n--------------------PRODUCTO--------------------\n");
    printf("Nombre: ");
    fflush(stdin);
    gets(aux.nombre);
    printf("\nMarca: ");
    fflush(stdin);
    gets(aux.marca);
    printf("\nSi el estado del producto es solido seleccione 0, si es liquido 1");
    do{
        printf("\nEstado: ");
        fflush(stdin);
        scanf("%d", &aux.estado);
        if((aux.estado < 0) || (aux.estado > 1)){
            printf("\nElija un valor valido, 1 o 0:\n");
        }
    }while((aux.estado < 0) || (aux.estado > 1));//esta es una verificacion, si el numero cargado es distinto de 1 o 0, vuelve a ejecutar las lineas anteriores

    printf("\nSi la cantidad es menor a 1, indicar el con un numero con '0.x'\nsi utiliza la ',' no tomara el numero correctamente.\n");
    //aclaro usar el "." y no la "," porque C usa el "." para decir q a partir de ahi son numeros decimales

    if(aux.estado == 1){

        do{
            printf("\nVolumen(en litros):");
            fflush(stdin);
            scanf("%f", &aux.volumen_peso);
            if(aux.volumen_peso <= 0){
                printf("\nElija un numero valido(mayor a 0):");
            }
        }while(aux.volumen_peso <= 0);//otra verificacion, el volumen tiene q ser mayor a 0
    }
    else{

        do {
            printf("\nPeso(en kilos): ");
            fflush(stdin);
            scanf("%f", &aux.volumen_peso);
            if(aux.volumen_peso <= 0){
                printf("\nElija un numero valido(mayor a 0):");
            }
        }while(aux.volumen_peso <= 0);//otra verificacion, el peso tiene q ser mayor a 0
    }

    do{
        printf("\nPrecio: $");
        fflush(stdin);
        scanf("%d", &aux.precio);
        if(aux.precio <= 0){
            printf("\nPor favor ingrese un precio valido(mayor a 0):");//otra verificacion, el precio tiene q ser mayor a 0
        }
    }while(aux.precio <= 0);

    do{
        printf("\nCantidad: ");
        fflush(stdin);
        scanf("%d", &aux.cantidad);
        if(aux.cantidad < 1){
            printf("\nPor favor ingrese una cantidad valida(1 o mas):");//otra verificacion, la cantidad tiene q ser 1 o mas
        }
    }while(aux.cantidad < 1);
    printf("\nDetalle(opcional): ");
    fflush(stdin);
    gets(aux.detalle);
    printf("------------------------------------------------\n");

    return aux;//retorno el producto, su cantidad esta almacenada en el atributo "p.cantidad"
}
void mostrarProducto(Producto aux){
    // printf("\n------------------------------------------------");

    printf("      |%s|%s|   %.2f          |    $%d          |       %d        |%s|\n",aux.marca,aux.nombre,aux.volumen_peso,aux.precio,aux.cantidad,aux.detalle);
    printf("        |____________________|____________________|_________________|__________________|________________|____________________|\n");

    // printf("\n------------------------------------------------\n");

}
void mostrarUnProducto(char archivo[], int pos){
    Producto aux;
    FILE *archi;
    archi=fopen(archivo,"rb");
    if(archi!=NULL){
        fseek(archi, sizeof(Producto)*(pos),SEEK_SET);
        if(fread(&aux, sizeof(Producto), 1, archi)>0){

            mostrarProducto(aux);
        }
    }

    fclose(archi);
}
void mostrarProductosNumerados(char archivo[], int max){
    int i=0;
    for (i; i<max; i++){
        printf("%d:", i+1);
        mostrarUnProducto(archivo, i);
    }
}
