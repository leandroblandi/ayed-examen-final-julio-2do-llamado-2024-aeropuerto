#ifndef AEROPUERTO_H
#define AEROPUERTO_H

#include "avion.h"

struct Aeropuerto;
typedef struct Aeropuerto* AeropuertoPtr;

AeropuertoPtr crearAeropuerto(char nombre[], char direccion[], long telefono);
void liberarAeropuerto(AeropuertoPtr a);

void mostrarAeropuerto(AeropuertoPtr a);
void mostrarAeropuertoFn(void* a);

char* getNombre(AeropuertoPtr a);
char* getDireccion(AeropuertoPtr a);
long getTelefono(AeropuertoPtr a);

void agregarAvion(AeropuertoPtr aeropuerto, AvionPtr avion);

#endif //AEROPUERTO_H
