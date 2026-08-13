#include <stdio.h>

#include "aeropuerto.h"
#include "avion.h"
#include "lista.h"
#include "pasajero.h"

// funciones propias del dato concreto
int compararEnteros(DatoPtr d1, DatoPtr d2);
void mostrarEntero(void* dato);

// funciones test
void crearLista_debeCrearseListVacia();
void crearListaEInsertarDatos_DebeMostrarseCorrectamente();
void crearPasajero_debeCrearseYMostrarseCorrectamente();
void crearAvion_debeCrearseYMostrarseCorrectamente();
void crearAeropuertoYAgregarAviones_debeCrearseYMostrarseCorrectamente();

int main(void) {
    //crearListaEInsertarDatos_DebeMostrarseCorrectamente();
    //crearListaEInsertarDatos_DebeMostrarseCorrectamente();
    // crearPasajero_debeCrearseYMostrarseCorrectamente();
    // crearAvion_debeCrearseYMostrarseCorrectamente();
    crearAeropuertoYAgregarAviones_debeCrearseYMostrarseCorrectamente();
    return 0;
}

void crearLista_debeCrearseListVacia() {
    ListaPtr lista = crearLista();
    mostrarLista(lista, &mostrarEntero);
    liberarLista(lista);
}

void crearListaEInsertarDatos_DebeMostrarseCorrectamente() {
    ListaPtr lista = crearLista();

    // insertamos algunos datos
    int numero1 = 3;
    insertarUltimo(lista, &numero1);

    int numero2 = 2;
    insertarUltimo(lista, &numero2);

    int numero3 = 17;
    insertarPrimero(lista, &numero3);

    // ordenamos y mostramos
    ordenarMedianteBurbuja(lista, &compararEnteros);
    mostrarLista(lista, &mostrarEntero);

    // elimino el 3, y muestro
    eliminarEnPosicion(lista, 1);
    mostrarLista(lista, &mostrarEntero);

    liberarLista(lista);
}

void crearPasajero_debeCrearseYMostrarseCorrectamente() {
    PasajeroPtr p = crearPasajero("Blandi", 44098528, 'S');
    mostrarPasajero(p);
    liberarPasajero(p);
}

void crearAvion_debeCrearseYMostrarseCorrectamente() {
    AvionPtr a = crearAvion("Boeing 777", 111222, 90);
    mostrarAvionFn(&a);
    liberarAvion(a);
}

void crearAeropuertoYAgregarAviones_debeCrearseYMostrarseCorrectamente() {
    AeropuertoPtr aeropuerto = crearAeropuerto("Ministro Pistarini", "Riccheri 33", 11548061111L);

    AvionPtr a1 = crearAvion("Boeing 737", 1111, 10);
    AvionPtr a2 = crearAvion("Airbus A320", 2222, 5);
    AvionPtr a3 = crearAvion("Embraer E190", 3333, 5);

    PasajeroPtr p1 = crearPasajero("Apellido1", 1, 'S');
    PasajeroPtr p2 = crearPasajero("Apellido2", 2, 'S');
    PasajeroPtr p3 = crearPasajero("Apellido3", 3, 'N');
    PasajeroPtr p4 = crearPasajero("Apellido4", 4, 'S');
    PasajeroPtr p5 = crearPasajero("Apellido5", 5, 'N');
    PasajeroPtr p6 = crearPasajero("Apellido6", 6, 'S');

    agregarPasajero(a1, p1);
    agregarPasajero(a1, p2);
    agregarPasajero(a1, p3);

    agregarPasajero(a2, p4);
    agregarPasajero(a2, p5);
    agregarPasajero(a2, p6);

    agregarAvion(aeropuerto, a1);
    agregarAvion(aeropuerto, a2);
    agregarAvion(aeropuerto, a3);

    mostrarAeropuerto(aeropuerto);

    // tratamos de agregar 6 pasajeros, solo 5 seran agregados
    agregarPasajero(a3, p1);
    agregarPasajero(a3, p2);
    agregarPasajero(a3, p3);
    agregarPasajero(a3, p4);
    agregarPasajero(a3, p5);
    agregarPasajero(a3, p6);

    mostrarAeropuerto(aeropuerto);

    eliminarPasajerosDeVentanilla(a1);
    eliminarPasajerosDeVentanilla(a2);
    eliminarPasajerosDeVentanilla(a3);

    mostrarAeropuerto(aeropuerto);
}


void mostrarEntero(void* dato) {
    int datoCasteado = *((int*) dato);
    printf(" %d, ", datoCasteado);
}

int compararEnteros(DatoPtr d1, DatoPtr d2) {
    int dato1 = *((int*) d1);
    int dato2 = *((int*) d2);

    if (dato1 == dato2) {
        return 0;
    }

    if (dato1 < dato2) {
        return -1;
    }

    return 1;
}