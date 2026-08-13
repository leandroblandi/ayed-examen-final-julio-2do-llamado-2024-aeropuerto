#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "aeropuerto.h"

struct Aeropuerto {
    char nombre[80];
    char direccion[100];
    long telefono;
    ListaPtr aviones;
};

AeropuertoPtr crearAeropuerto(char nombre[], char direccion[], long telefono) {
    AeropuertoPtr a = (AeropuertoPtr) malloc(sizeof(struct Aeropuerto));

    if (!a) {
        return NULL;
    }

    strcpy(a->nombre, nombre);
    strcpy(a->direccion, direccion);
    a->telefono = telefono;
    a->aviones = crearLista();

    return a;
}

void liberarAeropuerto(AeropuertoPtr a) {
    if (!a) {
        return;
    }
    free(a);
}

void mostrarAeropuerto(AeropuertoPtr a) {
    if (!a) {
        return;
    }

    printf("\nAeropuerto(nombre=%s, direccion=%s, telefono=%ld)",
        a->nombre,
        a->direccion,
        a->telefono
    );

    printf("\nAviones asociados al Aeropuerto:\n");
    mostrarLista(a->aviones, &mostrarAvionFn);
}

void mostrarAeropuertoFn(void* a) {
    AeropuertoPtr aeropuerto = *((AeropuertoPtr*) a);
    mostrarAeropuerto(aeropuerto);
}

char* getNombre(AeropuertoPtr a) {
    if (!a) {
        return NULL;
    }
    return a->nombre;
}

char* getDireccion(AeropuertoPtr a) {
    if (!a) {
        return NULL;
    }
    return a->direccion;
}

long getTelefono(AeropuertoPtr a) {
    if (!a) {
        return -1;
    }
    return a->telefono;
}

void agregarAvion(AeropuertoPtr aeropuerto, AvionPtr avion) {
    if (!aeropuerto || !avion) {
        printf("El aeropuerto o el avion pasados por parametro son invalidos");
        return;
    }

    insertarUltimo(aeropuerto->aviones, avion);
}