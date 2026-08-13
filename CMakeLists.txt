cmake_minimum_required(VERSION 4.3)
project(ayed_examen_final_julio_2do_llamado_2024 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

set(SOURCES
        src/main.c
        src/lista.c
        src/nodo.c
        src/pasajero.c
        src/avion.c
        src/aeropuerto.c
        src/ciudad.c
        src/funciones.c
)

add_executable(ayed_examen_final_julio_2do_llamado_2024 ${SOURCES})
