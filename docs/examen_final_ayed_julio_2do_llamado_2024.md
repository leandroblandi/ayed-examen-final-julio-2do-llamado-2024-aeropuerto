# Examen Final AYED - Julio - 2do Llamado 2024

## ENTREGA
Entregar el examen comprimido en rar a ambos mails antes de las 11hs:
* nico_perez_velez@hotmail.com
* nperez_dcao_smn@outlook.com

En caso que no puedan enviarlo me pueden dejar el link de un compartido.

---

## EXAMEN
Se evalúa el uso de listas del tipo void y la correcta implementación bajo el paradigma de TDA. Para aprobar es necesario tener hasta el ítem 6 funcionando correctamente.

Los libres deberán tener el ejercicio 7 y 8 correctamente encarados.

---

## ENUNCIADO
Se requiere implementar un sistema de gestión para un aeropuerto. Este sistema debe ser capaz de manejar una lista de aviones en el aeropuerto y cada avión debe contener una lista de pasajeros.

* **El Aeropuerto** tiene un nombre, dirección y teléfono.
* **Los aviones** tienen un tipo, matrícula y capacidad.
* **Los pasajeros** tienen apellido, dni, ventanilla.

### Tareas a realizar:

1. Crear el Aeropuerto Ministro Pistarini, Riccheri 33, 11-5480-61111.
2. Agregar 3 aviones al Aeropuerto:
    * Boeing 737, 1111, 10
    * Airbus A320, 2222, 5
    * Embraer E190, 3333, 5
3. Agregar los siguientes pasajeros a los aviones:
    * **Al avión 1111:**
        * Apellido1, 1, 'S'
        * Apellido2, 2, 'S'
        * Apellido3, 3, 'N'
    * **Al avión 2222:**
        * Apellido4, 4, 'S'
        * Apellido5, 5, 'N'
        * Apellido6, 6, 'S'
4. Mostrar el Aeropuerto, se debe mostrar los aviones y sus pasajeros.
5. Agregar, también, los 6 pasajeros al avión 3333. Como 6 es más que la capacidad, uno de ellos debería tirar error y no agregarse. Luego volver a mostrar el aeropuerto.
6. Eliminar a todos los pasajeros de ventanilla. Volver a mostrar el aeropuerto.
   *(4 puntos hasta aca)*

---

7. Al avión 3, agregarle una lista de Destinos (Ciudad, float latitud, float longitud):
    * **Buenos Aires**
        * Latitud: -34.6037
        * Longitud: -58.3816
    * **Asunción**
        * Latitud: -25.2637
        * Longitud: -57.5759
    * **La Paz**
        * Latitud: -16.5000
        * Longitud: -68.1500
          *(2 puntos)*

8. Calcular la distancia recorrida por el Avión 3. Usar librería `math.h` y función `sqrt` para la raíz.
   *(2 puntos)*