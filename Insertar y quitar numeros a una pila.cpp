/*Ejercicio : Hacer un programa para agregar elementos una pila (PUSH), hasta que el
usuario lo decida, después eliminar dichos elementos (POP).*/
//Por Aneudy Patiño & Lester Vásquez UAPA
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo  //Crea la estructura del Nodo
{
	int dato; //Elemento Intero numerico
	Nodo *siguiente; //Puntero en memoria hacia abajo al siguiente Nodo
};

//Funciones
void agregarPila(Nodo *&, int); //Agrega un elemento al nodo por referencia *& de tipo Entero
void sacarPila(Nodo *&, int &); //Elimina un elemento al nodo por referencia *& de tipo Entero

int main()
{
	Nodo *pila = NULL; //Inicializamos pila vacia
	int dato;
	char rpt;
	cout << "\n*** ALGORITMO DE UNA PILA ***\n\n";
	do
	{ //Pedimos todos los elementos de la pila
		cout << "Digite un numero: ";
		cin >> dato;
		agregarPila(pila, dato);

		cout << "\nDesea agregar otro numero a pila(s/n): ";
		cin >> rpt;
	} while ((rpt == 's') || (rpt == 'S'));

	cout << "\nSacando elementos de la PILA: \n";
	while (pila != NULL) //Bucle que recorre la Pila mientras contenga elementos
	{					
		sacarPila(pila, dato); //Llamo funcion 

		if (pila != NULL)  //Condicion si la Pila no esta vacia 
		{
			cout << dato << " ,"; //Imprime el valor y una coma (,)
		}
		else  //Imprime el valor y coloca un punto final (.)
		{
			cout << dato << ".";
		}
	}

	getch();
	return 0;
}

void agregarPila(Nodo *&pila, int n) //Agrega un Elemento a la Pila por referencia, un valor Entero
{
	Nodo *nuevo_nodo = new Nodo(); //Reservamos la memoria del Nodo
	nuevo_nodo->dato = n;  //Cargamos el valor dentro del nodo(dato) 
	nuevo_nodo->siguiente = pila; //Cargamos el puntero siguiente con el valor de pila
	pila = nuevo_nodo; //Asignar el nuevo nodo a pila

	cout << "\tElemento " << n << " agregado a PILA correctamente"; //Mostrar el valor agregado
}

void sacarPila(Nodo *&pila, int &n) // Elimina un Elemento de la Pila con datos por referencia
{
	Nodo *aux = pila; //Variable auxiliar de tipo Nodo que apunta a la cima
	n = aux->dato; //Asignamos el valor del nodo Pila en la cima
	pila = aux->siguiente; //pasamos al Nodo siguiente
	delete aux; //Eliminamos el valor de la cima
}
