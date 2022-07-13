//
// Created by Mati on 27/6/2022.
//

#ifndef TPFINALMENU_USUARIOS_H
#define TPFINALMENU_USUARIOS_H

#include "estructuras.h"

//FUNCIONES USUARIO
//USUARIOS
int iniciarSesionUsuario(char archivo[]);//se manda el archivo de usuarios por parametro para poder verificar si el usuario ingresado esta en el archivo
void guardarUsuario(Usuario temp, char archivo[]);//se guarda usuario en el archivo
Usuario cargarUnUsuario();//se carga el usuario
int encontrarUsuario(char dniIngreso[10], char archivo[]);//se envia por parametro el dni y lo busca con ese dato, si no lo encuentra te da la opcion de registrarte
int ingresarNombreContrasena(char nombreIngreso[20], char contraIngreso[20], char archivo[]);//se registra el usuario y se guarda en el archivo
int esUnNumero(char dato[]);//con esta funcion validamos q los caracteres ingresados en el string sean numeros
#endif //TPFINALMENU_USUARIOS_H
