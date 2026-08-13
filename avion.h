
#ifndef AVION_H
#define AVION_H
#include "ciudad.h"
#include "pasajero.h"

struct Avion;
typedef struct Avion* AvionPtr;

AvionPtr crearAvion(char tipo[], int matricula, int capacidad);
void liberarAvion(AvionPtr avion);

void mostrarAvion(AvionPtr avion);
void mostrarAvionFn(void* avion);

char* getTipo(AvionPtr avion);
int getMatricula(AvionPtr avion);
int getCapacidad(AvionPtr avion);

void agregarPasajero(AvionPtr avion, PasajeroPtr pasajero);
void eliminarPasajerosDeVentanilla(AvionPtr avion);

void agregarCiudadDestino(AvionPtr avion, CiudadPtr ciudad);
float calcularDistanciaRecorrida(AvionPtr avion);

#endif //AVION_H
