#include <math.h>
#include "funciones.h"

float calcularDistanciaEntrePuntos(float x1, float x2,  float y1, float y2) {
    float a = (float) pow(x2 - x1, 2);
    float b = (float) pow(y2 - y1, 2);
    return sqrtf(a + b);
}