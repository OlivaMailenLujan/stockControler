//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "usuarios.h"
#include "ctype.h"//esta libreria se agrego para la funcion "esUnNumero" lo que hace es verificar que en un arreglo char haya solamente numeros, de ser asi retorna 1, sino 0



Usuario cargarUnUsuario() {//para cargar un solo usuario
    Usuario aux;

    printf("\nIngrese Nombre y Apellido: \n");
    fflush(stdin);
    gets(aux.nombre);

    printf("\nIndique el DNI: \n");
    fflush(stdin);
    gets(aux.dni);

    printf("\nEstablezca una contrasenia: \n");
    fflush(stdin);
    gets(aux.contrasena);

    return aux;
}
void guardarUsuario(Usuario temp, char archivo[]) {
    FILE * archi = fopen(archivo, "ab"); //lo abro en modo ab para que no me pise la info anterior y me agregue en el final los datos de la persona nueva cargada

    if (archi!=NULL)
    {
        fwrite(&temp,sizeof(Usuario),1,archi);
        printf("\nUsuario creado exitosamente.\n");
    }
    else
    {
        printf("\nNo fue posible abrir el archivo.\n");
    }
    fclose(archi);

}
int encontrarUsuario(char dniIngreso[10], char archivo[]) { //si se pudo encontrar la persona, devuelve 1. En caso de error, 0.
    int flag = 0;
    Usuario temp;
    FILE * archi = fopen(archivo, "rb"); //abro en rb xq solo quiero buscar si esta o no

    if(archi!=NULL)
    {
        while((fread(&temp,sizeof(Usuario),1,archi)>0) && (flag == 0))
        {
            if(strcmpi(temp.dni,dniIngreso)==0)
            {
                flag = 1;
            }
        }
    }
    fclose(archi);

    return flag;
}
int ingresarNombreContrasena(char nombreIngreso[20], char contraIngreso[20], char archivo[]) {//si se pudo encontrar la persona, devuelve 1. En caso de error, 0.
    int flag = 0;
    Usuario temp;
    FILE * archi = fopen(archivo, "rb");

    if(archi!=NULL)
    {

        while((fread(&temp,sizeof(Usuario),1,archi)>0) && (flag == 0))
        {

            if(strcmpi(temp.nombre,nombreIngreso)==0 && strcmpi(temp.contrasena,contraIngreso)==0) //si el usuario y la contraseña estan bien

            {

                flag = 1;
            }
        }
    }
    fclose(archi);
    return flag;
}
int iniciarSesionUsuario(char archivo[]) {
    char opcion;
    char dniIngresado[10];
    char nombreYapellido[20];
    char contrasena[20];
    Usuario aux;
    int flag = 0;

    do{
        printf("Ingrese su DNI por favor: \n");
        fflush(stdin);
        gets(dniIngresado);
        if((esUnNumero(dniIngresado)) == 0){
            printf("ERROR, ingrese solamente numeros\n");
        }

    }while((esUnNumero(dniIngresado)) == 0);


    if ((encontrarUsuario(dniIngresado, archivo))==1)
    {
        printf("\nUsuario encontrado.\n");

        printf("\nIngresar Usuario:\n"); //seria el nombre y el apellido
        fflush(stdin);
        gets(nombreYapellido);

        printf("\nIngresar Contrasenia:\n");
        fflush(stdin);
        gets(contrasena);

        int dato=ingresarNombreContrasena(nombreYapellido,contrasena,archivo);

        if (dato==1)
        {
            printf("\nUsuario encontrado exitosamente, puede proceder.\n");

        }

        while(dato==0)
        {
            printf("\nNombre o contrasenia incorrecto, por favor ingreselo nuevamente.\n");
            system("pause");
            system("cls");

            printf("\nIngresar Usuario:\n"); //seria el nombre y el apellido
            fflush(stdin);
            gets(nombreYapellido);

            printf("\nIngresar Contrasenia:\n");
            fflush(stdin);
            gets(contrasena);

            dato=ingresarNombreContrasena(nombreYapellido,contrasena,archivo);
        }
    }
    else
    {
        printf("\nNo fue posible encontrar el Usuario, desea registrarse? S-N\n");
        fflush(stdin);
        printf("\n");
        scanf("%c",&opcion);

        if(opcion=='s') //si quiere registrarlo, le pide los datos para hacerlo
        {
            aux = cargarUnUsuario();
            guardarUsuario(aux,archivo);
        }
        else{
            flag = 1;
        }
    }
    return flag;
}

int esUnNumero(char dato[]){//con esta funcion validamos q los caracteres ingresados en el string sean numeros
    for (int i = 0; dato[i]!= '\0'; i++)// "\0" es el final del string
    {
        if (isdigit(dato[i]) == 0)
            return 0;
    }
    return 1;
}
