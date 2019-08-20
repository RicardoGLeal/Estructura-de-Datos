#include "stdafx.h"
#include <iostream>
using namespace std;
int checkletter(int dato);
bool cac;
float datof;
class Cola
{
public:
	int datos[20];
	int tope;
	int tofind;
	void inicializar();
	void encolar();
	void desencolar();
	bool vacia();
	bool llena();
	void imprime();
	void limpia();
	void busca();
};

void Cola::inicializar()
{
	vacia();
	tope =-1;
}

void Cola::encolar()
{
	if (llena() == true)
	{
		cout<<"Error, la Cola esta llena"<<endl;
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
		} while (cac == true);
		}
}

void Cola::desencolar()
{
	int as;
	if (vacia()==false)
	{
		for (int i = 1; i <= tope; i++)
		{		
			datos[i-1]=datos[i];
		}
		tope--;
		cout<<"!desencolar!"<<endl;
	}
	else
		cout<<"Error, la Cola esta vacia"<<endl;
	system("pause");
}

bool Cola::vacia()
{
	if (tope==-1)
		return 1;
	else
		return 0;
}

bool Cola::llena()
{
	if (tope==19)
		return 1;
	else
		return 0;
}

void Cola::imprime()
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

void Cola::limpia()
{
	if (vacia()==false)
		inicializar();
	else
		cout<<"Error, no hay nada que limpiar"<<endl;
	system("pause");
}

void Cola::busca()
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
	Cola C1;
	C1.inicializar();
	do
	{
		do
		{
			system("cls");
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
			system("cls");
			C1.encolar();
			break;
		case 2:
			C1.desencolar();
			break;
		case 3:
			C1.imprime();
			break;	
		case 4:
			C1.limpia();
			break;
		case 5:
			C1.busca();
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