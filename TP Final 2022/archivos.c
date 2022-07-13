//
//
#include <stdio.h>
#include "estructuras.h"
#include "menus.h"
#include "archivos.h"
#include "empleado.h"
#include "compra.h"


///FUNCIONES ARCHIVOS
void cargarArchivoDeProductos(char archivo[]){
    Producto aux;
    char seguir='s';
    int i=0;
    int maximo=5;
    FILE *archi;
    archi=fopen(archivo, "ab");
    if (archi!=NULL){
        while (seguir=='s' && i<maximo){
            aux=cargarProducto();
            fwrite(&aux, sizeof(Producto), 1, archi);
            i++;
            printf("Desea seguir? s-n\n");
            fflush(stdin);
            scanf("%c", &seguir);
        }
    }
    fclose(archi);
}
void leerArchivoDeStock(char archivo[]){
    int opcion;
    Producto aux;
    FILE *archi;
    archi=fopen(archivo, "rb");
    if (archi!=NULL){
        mostrarTitulos();
        while(fread(&aux, sizeof(Producto), 1, archi)>0){
            if (aux.cantidad!=0){ //para que no muestre articulos que no hay
                mostrarProducto(aux);

            }
        }
        int flag = menuCantidadPrecioEmpleado();
        scanf("%d",&opcion);
        switch(opcion)
        {

            case 1 :
                modificarCantidadesEmpleado(archivo);
                break;

            case 2:
                break;
        }
    } else {
        printf("El archivo no existe.\n");
    }

    fclose(archi);
}
void leerArchivoDeCompra(){
    Compra aux;
    FILE *archi;
    archi=fopen(COMPRA, "rb");
    if (archi!=NULL){
        while(fread(&aux, sizeof(Compra), 1, archi)>0){
            mostrarCompra(aux);
        }
    } else {
        printf("El archivo no existe.\n");
    }
    fclose(archi);
}
