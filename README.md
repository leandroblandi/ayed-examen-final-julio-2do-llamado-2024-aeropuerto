# Examen Final AYED - Julio 2do Llamado 2024

![C](https://img.shields.io/badge/C-11-00599C?logo=c&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-4.3-064F8C?logo=cmake&logoColor=white)
![CLion](https://img.shields.io/badge/CLion-IDE-000000?logo=clion&logoColor=white)
![TDA](https://img.shields.io/badge/Paradigma-TDA-4B8BBE)
![Lista Simplemente Enlazada](https://img.shields.io/badge/Estructura-Lista%20Simplemente%20Enlazada-2E8B57)
![Lista Void](https://img.shields.io/badge/Lista-void*%20gen%C3%A9rica-6A5ACD)
![Callbacks](https://img.shields.io/badge/Patr%C3%B3n-Punteros%20a%20Funci%C3%B3n-8A2BE2)
![Opaque Pointer](https://img.shields.io/badge/Patr%C3%B3n-Opaque%20Pointer-B8860B)
![Bubble Sort](https://img.shields.io/badge/Algoritmo-Bubble%20Sort-DC143C)
![Memoria Dinámica](https://img.shields.io/badge/Memoria-malloc%20%2F%20free-555555)

Sistema de gestión de un aeropuerto implementado en C, resolviendo el examen final de
Algoritmos y Estructuras de Datos (Julio, 2do llamado 2024). El objetivo del examen es
demostrar el uso de listas genéricas de tipo `void*` y la correcta implementación bajo el
paradigma de TDA (Tipo de Dato Abstracto).

## Consigna (parte práctica)

Se requiere implementar un sistema de gestión para un aeropuerto, capaz de manejar una lista
de aviones, donde cada avión contiene su propia lista de pasajeros.

- **Aeropuerto**: nombre, dirección, teléfono.
- **Avión**: tipo, matrícula, capacidad.
- **Pasajero**: apellido, DNI, ventanilla.

Tareas a realizar:

1. Crear el aeropuerto *Ministro Pistarini, Riccheri 33, 11-5480-61111*.
2. Agregar 3 aviones: *Boeing 737 / 1111 / 10*, *Airbus A320 / 2222 / 5*, *Embraer E190 / 3333 / 5*.
3. Agregar pasajeros: `Apellido1..3` al avión `1111` y `Apellido4..6` al avión `2222`.
4. Mostrar el aeropuerto con sus aviones y los pasajeros de cada avión.
5. Agregar los 6 pasajeros al avión `3333`; al exceder la capacidad (5), uno debe arrojar error
   y no agregarse. Volver a mostrar el aeropuerto.
6. Eliminar a todos los pasajeros de ventanilla y volver a mostrar el aeropuerto.
7. Agregar al avión 3 una lista de destinos (ciudad, latitud, longitud): *Buenos Aires
   (-34.6037, -58.3816)*, *Asunción (-25.2637, -57.5759)*, *La Paz (-16.5000, -68.1500)*.
8. Calcular la distancia recorrida por el avión 3 usando `math.h` y `sqrt`.

## Estado de la resolución

| Ítem | Descripción | Estado |
| --- | --- | --- |
| 1 | Crear aeropuerto | Implementado |
| 2 | Agregar aviones | Implementado |
| 3 | Agregar pasajeros | Implementado |
| 4 | Mostrar aeropuerto completo | Implementado |
| 5 | Validación de capacidad | Implementado |
| 6 | Eliminar pasajeros de ventanilla | Implementado |
| 7 | Lista de destinos del avión 3 | Pendiente |
| 8 | Cálculo de distancia recorrida | Pendiente |

## Estructura del proyecto

```
.
├── CMakeLists.txt      Configuración de compilación (C11)
├── main.c              Punto de entrada y casos de prueba de la consigna
├── nodo.h / nodo.c     TDA Nodo: dato void* + puntero al siguiente
├── lista.h / lista.c   TDA Lista simplemente enlazada genérica
├── aeropuerto.h / .c   TDA Aeropuerto, contiene una lista de aviones
├── avion.h / avion.c   TDA Avión, contiene una lista de pasajeros
├── pasajero.h / .c     TDA Pasajero
└── docs/               Enunciado original del examen
```

## Diseño

### TDA con punteros opacos

Cada módulo declara su `struct` únicamente en el `.c` y expone en el `.h` un typedef al
puntero (`ListaPtr`, `NodoPtr`, `AeropuertoPtr`, `AvionPtr`, `PasajeroPtr`). El consumidor
nunca accede a los campos de forma directa: solo a través de constructores, destructores,
getters, setters y operaciones. Esto garantiza el encapsulamiento propio del paradigma TDA.

### Lista genérica de tipo void

El nodo almacena el dato como `typedef void* DatoPtr`, por lo que la misma implementación de
lista se reutiliza para enteros, aviones y pasajeros. Las operaciones que dependen del tipo
concreto se resuelven mediante punteros a función que recibe la lista por parámetro:

- `mostrarLista(lista, void (*mostrar)(DatoPtr))` — impresión del dato concreto.
- `ordenarMedianteBurbuja(lista, int (*comparar)(DatoPtr, DatoPtr))` — orden por Bubble Sort.
- `eliminarPorCondicion(lista, int (*condicion)(DatoPtr))` — eliminación por criterio.

De esta forma, `mostrarAvionFn`, `mostrarPasajeroFn` y `esPasajeroDeVentanilla` actúan como
adaptadores entre la lista genérica y cada TDA concreto.

### Composición de TDAs

El aeropuerto mantiene una `ListaPtr aviones` y cada avión una `ListaPtr pasajeros`, por lo
que mostrar el aeropuerto recorre en cascada aviones y pasajeros. El avión conserva su
capacidad original y la capacidad disponible: `agregarPasajero` rechaza el alta e informa el
error por consola cuando la capacidad llega a cero (ítem 5), y
`eliminarPasajerosDeVentanilla` delega en `eliminarPorCondicion` usando
`esPasajeroDeVentanilla` como criterio (ítem 6).

## API de la lista

| Operación | Función |
| --- | --- |
| Construcción | `crearLista`, `liberarLista` |
| Inserción | `insertarPrimero`, `insertarUltimo`, `insertarEnPosicion` |
| Eliminación | `eliminarPrimero`, `eliminarUltimo`, `eliminarEnPosicion`, `eliminar`, `eliminarPorCondicion` |
| Consulta | `getPrimero`, `setPrimero`, `getUltimo`, `setUltimo`, `getLargo` |
| Recorrido | `mostrarLista`, `ordenarMedianteBurbuja` |

## Compilación y ejecución

Requisitos: CMake 4.3 o superior y un compilador con soporte para C11 (GCC, Clang o MSVC).

```bash
cmake -S . -B build
cmake --build build
./build/ayed_examen_final_julio_2do_llamado_2024
```

En Windows con MSVC el ejecutable se genera en `build/Debug/`.

## Pruebas

`main.c` contiene funciones de verificación manual que se habilitan descomentando su llamada
dentro de `main`:

- `crearLista_debeCrearseListVacia`
- `crearListaEInsertarDatos_DebeMostrarseCorrectamente`
- `crearPasajero_debeCrearseYMostrarseCorrectamente`
- `crearAvion_debeCrearseYMostrarseCorrectamente`
- `crearAeropuertoYAgregarAviones_debeCrearseYMostrarseCorrectamente` — recorre los ítems 1 a 6
  de la consigna y es la que se ejecuta por defecto.
