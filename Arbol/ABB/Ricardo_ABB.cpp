#include "stdafx.h"
#include <iostream>
#include <conio.h>
#define COUNT 10
using namespace std;

struct Nodo
{
	int dato;
	Nodo *der;
	Nodo *izq;
} *raiz, *aux, *aux2;

typedef struct Nodo nodo;
typedef nodo *nodoA;
int orden = 2, altura, nivel;

void Insertar(int);
void Eliminar(int);
void Mostrar();
void PreOrden(nodoA);
void InOrden(nodoA);
void PostOrden(nodoA);
void Grafico(nodoA, int);
void Raiz();
void Hijos(nodoA);
void Padres(nodoA);
void Hojas(nodoA);
void Tamano();
void Orden();
void Altura(nodoA, int);
void Nivel();
bool Vacio();
bool Buscar(int);

int main()
{
	int num;
	int nivel = 0;
	int altura=1;
	char op;
	do
	{
		system("cls");
		cout << "Arbol Binario de Busqueda (ABB)"<<endl;
		cout<<"Introduce una opcion:"<<endl;
		cout<<"[A] Insertar\n[B] Eliminar\n[C] Mostrar\n[D] Raiz\n[E] Hijos\n[F] Padres\n[G] Hojas\n[H] Tamano\n[I] Orden\n[J] Altura\n[K] Nivel\n[S] Salir\n";
		op = _getch();
		op = toupper(op);
		switch (op)
		{
		case 'A': //INSERTAR
			system("cls");
			cout << "Ingrese un numero\n";
			cin >> num;
			Insertar(num);
			system("pause");
			break;
		case 'B': //ELIMINAR
			system("cls");
			cout << "Ingrese el numero que desea eliminar\n";
			cin >> num;
			Eliminar(num);
			system("pause");
			break;
		case 'C': //MOSTRAR
			system("cls");
			Mostrar();
			system("pause");
			break;
		case 'D': //RAIZ
			system("cls");
			Raiz();
			system("pause");
			break;
		case 'E': //HIJOS
			system("cls");
			Hijos(raiz);
			system("pause");
			break;
		case 'F': //PADRES
			system("cls");
			Padres(raiz);
			system("pause");
			break;
		case 'G': //HOJAS
			system("cls");
			Hojas(raiz);
			system("pause");
			break;
		case 'H': //TAMANO
			system("cls");
			Tamano();
			system("pause");
			break;
		case 'I': //ORDEN
			system("cls");
			Orden();
			system("pause");
			break;
		case 'J': //ALTURA
			system("cls");
			Altura(raiz, altura);
			system("pause");
			break;
		case 'K': //NIVEL
			system("cls");
			Nivel();
			system("pause");
			break;
		}
	} while (op!='S');
    return 0;
}

void Insertar(int x)
{
	if (Vacio())
	{
		raiz = new Nodo;
		raiz->dato = x;
		raiz->der = NULL;
		raiz->izq = NULL;
	}
	else if (Buscar(x))
		cout << "Error: El dato ingresado ya se encuentra en el arbol"<<endl;
	else
	{
		aux = raiz;
		Inserta:
		if (x < aux->dato)
		{
			if (aux->izq != NULL)
			{
				aux = aux->izq;
				goto Inserta;
			}
			else
			{
				aux->izq = new Nodo;
				aux->izq->dato = x;
				aux->izq->izq = NULL;
				aux->izq->der = NULL;
			}
		}
		else if (x > aux->dato)
		{
			if (aux->der != NULL)
			{
				aux = aux->der;
				goto Inserta;
			}
			else
			{
				aux->der = new Nodo;
				aux->der->dato = x;
				aux->der->izq = NULL;
				aux->der->der = NULL;
			}
		}
	}
}
// Editar Eliminar
void Eliminar(int x)
{
	int lado = 2; // 1=izq  0=der
	if (Vacio())
	{
		cout << "Error: No hay datos en el arbol"<<endl;
		return;
	}
	else if (!Buscar(x))
		cerr << "Error: El dato ingresado no esta en el arbol\n";
	aux = raiz;
	Elimina:
	if (x < aux->dato)
	{
		aux2 = aux;
		aux = aux->izq;
		lado = 1;
		goto Elimina;
	}
	else if (x > aux->dato)
	{
		aux2 = aux;
		aux = aux->der;
		lado = 0;
		goto Elimina;
	}
	else
	{
		if (aux->izq == NULL && aux->der == NULL)
		{
			if (aux == raiz)
				raiz = NULL;
			else
			{
				if (lado == 1)
				{
					delete aux;
					aux2->izq = NULL;
				}
				else if (lado == 0)
				{
					delete aux;
					aux2->der = NULL;
				}
			}
		}
		else if (aux->der == NULL && aux->izq != NULL)
		{
			if (aux = raiz)
			{
				aux2 = raiz;
				aux = aux->izq;
				raiz = aux;
				delete aux2;
			}
			else
			{
				aux2 = aux;
				aux = aux->izq;
				delete aux2;
			}
		}
		else if (aux->izq == NULL && aux->der != NULL)
		{
			if (aux == raiz)
			{
				aux2 = raiz;
				aux = aux->der;
				raiz = aux;
				delete aux2;
			}
			else
			{
				aux2 = aux;
				aux = aux->der;
				delete aux2;
			}
		}
		else
		{
			if (aux != raiz)
			{
				Nodo *temp = new Nodo;
				temp = aux;
				do
				{
					aux = aux->izq;
				} while (aux->izq != NULL);
				aux2->izq = aux;
				aux->der = temp->der;
				if (temp->izq != aux)
					aux->izq = temp->izq;
				else
					aux->izq = NULL;
			}
			else
			{
				aux2 = raiz->der;
				do
				{
						if(aux2->izq!= NULL)
					aux2 = aux2->izq;
				} while (aux2->izq != NULL);
				aux2->izq = raiz->izq;
				aux = raiz;
				raiz = aux2;
				delete aux;
			}
		}
	}
}

void Mostrar()
{
	int contador =1;
	char op;
	if (Vacio())
		cout << "Error: No existen datos en el arbol\n";
	else
	{
		do
		{
			system("cls");
			cout << "Como desea hacer el recorrido?\n[1] Pre-orden\n[2] In-orden\n[3] Post-orden\n[4] Grafico\n";
			op = _getch();
		} while (op != '1' && op != '2' && op != '3'&& op != '4');
		aux = raiz;
		switch (op)
		{
		case '1':
			PreOrden(raiz);
			break;
		case '2':
			InOrden(raiz);
			break;
		case '3':
			PostOrden(raiz);
			break;
		case '4':	
			Grafico(raiz, contador);
			break;
		}
	}
}

void PreOrden(nodo *aux3)
{
	if (aux3 != NULL)
	{
		cout << aux3->dato << endl;
		PreOrden(aux3->izq);
		PreOrden(aux3->der);
	}
}

void InOrden(Nodo *aux3)
{
	if (aux3 != NULL)
	{
		InOrden(aux3->izq);
		cout << aux3->dato << endl;
		InOrden(aux3->der);
	}
}

void PostOrden(Nodo *aux3)
{
	if (aux3 != NULL)
	{
		PostOrden(aux3->izq);
		PostOrden(aux3->der);
		cout << aux3->dato << endl;
	}
}

void Grafico(Nodo *aux3, int contador)
{
		if(aux3!=NULL)
		{
			for (int i = contador; i > -10; i--)
			cout<<"   ";
			cout<<aux3->dato<<endl;
			if(aux3->der!=NULL)
			Grafico(aux3->der, contador+1);
			if(aux3->izq!=NULL)
			Grafico(aux3->izq, contador-1);
		}
}
void Raiz()
{
	if (!Vacio())
		cout << "Raiz: " << raiz->dato << endl;
	else
		cout << "No hay datos en el arbol\n";
}

void Hijos(nodo *aux3)
{
	if (!Vacio())
	{
		if (aux3 != NULL)
		{
			if (aux3 != raiz)
				cout << aux3->dato << endl;
			Hijos(aux3->izq);
			Hijos(aux3->der);
		}
	}
}

void Padres(nodo *aux3)
{
	if (!Vacio())
	{
		if (aux3 != NULL)
		{
			if (aux3->izq != NULL || aux3->der != NULL)
				cout << aux3->dato << endl;
			Padres(aux3->izq);
			Padres(aux3->der);
		}
	}
}

void Hojas(nodo *aux3)
{
	if (!Vacio())
	{
		if (aux3 != NULL)
		{
			if (aux3->izq == NULL && aux3->der == NULL)
				cout << aux3->dato << endl;
			Hojas(aux3->izq);
			Hojas(aux3->der);
		}
	}
	else
		cout<<"Error: Arbol vacio"<<endl;
}

void Tamano()
{
	cerr << "No hecho\n";
}

void Orden()
{
	cout << "El arbol es de orden: " << orden << endl;
}

void Altura(Nodo *aux3, int altura)
{
	if (!Vacio())
	{
		if (aux3!=NULL)
		{
			if (aux3->izq!=NULL)
			Altura(aux3->izq, altura+1);
			else if(aux3->der!=NULL)
			Altura(aux3->der, altura+1);
			else 
				cout<<"Altura: "<<altura<<endl;
		}
	}
	else
		cout<<"Error: Arbol vacio"<<endl;
	
}

void Nivel()
{
	int nodo;
	nivel = 0;
	if(!Vacio())
	{
	cout<<"Escribe el nodo"<<endl;
	cin>>nodo;
	if(!Buscar(nodo))
	cout<<"Nodo no encontrado"<<endl;
	else
	cout<<"Nivel: "<<nivel<<endl;
	}
	else
		cout<<"Error: Arbol vacio"<<endl;
}

bool Buscar(int x)
{
	aux = raiz;
	Busca:
	if (aux != NULL)
	{
		if (x == aux->dato)
		{
			nivel++;
			return 1;
		}
		if (x < aux->dato)
		{
			nivel++;
			aux = aux->izq;
			goto Busca;
		}
		else
		{
			nivel++;
			aux = aux->der;
			goto Busca;
		}
	}
	else
		return 0;
}

bool Vacio()
{
	if (raiz == NULL)
		return 1;
	return 0;
}