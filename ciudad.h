#ifndef CIUDAD_H
#define CIUDAD_H

struct Ciudad;
typedef struct Ciudad* CiudadPtr;

CiudadPtr crearCiudad(char nombre[], float latitud, float longitud);
void liberarCiudad(CiudadPtr ciudad);

void mostrarCiudad(CiudadPtr ciudad);
void mostrarCiudadFn(void* ciudad);

char* getNombreCiudad(CiudadPtr ciudad);
float getLatitud(CiudadPtr ciudad);
float getLongitud(CiudadPtr ciudad);

float calcularDistanciaEntreCiudades(CiudadPtr c1, CiudadPtr c2);
float calcularDistanciaEntreCiudadesFn(void* c1, void* c2);

#endif //CIUDAD_H
