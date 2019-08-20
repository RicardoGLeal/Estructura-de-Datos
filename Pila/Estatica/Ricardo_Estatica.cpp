#include "stdafx.h"
#include <iostream>
using namespace std;
int checkletter(int dato);
bool cac;
float datof;
class Pila
{
public:
	int datos[20];
	int tope;
	int tofind;
	void inicializar();
	void push();
	void pop();
	bool vacia();
	bool llena();
	void imprime();
	void limpia();
	void busca();
};

void Pila::inicializar()
{
	vacia();
	tope =-1;
}

void Pila::push()
{
	if (llena() == true)
	{
		cout<<"Error, la pila esta llena"<<endl;
		system("pause");
	}
	else
	{
		tope++;
		cac = false;

		do
		{
			cout<<"Entroduce el elemento"<<endl;
			cin>>datof;
			cac = checkletter(datof);
			if (cac == false)
				datos[tope] = (int)datof;
			system("pause");
		} while (cac == true);
		}
}

void Pila::pop()
{
	if (vacia()==false)
	{
		tope--;
		cout<<"!Pop!"<<endl;
	}
	else
		cout<<"Error, la pila esta vacia"<<endl;
	system("pause");
}

bool Pila::vacia()
{
	if (tope==-1)
		return 1;
	else
		return 0;
}

bool Pila::llena()
{
	if (tope==19)
		return 1;
	else
		return 0;
}

void Pila::imprime()
{
	vacia();
	if (vacia() == false)
	{
		for (int i = 0; i <= tope; i++)
			cout<<"["<<i<<"]: "<<datos[i]<<endl; 
	}
	else 
		cout<<"Error, no hay nada que imprimir"<<endl;
	system("pause");
}

void Pila::limpia()
{
	if (vacia()==false)
		inicializar();
	else
		cout<<"Error, no hay nada que limpiar"<<endl;
	system("pause");
}

void Pila::busca()
{
	bool encontrado = false;
	if(vacia()==false)
	{
		do
		{
			cout<<"Introduce dato a buscar"<<endl;
			cin>>datof;
			cac = checkletter(datof);
			if (cac == false)
				tofind = (int)datof;
		} while (cac == true);
		for (int i = 0; i <= tope; i++)
		{
			if (tofind==datos[i])
			{
				encontrado= true;
				cout<<"Dato "<<tofind<<" encontrado en la posicion "<<i<<endl;
				break;
			}
		}
		if (encontrado==false)
			cout<<"Dato no encontrado"<<endl;
	}
	else
		cout<<"Error, no hay nada que buscar"<<endl;
	system("pause");
}

int _tmain(int argc, _TCHAR* argv[])
{
	int option;
	Pila P1;
	P1.inicializar();
	do
	{
		do
		{
			system("cls");
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
			break;
		case 2:
			P1.pop();
			break;
		case 3:
			P1.imprime();
			break;	
		case 4:
			P1.limpia();
			break;
		case 5:
			P1.busca();
			break;
		case 6:
			break;
		default:
			cout<<"Entrada incorrecta"<<endl;
			system("pause");
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