#include "stdafx.h"
#include <iostream>
using namespace std;
int checkletter(int dato);
bool cac;
float datof;
bool busca = false;
bool pushi = 1;
float numero;

class Pila
{
public:
	int tofind;
	void inicializar();
	void push();
	void pop();
	bool vacia();
	void imprime();
	void limpia();
	void buscar();
};
struct nodo
{
	int dato;
	nodo *sig;
}*pila, *aux, *tope;

void Pila::inicializar()
{
	pila=NULL;
}

void Pila::push()
{
	int x=0;
	do
	{
		cout<<"Introduce un numero"<<endl;
		cin>>datof;
		cac = checkletter(datof);
		if (cac == false)
			x = (int)datof;
	} while (cac == true);
	if (vacia())
	{
		pila = new nodo;
		pila->dato = x;
		pila->sig = NULL;
		tope=pila;
		cout<<"Elemento "<<x<<" insertado en la pila"<<endl;
	}
	else
	{
		aux= new nodo;
		aux->dato = x;
		aux->sig = NULL;
		tope->sig = aux;
		tope=aux;
		cout<<"Elemento "<<x<<" insertado en la pila"<<endl;
	}
}

void Pila::pop()
{
	if (vacia())
		cout<<"Error, la pila esta vacia"<<endl;
	else
	{
		aux=pila;
		if (aux->sig==NULL)
			pila=NULL;
		else
		{
		while (aux->sig!=tope)
			aux=aux->sig;
		aux->sig = NULL;
		delete tope;
		tope = aux;
		}
		cout<<"Elemento eliminado"<<endl;
	}
}

bool Pila::vacia()
{
	if (pila==NULL)
		return true;
	else
		return false;
}

void Pila::imprime()
{
	if (vacia())
		cout<<"No hay nada en la pila"<<endl;
	else 
	{
		cout<<"Pila:"<<endl;
		aux=pila;
		do
		{
			cout<<aux->dato<<"   ";
			aux = aux->sig;
		}
		while(aux!=NULL);
		cout<<endl;
	}
}

void Pila::limpia()
{
	if (vacia()==false)
	{
		aux=tope;
		if(pila!=tope)
		{
		do
		pop();
		while (aux!=pila);
		}
			pop();
		cout<<"Pila limpiada exitosamente"<<endl;
	}
	else
		cout<<"Error, no hay nada que limpiar"<<endl;
}

void Pila::buscar()
{
	busca = false;
	if (vacia())
		cout << "No hay nada en la pila" << endl;
	else
	{
		cout << "Introduzca el valor entero a buscar:" << endl;
		while (!(cin >> numero))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Debe de ser una cantidad entera:" << endl;
		}

		aux = pila;
		while (aux!=NULL)
		{
			if (aux->dato==numero)
				busca = true;
			aux = aux->sig;
		}
		if (busca == true)
			cout << "Tu numero si esta en la pila" << endl;
		else
			cout << "Tu numero no esta en la pila" << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Pila P1;
	P1.inicializar();
	int option;
	do
	{
		do
		{
			cout<<"Introduce una opcion"<<endl;
			cout<<"[1]: Push"<<endl<<"[2]: Pop"<<endl<<"[3]: Imprime"<<endl<<"[4]: Limpia"<<endl<<"[5]: Buscar"<<endl<<"[6]: Salir"<<endl;
			cin>>datof;
			cac = checkletter(datof);
			if (cac == false)
				option = (int)datof;
		} while (cac == true);
		switch (option)
		{
		case 1:
			P1.push();
			system("pause");
			system("cls");
			break;
		case 2:
			P1.pop();
			system("pause");
			system("cls");
			break;
		case 3:
			P1.imprime();
			system("pause");
			system("cls");
			break;	
		case 4:
			P1.limpia();
			system("pause");
			system("cls");
			break;
		case 5:
			P1.buscar();
			system("pause");
			system("cls");
			break;
		case 6:
			break;
		}
	} while (option!= 6);

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
	}
	return mistake;
}