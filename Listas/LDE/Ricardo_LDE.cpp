#include "stdafx.h"
#include <iostream>
using namespace std;
int checkletter(int dato);
int datof;
bool cac;

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
	void elimina();
	void limpia();
	void imprime();
	bool buscar(int &x);
	int x;
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
	bool completed = false;
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
		lista->sig=NULL;
		lista->ant=NULL;
	}
	else
	{
		aux = new Nodo;
		aux->dato=x;
		aux->ant = NULL;
		aux->sig = NULL;
		if (x<lista->dato)
		{
			aux->sig = lista;
			aux->ant = NULL;
			lista->ant = aux;
			lista = aux;
		}
		else
		{
			aux2 = lista;
			while (aux2->sig!=NULL && aux2->sig->dato<x)
			aux2 = aux2->sig;
			if (aux2->sig == NULL)
			{
				aux2->sig = aux;
				aux->ant = aux2;
			}
			else
			{
			aux->sig = aux2->sig;
			aux2-> sig = aux;
			aux->sig->ant = aux;
			aux->ant=aux2;
			}
		}
	}
}

void Lista::elimina()
{
	if(vacia())
		cout<<"No hay nada en la lista"<<endl;
	else
	{
		cout<<"Escribe el numero a buscar"<<endl;
		cin>>x;
		if(buscar(x)==false)//CASO 1: NO SE ENCUENTRA
			cout<<"No se encontro el elemento"<<endl;
		else
			if (lista->sig==NULL)// CASO 2: SE BUSCA LISTA Y SOLO HAY LISTA
			{
				delete lista;
				inicializar();
			}
			else
				if (lista->dato==x)// CASO 2: SE BUSCA LISTA Y HAY MAS ELEMENTOS
				{
					aux= lista->sig;
					delete lista;
					lista = aux;
					lista->ant = NULL;
				}
				else
				{
					aux=lista;
					while (aux->dato!=x)
						aux = aux->sig;
					if(aux->sig==NULL)
					{
						aux->ant->sig=NULL;
						delete aux;
					}
					else
					{
						aux->ant->sig = aux->sig;
						aux->sig->ant = aux->ant;
					}
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
		while(aux!=NULL)
		{
			if(aux->dato==x)
				return 1;
			aux = aux->sig;
		}
		return 0;
	}

}
void Lista::limpia()
{
	aux2=lista;
	if (!vacia())
	{
		while (aux2->sig!=NULL)
			aux2 = aux2->sig;

		while (lista!=aux2)
		{
			aux=lista;
			if (aux->sig==NULL)
				lista=NULL;
			else
			{
				while (aux->sig!=aux2)
					aux=aux->sig;
				aux->sig = NULL;
				delete aux2;
				aux2 = aux;
			}
		}
		delete lista;
		inicializar();
		cout<<"Lista limpiada"<<endl;
	}
	else
		cout<<"Nada que limpiar.."<<endl;
}
void Lista::imprime()
{
	if (vacia())
		cout<<"La lista esta vacia"<<endl;
	else
	{
		cout<<"Lista:"<<endl;
		aux=lista;
		while (aux!=NULL)
		{
			cout<<aux->dato<<"   ";
			aux= aux->sig;
		}
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
			L1.elimina();
			cout<<"Dato eliminado"<<endl;
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