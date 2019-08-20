#include "stdafx.h"
#include <iostream>
using namespace std;
int checkletter(int dato);

float datof;
bool busca = false;
bool encolari = 1;
float numero;
bool cac;
class Cola
{
public:
	int tofind;
	void inicializar();
	void encolar();
	void desencolar();
	bool vacia();
	void imprime();
	void limpia();
	void buscar();
};
struct nodo
{
	int dato;
	nodo *sig;
}*cola, *aux, *frente;

void Cola::inicializar()
{
	cola=NULL;
}

void Cola::encolar()
{
	int x=0;
	do
	{
		cout<<"Introduce un numero"<<endl;
		cin>>datof;
		cac = checkletter(x);
		if (cac == false)
			x = (int)datof;
	} while (cac == true);
	if (vacia())
	{
		cola = new nodo;
		cola->dato = x;
		cola->sig = NULL;
		frente=cola;
		cout<<"Elemento "<<x<<" insertado en la cola"<<endl;
	}
	else
	{
		aux= new nodo;
		aux->dato = x;
		aux->sig = NULL;
		frente->sig = aux;
		frente=aux;
		cout<<"Elemento "<<x<<" insertado en la cola"<<endl;
	}
}

void Cola::desencolar()
{
	if (vacia())
		cout<<"Error, la cola esta vacia"<<endl;
	else
	{
		if (cola==frente)
		{
			delete frente;
			inicializar();
		}
		else
		{
			aux=cola->sig;
			delete cola;
			cola=aux;
		}
		cout<<"Elemento eliminado"<<endl;
	}
}

bool Cola::vacia()
{
	if (cola==NULL)
		return true;
	else
		return false;
}

void Cola::imprime()
{
	if (vacia())
		cout<<"No hay nada en la cola"<<endl;
	else 
	{
		cout<<"Cola:"<<endl;
		aux=cola;
		do
		{
			cout<<aux->dato<<"   ";
			aux = aux->sig;
		}
		while(aux!=NULL);
		cout<<endl;
	}
}

void Cola::limpia()
{
	if (vacia()==false)
	{
		while(cola!=frente)
			desencolar();
		delete frente;
		inicializar();
	}
	else
		cout<<"Error, no hay nada que limpiar"<<endl;
}

void Cola::buscar()
{
	busca = false;
	if (vacia())
		cout << "No hay nada en la cola" << endl;
	else
	{
		encolari = 1;
		cout << "Introduzca el valor entero (ya sea positivo o negativo) a buscar:" << endl;
		while (!(cin >> numero))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Porfavor que sea una cantidad entera:" << endl;
		}
		if (numero == (int)numero)
		{
			if (numero >= -100000 && numero <= 10000000)
				encolari = 0;
			else
				encolari = 1;
		}
		else
			encolari = 1;
		aux = cola;
		while (aux!=NULL)
		{
			if (aux->dato==numero)
				busca = true;
			aux = aux->sig;
		}
		if (busca == true)
			cout << "Tu numero si esta en la cola" << endl;
		else
			cout << "Tu numero no esta en la cola" << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Cola C1;
	int option;
	do
	{
		do
		{
			cout<<"Introduce una opcion"<<endl;
			cout<<"[1]: Encolar"<<endl<<"[2]: Desencolar"<<endl<<"[3]: Imprime"<<endl<<"[4]: Limpia"<<endl<<"[5]: Buscar"<<endl<<"[6]: Salir"<<endl;
			cin>>datof;
			cac = checkletter(datof);
			if (cac == false)
				option = (int)datof;
		} while (cac == true);
		switch (option)
		{
		case 1:
			C1.encolar();
			system("pause");
			system("cls");
			break;
		case 2:
			C1.desencolar();
			system("pause");
			system("cls");
			break;
		case 3:
			C1.imprime();
			system("pause");
			system("cls");
			break;	
		case 4:
			C1.limpia();
			system("pause");
			system("cls");
			break;
		case 5:
			C1.buscar();
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
		system("pause");
	}
	return mistake;
}