#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pasajero.h"

struct Pasajero {
    char apellido[50];
    long dni;
    char ventanilla;
};

PasajeroPtr crearPasajero(char apellido[], long dni, char ventanilla) {
    PasajeroPtr pasajero = (PasajeroPtr) malloc(sizeof(struct Pasajero));

    if (!pasajero) {
        return NULL;
    }

    strcpy(pasajero->apellido, apellido);
    pasajero->dni = dni;
    pasajero->ventanilla = ventanilla;

    return pasajero;
}

void liberarPasajero(PasajeroPtr pasajero) {
    if (!pasajero) {
        return;
    }

    free(pasajero);
}

void mostrarPasajero(PasajeroPtr pasajero) {
    if (!pasajero) {
        return;
    }

    printf("\nPasajero(dni=%ld, apellido=%s, ventanilla=%c)",
        pasajero->dni,
        pasajero->apellido,
        pasajero->ventanilla
    );
}

void mostrarPasajeroFn(void* pasajero) {
    PasajeroPtr pasajeroCasteado = (PasajeroPtr) pasajero;
    mostrarPasajero(pasajeroCasteado);
}

char* getApellido(PasajeroPtr pasajero) {
    if (!pasajero)
        return NULL;
    return pasajero->apellido;
}

long getDni(PasajeroPtr pasajero) {
    if (!pasajero)
        return -1;
    return pasajero->dni;
}

char getVentanilla(PasajeroPtr pasajero) {
    if (!pasajero)
        return 'N';
    return pasajero->ventanilla;
}

int esPasajeroDeVentanilla(void* pasajero) {
    if (!pasajero) {
        return -1;
    }

    PasajeroPtr p = (PasajeroPtr) pasajero;

    if (p->ventanilla == 'S') {
        return 1;
    }

    return 0;

}