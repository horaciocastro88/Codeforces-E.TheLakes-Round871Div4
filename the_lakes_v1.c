
	/* E.The Lakes - Round 871 (Div. 4) */
	
	/* Version con cola implementada. */
	
	/* Eliminamos pasos innecesarios */
	
#include <stdio.h>
#include <stdlib.h>

#define P printf
#define S scanf

int resolver_problema();

	// Implementacion de la cola

typedef struct celda {
	
	int profundidad;
	int posX;
	int posY;
	
	struct celda * siguiente;	
	
} celda;

celda * front = NULL;
celda * rear = NULL;

void enqueue (int prof, int posX, int posY);
celda * dequeue ();
void vaciar_queue();


int main () {
	
	int t, i;
	
	S("%d", &t);
	
	int * array_res;
	
	array_res = (int *) malloc ( t * sizeof(int) );
	
	if (array_res == NULL) { P("Error en la asig de memoria dinamica.\n"); return 1;}
	
	for ( i = 0; i < t; i++) {
		
		array_res[i] = resolver_problema();
		
		if (array_res[i] == - 1) { P("Error en la asig de memoria dinamica.\n"); free(array_res); return 1; }
		
	}
	
	//P("\n\n Volvemos a los resultados finales \n\n");
	
	for ( i = 0; i < t; i++) {
		
		P("%d\n", array_res[i]) ;
		
	}
	
	free(array_res);
	
	return 0;
	
}	

int resolver_problema() {
	
	//P(" ** Resolucion ** \n\n");
	
	int filas, columnas;
	
	S("%d", &filas);
	
	S("%d", &columnas);
	
	int ** matriz;
	
	matriz =(int **) malloc ( filas * sizeof(int *) );
	
	if (matriz == NULL) {return -1;}
	
	int i, j, k;
	
	for ( i = 0; i < filas; i++) {
		
		matriz[i] = (int *) malloc (columnas * sizeof(int) );
		
		if (matriz[i] == NULL) { 
			
			for ( k = 0; k < i; k++) free(matriz[k]);
				
			free(matriz);
			
			return - 1;
		
		}
		
	}
	
	for (i = 0; i < filas; i++) 
		for (j = 0; j < columnas; j++) 
			S("%d", &matriz[i][j]);
			
	
	// Matriz de visitados
	
	int ** matriz_visitados;
	
	matriz_visitados = (int **) malloc ( filas * sizeof(int *) );
	if (matriz_visitados == NULL) {return -1;}
	
	for ( i = 0; i < filas; i++) {
	
		matriz_visitados[i] = (int *) malloc ( columnas * sizeof(int) );
		
		if ( matriz_visitados[i] == NULL) {
			
			for ( k = 0; k < i; k++) free(matriz_visitados[k]);
			
			free(matriz_visitados);
			
			return -1;
			
		}
		
	}
	
	for ( i = 0; i < filas; i++)
		for(j = 0; j < columnas; j++)
			matriz_visitados[i][j] = 0;
	
	// Logica
	
	int max_volumen = 0;
	int volumen_actual = 0;
	
	int nuevoX;
	int nuevoY;
	
	for ( i = 0; i < filas; i++)
		for ( j = 0; j < columnas; j++) {
			
			if (matriz_visitados[i][j] == 0 && matriz[i][j] > 0) {
				
				enqueue(matriz[i][j], i, j);
				matriz_visitados[i][j] = 1;
				volumen_actual = volumen_actual + matriz[i][j];
				
			}
			
			while ( front != NULL) {
				
				celda * actual;
				
				actual = dequeue();
				
				// Verificamos Vecinos
				
				//  El de arriba
				
				nuevoX = actual->posX + 1;
				nuevoY = actual->posY;
				
				if (nuevoX >= 0 && nuevoX < filas && nuevoY >= 0 && nuevoY < columnas && 
				matriz[nuevoX][nuevoY] > 0 && matriz_visitados[nuevoX][nuevoY] == 0) {
					
					matriz_visitados[nuevoX][nuevoY] = 1;
					volumen_actual = volumen_actual + matriz[nuevoX][nuevoY];
					enqueue(matriz[nuevoX][nuevoY], nuevoX, nuevoY);
					
				}
				
				// El de abajo
				
				nuevoX = actual->posX - 1;
				nuevoY = actual->posY;
				
				if (nuevoX >= 0 && nuevoX < filas && nuevoY >= 0 && nuevoY < columnas && 
				matriz[nuevoX][nuevoY] > 0 && matriz_visitados[nuevoX][nuevoY] == 0) {
					
					matriz_visitados[nuevoX][nuevoY] = 1;
					volumen_actual = volumen_actual + matriz[nuevoX][nuevoY];
					enqueue(matriz[nuevoX][nuevoY], nuevoX, nuevoY);
					
				}
				
				// El de la derecha
				
				nuevoX = actual->posX;
				nuevoY = actual->posY + 1;
				
				if (nuevoX >= 0 && nuevoX < filas && nuevoY >= 0 && nuevoY < columnas && 
				matriz[nuevoX][nuevoY] > 0 && matriz_visitados[nuevoX][nuevoY] == 0) {
					
					matriz_visitados[nuevoX][nuevoY] = 1;
					volumen_actual = volumen_actual + matriz[nuevoX][nuevoY];
					enqueue(matriz[nuevoX][nuevoY], nuevoX, nuevoY);
					
				}
				
				// El de la izquierda
				
				nuevoX = actual->posX;
				nuevoY = actual->posY - 1;
				
				if (nuevoX >= 0 && nuevoX < filas && nuevoY >= 0 && nuevoY < columnas && 
				matriz[nuevoX][nuevoY] > 0 && matriz_visitados[nuevoX][nuevoY] == 0) {
					
					matriz_visitados[nuevoX][nuevoY] = 1;
					volumen_actual = volumen_actual + matriz[nuevoX][nuevoY];
					enqueue(matriz[nuevoX][nuevoY], nuevoX, nuevoY);
					
				}
				
				free(actual);
				
			}
			
			if (volumen_actual > max_volumen)
				max_volumen = volumen_actual;
				
			volumen_actual = 0;
			
		}
	
	// Liberacion de memoria
				
	for ( i = 0; i < filas; i++) free(matriz[i]);
		
	free(matriz);		
				
	for ( i = 0; i < filas; i++) free(matriz_visitados[i]);
	
	free(matriz_visitados);		
	
	vaciar_queue();	
	
	return max_volumen;
	
}

void enqueue (int prof, int posX, int posY) {
	
	celda * nuevo;
	
	nuevo = (celda *) malloc ( sizeof(celda) );
	if ( nuevo == NULL) { P("Error en la asig de memoria.\n"); return;}
	
	nuevo->profundidad = prof;			
	nuevo->posX = posX;
	nuevo->posY = posY;
	
	nuevo->siguiente = NULL;		
	
	if ( front == NULL) {	
		
		front = nuevo;
		rear = nuevo;
		
	}
	
	else {
		
		rear->siguiente = nuevo;	
		rear = nuevo;
	}
	
	
}

celda * dequeue () {
	
	if ( front == NULL) 
		return NULL;	
	
	celda * actual = front;
	
	front = actual->siguiente;
	
	return actual;	
	
	return NULL;
	
}

void vaciar_queue () {
	
	celda * actual;		
	
	while ( front != NULL) {
		
		actual = front;
		front = actual->siguiente;
		free(actual);		
		
	}
	
}
