#include "stdafx.h"
#include <iostream>
using namespace std;
int checkletter(int dato);
int datof;
bool cac;
int numero;
int x;
struct Nodo
{
	int dato;
	Nodo *sig;
	Nodo *ant;
}*lista, *aux, *aux2;

class Lista
{
public:
	void inicializar();
	bool vacia();
	void ingresa();
	void elimina(int x);
	void limpia();
	void imprime();
	bool buscar(int &x);
};

void Lista::inicializar()
{
	lista=NULL;
}

bool Lista::vacia()
{
	if(lista==NULL)
		return true;
	else
		return false;
}

void Lista::ingresa()
{
	do
	{
		cout<<"Introduce un numero"<<endl;
		cin>>datof;
		cac = checkletter(x);
		if (cac == false)
			x = (int)datof;
	} while (cac == true);
	if(vacia())
	{
		lista= new Nodo;
		lista->dato = x;
		lista->ant=lista;
		lista->sig=lista;
	}
	else if(x<lista->dato)
	{
		aux = new Nodo;
		aux->dato=x;
		aux->ant = lista->ant;
		aux->ant->sig=aux;
		aux->sig = lista;
		lista->ant=aux;
		lista=aux;
	}
	else
	{
		aux = new Nodo;
		aux->dato = x;
		aux2 = lista;
		while (aux2->sig->dato<x && aux2->sig!=lista)
			aux2 = aux2->sig;
		aux->sig = aux2->sig;
		aux2->sig = aux;
		aux->ant = aux2;
		aux->sig->ant = aux;
	}
}


void Lista::elimina(int x)
{
	if(vacia())
		cout<<"No hay nada en la lista"<<endl;
	else
	{
		if(buscar(x)==false)//CASO 1: NO SE ENCUENTRA
			cout<<"No se encontro el elemento"<<endl;
		else
			if (lista->sig==lista)// CASO 2: SE BUSCA LISTA Y SOLO HAY LISTA
			{
				delete lista;
				inicializar();
				cout<<"Dato eliminado"<<endl;
			}
			else
				if (lista->dato==x)// CASO 2: SE BUSCA LISTA Y HAY MAS ELEMENTOS
				{
					aux= lista->sig;
					aux->ant = lista->ant;
					lista->ant->sig = aux;
					delete lista;
					lista = aux;
				}
				else
				{
					aux=lista->sig;
					while (aux->dato!=x && aux->sig!=lista)
						aux = aux->sig;
					aux->ant->sig=aux->sig;
					aux->sig->ant = aux->ant;
					delete aux;
					cout<<"Dato eliminado"<<endl;
				}		
	}
}
bool Lista::buscar(int &x)
{
	if (vacia())
		cout<<"No hay nada en la lista"<<endl;
	else
	{
		aux=lista;
		do
		{
			if(aux->dato==x)
				return 1;
			aux = aux->sig;
		}while(aux!=lista);
		return 0;
	}

}
void Lista::limpia()
{
	if (vacia())
		cout<<"No hay nada que limpiar"<<endl;
	else
	{
		while(!vacia())
		{
			numero = lista->dato;
			elimina(numero);
		}
		inicializar();
		cout<<"Lista limpiada"<<endl;
	}
}
void Lista::imprime()
{
	if (vacia())
		cout<<"La lista esta vacia"<<endl;
	else
	{
		cout<<"Lista:"<<endl;
		aux=lista;
		do
		{
			cout<<aux->dato<<"  ";
			aux = aux->sig;
		} while (aux!=lista);
		cout<<endl;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	Lista L1;
	int option;
	do
	{
		do
		{
			cout<<"Lista Circular Doble"<<endl;
			cout<<"Introduce una opcion"<<endl;
			cout<<"[1]: Ingresa"<<endl<<"[2]: Elimina"<<endl<<"[3]: Imprime"<<endl<<"[4]: Limpia"<<endl<<"[5]: Salir"<<endl;
			cin>>datof;
			cac = checkletter(datof);
			if (cac == false)
				option = (int)datof;
		} while (cac == true);
		switch (option)
		{
		case 1:
			L1.ingresa();
			cout<<"Dato ingresado en la lista"<<endl;
			system("pause");
			system("cls");
			break;
		case 2:
			if (L1.vacia())
			cout<<"No hay nada que limpiar"<<endl;
			else{
			cout<<"Escribe el numero a buscar"<<endl;
			cin>>x;
			L1.elimina(x);}
			system("pause");
			system("cls");
			break;
		case 3:
			L1.imprime();
			system("pause");
			system("cls");
			break;	
		case 4:
			L1.limpia();
			system("pause");
			system("cls");
			break;
		case 5:
			break;
		}
	} while (option!= 5);

	system("pause");
	return 0;
	system("pause");
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