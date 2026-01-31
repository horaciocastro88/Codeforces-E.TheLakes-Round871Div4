# 🌊 Problema llamado The Lakes de Codeforces Round 871 Div 4

## 📌 Descripción del Proyecto 

	El objetivo es aprender y aplicar teoría de grafos, 
	y estructuras de datos fundamentales como la queue o cola.
	Hay que encontrar el volumen máximo de un "lago" representado por una matriz $n \times m$, 
	donde cada celda tiene una profundidad.
	Un lago se define como un conjunto de celdas conectadas ortogonalmente con profundidad no nula.

**Link al problema original:** [Codeforces - The Lakes](https://codeforces.com/problemset/problem/1829/E)

📌 Fue aceptado en los testeos de la plataforma.

## 🚀 Enfoque Técnico y Algoritmo
Para resolver este problema cumpliendo las restricciones de tiempo (3 segundos) y memoria, implementé un algoritmo de **Búsqueda en Anchura o amplitud (BFS)**.

### Puntos destacados de la implementación:
* **Gestión de Memoria Manual:** Uso intensivo de punteros y `malloc/free` para la asignación dinámica de la matriz y la estructura de la cola, asegurando que no haya fugas de memoria (memory leaks).
* **Estructuras de Datos Propias:** Implementación de una `Queue` (Cola) basada en listas enlazadas desde cero (`struct celda`), sin depender de librerías de alto nivel.
* **Algoritmo Flood Fill:** Uso de una matriz de visitados para recorrer cada componente conexa (lago) una única vez, logrando una complejidad lineal $O(N \times M)$.

## 🛠️ Tecnologías
* **Lenguaje:** C (Standard C99/C11)
* **Compilador:** GCC
* **Entorno:** Desarrollado en Raspberry Pi OS (Debian) / Geany

## 💻 Caso de prueba:

Debemos ingresar por consola:
1 3 3 1 2 0 3 4 0 0 0 5

El primer 1 es porque será una sola matriz.
Luego 3 y 3 porque sera una matriz 3x3.
Los siguientes son los numeros dentro de la matriz
que forman el o los lagos.

Salida:
10
 Es el lago mas grande, 1 + 2 + 3 + 4. 






