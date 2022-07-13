//
//
#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "menus.h"
#include "archivos.h"
#include "empleado.h"
#include "compra.h"


void modificarUnaCantidad(char archivo[], int posicion){
    Producto temp; //defino un auxiliar donde guardar los datos del fread
    int cantDeProducto=0; //la cantidad que le voy a querer agregar a los que hay

    FILE *archi=fopen(archivo,"r+b");  //se abre el archivo con permisos tanto de escritura como de lectura

    if(archi!=NULL) {
        fseek(archi, sizeof(Producto)*(posicion),SEEK_SET); //se posiciona el cursor en la posicion del registro a modificar
        fread(&temp, sizeof(Producto), 1, archi); //se lee el registro

        printf("\nIngrese la cantidad que va a agregar al stock: ");
        fflush(stdin);
        scanf("%d", &cantDeProducto); //mi nuevo dato donde voy a guardar la cantidad de cosas que quiere sumar

        while (cantDeProducto<1) {
            printf("\nLa cantidad que quiere es invalida, ingrese una nueva: ");
            fflush(stdin);
            scanf("%d", &cantDeProducto);
        }

        temp.cantidad=temp.cantidad+cantDeProducto; //temp va a ser el que vuelva a escribir en el archivo con la cantidad que le indique previamente ya sumada

        fseek(archi,sizeof(Producto)*(-1),SEEK_CUR); //se retrocede una pos el cursor
        fwrite(&temp,sizeof(Producto),1,archi); //se reescibe con la nueva cantidad del producto
    }
    fclose(archi);
}
void modificarCantidadesEmpleado(char archivo[]) {
    int max=5; //la mayor cantidad de productos que hay dentro del archivo

    mostrarTitulos();
    mostrarProductosNumerados(archivo, max);

    int numDeProducto=0; //guardo aca el producto que voy a querer modificarle la cantidad
    char seguir='s';

    while (seguir=='s'){
        printf("\nIngrese el numero del producto que quiere modificar la cantidad o 0 para volver: "); //el 0 va a ser el volver
        fflush(stdin);
        scanf("%d", &numDeProducto);

        while (numDeProducto<0 || numDeProducto>max) {//por si llega a equivocarse el usuario y poner un numero que no esta dentro de los "permitidos"
            printf("\nEse producto no existe, ingrese uno nuevo: ");
            fflush(stdin);
            scanf("%d", &numDeProducto);
        }

        switch(numDeProducto) {

            case 0:
                seguir='n';
                break;

            case 1:
                modificarUnaCantidad(archivo, 0);

                printf("\nQuiere modificar la cantidad de otro producto de esta seccion? S-N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                mostrarTitulos();
                mostrarProductosNumerados(archivo,5);

                break;

            case 2:
                modificarUnaCantidad(archivo, 1);

                printf("\nQuiere modificar la cantidad de otro producto de esta seccion? S-N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                mostrarTitulos();
                mostrarProductosNumerados(archivo,5);

                break;

            case 3:
                modificarUnaCantidad(archivo, 2);

                printf("\nQuiere modificar la cantidad de otro producto de esta seccion? S-N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                mostrarTitulos();
                mostrarProductosNumerados(archivo,5);

                break;

            case 4:
                modificarUnaCantidad(archivo, 3);

                printf("\nQuiere modificar la cantidad de otro producto de esta seccion? S-N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                mostrarTitulos();
                mostrarProductosNumerados(archivo,5);

                break;

            case 5:
                modificarUnaCantidad(archivo, 4);

                printf("\nQuiere modificar la cantidad de otro producto de esta seccion? S-N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                mostrarTitulos();
                mostrarProductosNumerados(archivo,5);

                break;
        }
    }
    system("cls");
}
void modificarUnPrecio(char archivo[], int posicion){
    Producto temp; //defino un auxiliar donde guardar los datos del fread
    int nuevoPrecio=0;
    FILE *archi=fopen(archivo,"r+b");  //se abre el archivo con permisos tanto de escritura como de lectura

    if(archi!=NULL) {
        fseek(archi, sizeof(Producto)*(posicion),SEEK_SET); //se posiciona el cursor en la posicion del registro a modificar
        fread(&temp, sizeof(Producto), 1, archi); //se lee el registro

        printf("\nIngrese el nuevo precio del producto: $");
        fflush(stdin);
        scanf("%d", &nuevoPrecio); //mi nuevo dato
        while (nuevoPrecio<1) {
            printf("\nEl precio que quiere es invalido, ingrese uno nuevo: $");
            fflush(stdin);
            scanf("%d", &nuevoPrecio);
        }

        temp.precio=nuevoPrecio; //temp va a ser el que vuelva a escribir en el archivo

        fseek(archi,sizeof(Producto)*(-1),SEEK_CUR); //se retrocede una pos el cursor
        fwrite(&temp,sizeof(Producto),1,archi); //se reescibe con el nuevo precio
    }
    fclose(archi);
}
void modificarPreciosEmpleado(char archivo[]) {
    int max=5; //la mayor cantidad de productos que hay dentro del archivo
    mostrarTitulos();
    mostrarProductosNumerados(archivo, max);

    int numDeProducto=0; //guardo aca el producto que voy a querer modificar
    char seguir='s';

    while (seguir=='s'){
        printf("\nIngrese el numero del producto que quiere modificar el precio o 0 para volver: "); //el 0 va a ser el volver
        fflush(stdin);
        scanf("%d", &numDeProducto);

        while (numDeProducto<0 || numDeProducto>max) {//por si llega a equivocarse el usuario y poner un numero que no esta dentro de los "permitidos"
            printf("\nEse producto no existe, ingrese uno nuevo: ");
            fflush(stdin);
            scanf("%d", &numDeProducto);
        }

        switch(numDeProducto) {

            case 0: ///volver al menu inicial
                seguir='n';
                break;

            case 1:
                modificarUnPrecio(archivo, 0);

                printf("\nQuiere modificar el precio de otro producto de esta seccion? S-N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                mostrarTitulos();
                mostrarProductosNumerados(archivo,5);
                break;

            case 2:
                modificarUnPrecio(archivo, 1);

                printf("\nQuiere modificar el precio de otro producto de esta seccion? S-N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                mostrarTitulos();
                mostrarProductosNumerados(archivo,5);
                break;

            case 3:
                modificarUnPrecio(archivo, 2);

                printf("\nQuiere modificar el precio de otro producto de esta seccion? S-N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                mostrarTitulos();
                mostrarProductosNumerados(archivo,5);
                break;

            case 4:
                modificarUnPrecio(archivo, 3);

                printf("\nQuiere modificar el precio de otro producto de esta seccion? S-N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                mostrarTitulos();
                mostrarProductosNumerados(archivo,5);
                break;

            case 5:
                modificarUnPrecio(archivo, 4);

                printf("\nQuiere modificar el precio de otro producto de esta seccion? S-N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                mostrarTitulos();
                mostrarProductosNumerados(archivo,5);

                break;
        }
    }
}
void buscarCompraPorID(){
    Compra aux;

    int flag=1;
    int iDTicket=0;
    printf("\nIDTicket de compra que quiere ver: ");
    fflush(stdin);
    scanf("%d", &iDTicket);

    FILE *archi;
    archi=fopen(COMPRA, "rb");
    if (archi!=NULL){
        while (flag==1 && fread(&aux, sizeof(Compra), 1, archi)>0){
            if (aux.iDTicket==iDTicket){
                mostrarCompra(aux);
                flag=0;
            }
        }
        if (flag==1){
            printf("\nEsa compra no existe.\n");
        }
    }
    fclose(archi);
}
