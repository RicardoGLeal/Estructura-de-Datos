#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

int checkletter(int dato);
bool cac;
int datof;
char letter = 'A';
int opcion, acumulador = 0;

struct nodoGrafo {
	char nombre;
	struct nodoGrafo *sig;
	struct nodoArista *ady;
};

struct nodoArista {
	int distanciaArista;
	struct nodoGrafo *destino;
	struct nodoArista *sig;
};

typedef struct nodoGrafo *nodo;
typedef struct nodoArista *arista;

nodo ptrCabeza;

int buscarNodo(char x){
	nodo aux;
	aux = ptrCabeza;
	while (aux != NULL)
	{
		if (aux->nombre == x){
			return 1;
		}
		aux = aux->sig;
	}
	if (aux == NULL){
		return 0;
	}
}

void agregarArista(nodo &aux, nodo &aux2, arista &nuevo)
{
	arista nueva;
	if (aux->ady == NULL){
		aux->ady = nuevo;
		nuevo->destino = aux2;
		cout<<"Arista agregada correctamente"<<endl;
	}
	else{
		nueva = aux->ady;
		while (nueva->sig != NULL)
			nueva  = nueva->sig;
		nuevo->destino = aux2;
		nueva->sig = nuevo;
		cout << "Arista agregada correctamente"<<endl;
	}

}

void insertarArista(){
	char inicio, destino;
	arista nuevo = new struct nodoArista;
	nodo aux, aux2;

	if (ptrCabeza == NULL){
		cout << "Error: Grafo vacio"<<endl;
		return;
	}
	nuevo->sig = NULL;
	cout << "Nodo de inicio: ";
	cin >> inicio;
	cout << "Nodo destino: ";
	cin >> destino;
	if (buscarNodo(inicio) == 0 || buscarNodo(destino) == 0){
		cout << "No existe el nodo!";
	}
	else {
		cout << "Ingresa la distancia de la arista: ";
		cin >> nuevo->distanciaArista;
		aux = ptrCabeza;
		aux2 = ptrCabeza;
		while (aux2 != NULL)
		{
			if (aux2->nombre == destino){
				break;
			}

			aux2 = aux2->sig;
		}
		while (aux != NULL)
		{
			if (aux->nombre == inicio){
				agregarArista(aux, aux2, nuevo);
				return;
			}

			aux = aux->sig;
		}
		cout << "Nodo insertado!";
	}
}

void insertarNodo(){
	nodo aux, nuevo = new struct nodoGrafo;
	nuevo->nombre = letter;
	nuevo->sig = NULL;
	nuevo->ady = NULL;

	if (ptrCabeza == NULL){
		ptrCabeza = nuevo;
	}
	else
	{
		aux = ptrCabeza;
		while (aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}

}

void vaciarAristas(nodo &aux)
{
	arista aux2, aux3;
	aux2 = aux->ady;
	while (aux2->sig != NULL)
	{
		aux3 = aux2;
		aux2 = aux2->sig;
		delete aux3;
	}
}

void eliminarNodo(){
	char var;
	nodo aux, ant = NULL;
	aux = ptrCabeza;
	if (ptrCabeza == NULL){
		cout << "No hay nodos para eliminar!";
		return;
	}
	cout << "Ingrese el nombre del nodo: ";
	cin >> var;

	while(aux != NULL){
		if(aux->nombre == var){
			if (aux->ady != NULL)
				vaciarAristas(aux);

			if (aux == ptrCabeza){

				ptrCabeza = ptrCabeza->sig;
				delete(aux);
				cout <<"Nodo eliminado"<<endl;
				return;

			}
			else{
				ant->sig = aux->sig;
				delete(aux);
				cout <<"Nodo eliminado"<<endl;
				return;
			}
		}
		else{
			ant = aux;
			aux = aux->sig;
		}
	}
	cout<<"Nodo no encontrado"<<endl;
	acumulador = 0;
}

void mostrarGrafo(){

	nodo aux;
	arista aux2;

	char start, end;
	aux = ptrCabeza;
	cout<<"Nodo inicio\n";
	cin>>start;
	cout<<"Nodo destino\n";
	cin>>end;

	if (buscarNodo(start)==1)
	{
		if (buscarNodo(end)==1)
		{
			if (aux!=NULL)
			{
				aux2 = aux->ady;
				if(aux2!=NULL){

					while((aux->sig!=NULL)&&(aux->ady!=NULL))
					{
						cout<<aux->nombre;
						if(aux->ady != NULL)
						{
							for (int i = 0; i < aux->ady->distanciaArista; i++)
								cout<<"-";
						acumulador = acumulador + aux->ady->distanciaArista;
						aux = aux->sig;
						}
						else
							break;
					}
					cout<<end<<" ";
					cout<<"Distancia: ("<<acumulador<<")";
					acumulador = 0;
				}
				else
					cout<<"Error: No se encontro ninguna conexion"<<endl;
			}
		}
		else
			cout<<"Error: No se encontro ninguna conexion"<<endl;
	}
	else
	cout<<"Error: No se encontro ninguna conexion"<<endl;
}

int main(){

	ptrCabeza = NULL;
	do {
		system("cls");
		cout << "Grafos"<<endl;
		do
	{
		system("cls");
		cout<<"Escoge una opcion"<<endl;
		cout << "\n1.-Insertar Nodo\n2.-Insertar Aristas\n3.-Mostrar Camino\n4.-Eliminar Nodo\n5.-Salir\n";
		cin>>datof;
		cac = checkletter(opcion);
		if (cac == false)
			opcion = (int)datof;
	} while (cac == true);

		switch (opcion) {
		case 1:
			insertarNodo();
			cout<<"Nodo "<<letter<<" creado correctamente"<<endl;
			system("pause");
			letter++;
			break;
		case 2:
			insertarArista();
			break;
		case 3:
			mostrarGrafo();
			system("pause");
			break;
		case 4:
			eliminarNodo();
			system("pause");
			break;
		case 5:
			system("pause");
			return 0;
			break;
		default:
			cout << "Error: Opcion invalida"<<endl;
			_getch();
			break;  
		}
	} while (opcion != 5);

	return 0;
}

int checkletter(int dato)
{
	bool mistake = false;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		mistake= true;
		cout<<"Solo puedes ingresar numeros..."<<endl<<"Repite"<<endl;
		system("pause");
	}
	return mistake;
}