#ifndef PASAJERO_H
#define PASAJERO_H

struct Pasajero;
typedef struct Pasajero* PasajeroPtr;

PasajeroPtr crearPasajero(char apellido[], long dni, char ventanilla);
void liberarPasajero(PasajeroPtr pasajero);

void mostrarPasajero(PasajeroPtr pasajero);
void mostrarPasajeroFn(void* pasajero);

char* getApellido(PasajeroPtr pasajero);
long getDni(PasajeroPtr pasajero);
char getVentanilla(PasajeroPtr pasajero);

int esPasajeroDeVentanilla(void* pasajero);

#endif //PASAJERO_H
