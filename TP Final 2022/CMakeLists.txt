cmake_minimum_required(VERSION 3.22)
project(TPFINALmenu C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TPFINALmenu main.c pila.c pila.h estructuras.c estructuras.h menus.c menus.h usuarios.c usuarios.h producto.c producto.h archivos.c archivos.h empleado.c empleado.h compra.c compra.h)
