#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ciudad.h"
#include "funciones.h"

struct Ciudad {
    char nombre[80];
    float latitud, longitud;
};

CiudadPtr crearCiudad(char nombre[], float latitud, float longitud) {
    CiudadPtr ciudad = (CiudadPtr) malloc(sizeof(struct Ciudad));

    if (!ciudad) {
        return NULL;
    }

    strcpy(ciudad->nombre, nombre);
    ciudad->latitud = latitud;
    ciudad->longitud = longitud;

    return ciudad;
}

void liberarCiudad(CiudadPtr ciudad) {
    if (!ciudad) {
        return;
    }
    free(ciudad);
}

void mostrarCiudad(CiudadPtr ciudad) {
    if (!ciudad) {
        return;
    }

    printf("\nCiudad(nombre=%s, latitud=%f, longitud=%f)",
        ciudad->nombre,
        ciudad->latitud,
        ciudad->longitud
    );
}
void mostrarCiudadFn(void* ciudad) {
    CiudadPtr c = (CiudadPtr) ciudad;
    mostrarCiudad(c);
}

char* getNombreCiudad(CiudadPtr ciudad) {
    if (!ciudad) {
        return NULL;
    }

    return ciudad->nombre;
}

float getLatitud(CiudadPtr ciudad) {
    if (!ciudad) {
        return -1.f;
    }
    return ciudad->latitud;
}

float getLongitud(CiudadPtr ciudad) {
    if (!ciudad) {
        return -1.f;
    }
    return ciudad->longitud;
}

float calcularDistanciaEntreCiudades(CiudadPtr c1, CiudadPtr c2) {
    if (!c1 || !c2) {
        return -1.00f;
    }

    float x1 = c1->latitud;
    float x2 = c2->latitud;
    float y1 = c1->longitud;
    float y2 = c2->longitud;

    return calcularDistanciaEntrePuntos(x1, x2, y1, y2);
}

float calcularDistanciaEntreCiudadesFn(void* c1, void* c2) {
    CiudadPtr ciudad1 = (CiudadPtr) c1;
    CiudadPtr ciudad2 = (CiudadPtr) c2;
    return calcularDistanciaEntreCiudades(ciudad1, ciudad2);
}