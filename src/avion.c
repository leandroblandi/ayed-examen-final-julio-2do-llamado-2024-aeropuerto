#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avion.h"
#include "pasajero.h"
#include "lista.h"

struct Avion {
    char tipo[80];
    int matricula, capacidad, capacidadOriginal;
    ListaPtr pasajeros;
    ListaPtr destinos;
};

AvionPtr crearAvion(char tipo[], int matricula, int capacidad) {
    AvionPtr a = (AvionPtr) malloc(sizeof(struct Avion));

    if (!a) {
        return NULL;
    }

    strcpy(a->tipo, tipo);
    a->matricula = matricula;
    a->capacidad = capacidad;
    a->capacidadOriginal = capacidad;
    a->pasajeros = crearLista();
    a->destinos = crearLista();

    return a;
}

void liberarAvion(AvionPtr avion) {
    if (!avion) {
        return;
    }
    free(avion);
}

void mostrarAvion(AvionPtr avion) {
    if (!avion) {
        return;
    }

    printf("\nAvion(tipo=%s, matricula=%d, capacidad=%d)",
        avion->tipo,
        avion->matricula,
        avion->capacidad
    );

    printf("\nPasajeros asignados al Avion:");
    mostrarLista(avion->pasajeros, &mostrarPasajeroFn);

    printf("\nDestinos del Avion:");
    mostrarLista(avion->destinos, &mostrarCiudadFn);
}

void mostrarAvionFn(void* avion) {
    AvionPtr avionCasteado = (AvionPtr) avion;
    mostrarAvion(avionCasteado);
}

char* getTipo(AvionPtr avion) {
    if (!avion) {
        return NULL;
    }

    return avion->tipo;
}
int getMatricula(AvionPtr avion) {
    if (!avion) {
        return -1;
    }
    return avion->matricula;
}
int getCapacidad(AvionPtr avion) {
    if (!avion) {
        return -1;
    }
    return avion->capacidad;
}

void agregarPasajero(AvionPtr avion, PasajeroPtr pasajero) {
    if (!avion || !pasajero) {
        printf("El avion o el pasajero pasados por parametro son invalidos");
        return;
    }

    if (avion->capacidad <= 0) {
        printf("\nNo se puede agregar el pasajero con DNI %ld porque la capacidad del Avion %d ya esta al maximo.",
            getDni(pasajero),
            avion->matricula
        );
        return;
    }

    insertarUltimo(avion->pasajeros, pasajero);
    avion->capacidad--;
}

void eliminarPasajerosDeVentanilla(AvionPtr avion) {
    if (!avion || !avion->pasajeros || avion->capacidadOriginal ==avion->capacidad) {
        return;
    }

    // elimino de la lista todos los pasajeros con ventanilla 'S'
    eliminarPorCondicion(avion->pasajeros, esPasajeroDeVentanilla);
}

void agregarCiudadDestino(AvionPtr avion, CiudadPtr ciudad) {
    if (!avion || !avion->pasajeros || !ciudad) {
        return;
    }

    insertarUltimo(avion->destinos, ciudad);
}

float calcularDistanciaRecorrida(AvionPtr avion) {
    if (!avion || !avion->destinos) {
        return -999.0f;
    }

    return realizarCalculoEntreNodos(avion->destinos, &calcularDistanciaEntreCiudadesFn);
}