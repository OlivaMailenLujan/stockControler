//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "menus.h"
#include "archivos.h"
#include "compra.h"


int agregarProductoAlCarrito(Producto compra[], Pila *precios, int validos, int posicion, char archivo[]){
    Producto temp;
    int flag=0;
    int cantDeProducto=0;

    FILE *archi;
    archi=fopen(archivo,"r+b");
    if(archi!=NULL){
        fseek(archi, sizeof(Producto)*(posicion),SEEK_SET); //se posiciona el cursor en la posicion del registro
        fread(&compra[validos], sizeof(Producto), 1, archi); //se agrega al carrito
        if (compra[validos].cantidad==0){
            flag=1;
        } else {
            printf("\nIngrese la cantidad que quiera: "); //la cantidad de unidades que quiere de ese producto
            fflush(stdin);
            scanf("%d", &cantDeProducto);
            while (cantDeProducto<1 || cantDeProducto>compra[validos].cantidad) {
                printf("\nLa cantidad que quiere es invalida, ingrese una nueva: ");
                fflush(stdin);
                scanf("%d", &cantDeProducto);
            }
            temp=compra[validos]; //temp va a ser el que vuelva a escribir en el archivo //compra es el arreglo del carrito
            apilar(precios, compra[validos].precio*cantDeProducto); //se guardan en una pila los precios
            compra[validos].cantidad=cantDeProducto; //cantidad que tiene en el carrito
            temp.cantidad-=cantDeProducto; //cantidad que queda en stock
            fseek(archi,sizeof(Producto)*(-1),SEEK_CUR); //se retrocede una posicion el cursor
            fwrite(&temp,sizeof(Producto),1,archi); //se reescibe con la nueva cantidad disponible
        }
    }
    fclose(archi);
    return flag;
}
void comprar(Producto compra[], Pila *precios, int *validos, char archivo[]){ //agrega los productos que elige a un arreglo y los precios a una pila
    int max=5;
    mostrarTitulos();
    mostrarProductosNumerados(archivo, max);

    int flag;
    char seguir='s';
    int numDeProducto=0;

    while (seguir=='s') {
        printf("\nIngrese el numero del producto que quiere agregar al carrito o 0 para volver: "); //el 0 va a ser el volver
        fflush(stdin);
        scanf("%d", &numDeProducto);
        while (numDeProducto<0 || numDeProducto>max) {
            printf("\nEse producto no existe, ingrese uno nuevo: ");
            fflush(stdin);
            scanf("%d", &numDeProducto);
        }

        switch(numDeProducto){
            case 0:
                seguir = 'n';
                system("cls");
                break;
            case 1:
                flag = agregarProductoAlCarrito(compra, precios, *validos, 0, archivo);
                if (flag==1){
                    printf("\nQuiere agregar al carrito otro producto de esta seccion? S-N\n");
                    fflush(stdin);
                    scanf("%c", &seguir);
                    system("cls");
                    mostrarTitulos();
                    mostrarProductosNumerados(archivo,5);
                } else {
                    (*validos)++;
                    printf("\nQuiere agregar al carrito otro producto de esta seccion? S-N\n");
                    fflush(stdin);
                    scanf("%c", &seguir);
                    system("cls");
                    mostrarTitulos();
                    mostrarProductosNumerados(archivo,5);
                }
                break;
            case 2:
                flag = agregarProductoAlCarrito(compra, precios, *validos, 1, archivo);
                if (flag==1){
                    printf("\nQuiere agregar al carrito otro producto de esta seccion? S-N\n");
                    fflush(stdin);
                    scanf("%c", &seguir);
                    system("cls");
                    mostrarTitulos();
                    mostrarProductosNumerados(archivo,5);
                } else {
                    (*validos)++;
                    printf("\nQuiere agregar al carrito otro producto de esta seccion? S-N\n");
                    fflush(stdin);
                    scanf("%c", &seguir);
                    system("cls");
                    mostrarTitulos();
                    mostrarProductosNumerados(archivo,5);
                }
                break;
            case 3:
                flag = agregarProductoAlCarrito(compra, precios, *validos, 2, archivo);
                if (flag==1){
                    printf("\nQuiere agregar al carrito otro producto de esta seccion? S-N\n");
                    fflush(stdin);
                    scanf("%c", &seguir);
                    system("cls");
                    mostrarTitulos();
                    mostrarProductosNumerados(archivo,5);
                } else {
                    (*validos)++;
                    printf("\nQuiere agregar al carrito otro producto de esta seccion? S-N\n");
                    fflush(stdin);
                    scanf("%c", &seguir);
                    system("cls");
                    mostrarTitulos();
                    mostrarProductosNumerados(archivo,5);
                }
                break;
            case 4:
                flag = agregarProductoAlCarrito(compra, precios, *validos, 3, archivo);
                if (flag==1){
                    printf("\nQuiere agregar al carrito otro producto de esta seccion? S-N\n");
                    fflush(stdin);
                    scanf("%c", &seguir);
                    system("cls");
                    mostrarTitulos();
                    mostrarProductosNumerados(archivo,5);
                } else {
                    (*validos)++;
                    printf("\nQuiere agregar al carrito otro producto de esta seccion? S-N\n");
                    fflush(stdin);
                    scanf("%c", &seguir);
                    system("cls");
                    mostrarTitulos();
                    mostrarProductosNumerados(archivo,5);
                }
                break;
            case 5:
                flag = agregarProductoAlCarrito(compra, precios, *validos, 4, archivo);
                if (flag==1){
                    printf("\nQuiere agregar al carrito otro producto de esta seccion? S-N\n");
                    fflush(stdin);
                    scanf("%c", &seguir);
                    system("cls");
                    mostrarTitulos();
                    mostrarProductosNumerados(archivo,5);
                } else {
                    (*validos)++;
                    printf("\nQuiere agregar al carrito otro producto de esta seccion? S-N\n");
                    fflush(stdin);
                    scanf("%c", &seguir);
                    system("cls");
                    mostrarTitulos();
                    mostrarProductosNumerados(archivo,5);
                }
                break;
        }
    }
}
void mostrarCarrito(Producto compra[], int validos){
    int i=0;
    for (i; i<validos; i++){
        printf("%d:", i+1);
        mostrarProducto(compra[i]);
    }
}
void devolverAStock (char archivo[], char nombreProducto[], int cantidad){ //si el producto esta en el archivo le devuelve las cantidades que se habian sacado
    Producto aux;
    int flag=1;
    FILE *archi;
    archi=fopen(archivo, "r+b");
    if (archi!=NULL){
        while (flag==1 && fread(&aux, sizeof(Producto), 1, archi)>0){
            if (strcmpi(aux.nombre, nombreProducto)==0){ //si se encuentra ese producto
                aux.cantidad+=cantidad; //lo que se habia sacado se devuelve
                fseek(archi,sizeof(Producto)*(-1),SEEK_CUR); //se retrocede una posicion el cursor
                fwrite(&aux,sizeof(Producto),1,archi); //se reescibe con la nueva cantidad disponible
                flag=0;
            }
        }
    }
    fclose(archi);
}
void eliminarProductoDelCarrito(Producto compra[], Pila *precios, int *validos){
    int prodARetirar=0;
    int cantARetirar=0;
    char seguir='s';
    printf("\nQuiere eliminar algun producto del carrito? S-N\n");
    fflush(stdin);
    scanf("%c", &seguir);
    while (seguir=='s'){
        printf("\nNumero del producto que quiere retirar del carrito: ");
        fflush(stdin);
        scanf("%d", &prodARetirar);
        while (prodARetirar<1 || prodARetirar>*validos){
            printf("\nEl numero del producto es incorrecto, ingreselo nuevamente: ");
            fflush(stdin);
            scanf("%d", &prodARetirar);
        }
        printf("\nCantidad del producto que quiere retirar: ");
        fflush(stdin);
        scanf("%d", &cantARetirar);
        while (cantARetirar<1 || cantARetirar>compra[prodARetirar-1].cantidad){
            printf("\nLa cantidad es incorrecta, ingresela nuevamente: ");
            fflush(stdin);
            scanf("%d", &cantARetirar);
        }
        devolverAStock (LACTEOS, compra[prodARetirar-1].nombre, cantARetirar);
        devolverAStock (CARNES, compra[prodARetirar-1].nombre, cantARetirar);
        devolverAStock (ALMACEN, compra[prodARetirar-1].nombre, cantARetirar);
        devolverAStock (PASTAS, compra[prodARetirar-1].nombre, cantARetirar);
        devolverAStock (BEBIDAS, compra[prodARetirar-1].nombre, cantARetirar);
        devolverAStock (ALCOHOL, compra[prodARetirar-1].nombre, cantARetirar);
        apilar(precios,(compra[prodARetirar-1].precio*cantARetirar)*-1);
        compra[prodARetirar-1].cantidad-=cantARetirar;
        if(compra[prodARetirar-1].cantidad==0){
            int i=prodARetirar-1;
            for(i;i<*validos; i++){
                compra[i]=compra[i+1];
            }
            (*validos)--;
        }
        system("cls");
        ImagenDeCarga();
        mostrarTitulos();
        mostrarCarrito(compra, *validos);
        printf("\nQuiere eliminar otro producto del carrito? S-N\n");
        fflush(stdin);
        scanf("%c", &seguir);
    }
}
int precioTotalCarrito(Pila precios) {//funcion int xq los precios son enteros
    int tope=0;
    int total=0; //inicio la cuenta en cero

    while (!pilavacia(&precios))
    {
        tope=desapilar(&precios); //guardo el ultimo elemento de la pila
        total=total+tope; //lo sumo a lo que ya tenia
    }
    return total; //retorno el total
}
float descuentoCompra(Pila precios) {
    int total=precioTotalCarrito(precios);
    float compraConDesc=0;

    if (total>=5000) {
        printf("\nPrecio: $%d",total);
        compraConDesc= total-(0.20*total);
        printf("\nTiene un descuento del 20%%.");
        printf("\nPrecio total a abonar: $%.2f\n",compraConDesc);
    } else if (total<5000 && total>=3000) {
        printf("\nPrecio: $%d",total);
        compraConDesc = total-(0.15*total);
        printf("\nTiene un descuento del 15%%.");
        printf("\nPrecio total a abonar: $%.2f\n",compraConDesc);
    } else {
        printf("\nPrecio: $%d",total);
        compraConDesc = total;
        printf("\nNo tiene ningun descuento.");
        printf("\nPrecio total a abonar: $%.2f\n",compraConDesc);
    }
    return compraConDesc;
}
int generarIDTicket(){
    int numero=0;
    numero = (rand() % 30000 + 10000);
    return numero;
}
int existeTicketEnArchivo(int iDTicket){
    int flag=0;
    Compra aux;
    FILE *archi;
    archi=fopen(COMPRA, "rb");
    if (archi!=NULL){
        while (fread(&aux, sizeof(Compra), 1, archi)>0){
            if (aux.iDTicket==iDTicket){
                flag=1;
            }
        }
    }
    fclose(archi);
    return flag;
}
int finalizarCompra(Producto compra[], int validos, float precio){
    Compra aux;
    int flag2 = 1;
    int flag=1;
    int i=0;
    if (validos>0){
        while(flag==1){
            aux.iDTicket=generarIDTicket();
            flag=existeTicketEnArchivo(aux.iDTicket);
        }
        for (i; i<validos; i++){
            aux.carrito[i]=compra[i];
        }
        aux.validos=validos;
        aux.precioTotal=precio;
        mostrarCompra(aux);
        printf("\nCON SU NUMERO DE TICKET DIRIJASE A LA SUCURSAL A RETIRAR EL PEDIDO.\n");

        FILE *archi;
        archi=fopen(COMPRA, "ab");
        if (archi!=NULL){
            fwrite(&aux, sizeof(Compra), 1, archi);
        }
        fclose(archi);
    } else {
        printf("\nSu carrito esta vacio.");
        flag2 = 0;
    }
    return flag2;
}
void mostrarCompra(Compra aux){
    printf("\nCOMPRA:");
    printf("\n------------------------------------------------");
    printf("\nIDTICKET: %d", aux.iDTicket);
    printf("\n------------------------------------------------");
    printf("\nCARRITO: \n");
    mostrarTitulos();
    mostrarCarrito(aux.carrito, aux.validos);
    printf("\n------------------------------------------------");
    printf("\nPRECIO TOTAL: $%.2f", aux.precioTotal);
    printf("\n------------------------------------------------\n");
}
int eliminarCarrito(Producto compra[], Pila *precios, int *validos){
    char seguir;
    int flag=0;
    int i=0;
    printf("-Quiere eliminar su compra? S/N\n");
    fflush(stdin);
    scanf("%c", &seguir);

    if (seguir=='n'){
        flag=1;
    } else {
        for (i; i<*validos;i++){
            devolverAStock (LACTEOS, compra[i].nombre, compra[i].cantidad);
            devolverAStock (CARNES, compra[i].nombre, compra[i].cantidad);
            devolverAStock (ALMACEN, compra[i].nombre, compra[i].cantidad);
            devolverAStock (PASTAS, compra[i].nombre, compra[i].cantidad);
            devolverAStock (BEBIDAS, compra[i].nombre, compra[i].cantidad);
            devolverAStock (ALCOHOL, compra[i].nombre, compra[i].cantidad);
            apilar(precios,((compra[i].precio)*(compra[i].cantidad))*-1);
            compra[i]=compra[i+1];
        }
        (*validos)=0;
    }
    return flag;
}
