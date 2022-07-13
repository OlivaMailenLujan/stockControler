#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menus.h"
#include "usuarios.h"
#include "archivos.h"



int main()
{
    srand(time(NULL));

    int opcion;
    int flag= 1;
    int opcion1;

    do{
        system("cls");
        menu();
        gotoxy(33,65);scanf("%d",&opcion);
        ImagenDeCarga();
        system("cls");

        switch(opcion){

        case 1 :
            flag = iniciarSesionUsuario(EMPLEADOS);
            if (flag == 1){
                break;
            }
            system("cls");
            mostrarOpcionesEmpleado();
        break;

        case 2 :
            flag = iniciarSesionUsuario(CLIENTES);
            if (flag == 1){
                break;
            }
            system("cls");
            verTipoProductoCliente();
        break;

        case 3 :
            system("cls");
            cerrarPrograma();
            printf("\n");
            printf("\n");
            system("pause");
        break;
        }
        system("cls");

    } while(opcion != 3);

    return 0;
}


