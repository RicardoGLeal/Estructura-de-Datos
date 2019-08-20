#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
float dato;
int checkletter(int dato);
void Busqueda(int *a, int ndatos);
int _tmain(int argc, _TCHAR* argv[])
{
	int *datos;
	bool mistake = false;
	int refmayor, ndatos;
	int repbusq, repall;
	do
	{
		do
		{
			cout<<"Búsqueda Secuencial"<<endl;
			cout<<"Escribe el numero de datos a ingresar, debe ser entre 1 y 20"<<endl;
			do
			{
				cin>>dato;
				mistake = checkletter(dato);
			} while (mistake==true);
			ndatos= (int)dato;
			if ((ndatos<2)||(ndatos>20))
				cout<<"El numero de datos debe de ser mayor que 2 y menor que 20"<<endl;
		} while ((ndatos<2)||(ndatos>20));

		datos = new int[ndatos];
		int i, a, z, mayor;

		cout<<"Introduce los datos, deben ser enteros"<<endl;
		for (i = 0; i< ndatos; i++)
		{
			do
			{
				mistake = false;
				cout<<"Dato "<<i+1<<endl;
				cin>>dato;
				mistake = checkletter(dato);
				datos[i] = (int)dato;
				if (mistake == false)
				{
					datos[i] = (int)dato;
					for (z = i-1; z >= 0; z--)
					{
						if (datos[i]==datos[z])
						{
							cout<<"El dato ingresado ya habia sido introducido..."<<endl<<"Repite"<<endl;
							mistake = true;
							break;
						}
					}
				}
			} while (mistake == true);
		}
		cout << setw(2);
		cout<<"A:";
		for (int i = 0; i < ndatos; i++)
		{
			cout << setw(5);
			cout<<datos[i];
		}
		cout<<endl;
		do
		{
			Busqueda(datos, ndatos);
			cout<<"Deseas encontrar otro numero? 1:Si 2:No"<<endl;
			cin>>repbusq;
		} while (repbusq==1);


		cout<<"Deseas ingresar otro arreglo? 1:Si 2:No"<<endl;
		cin>>repall;
	} while (repall == 1);


	system("pause");
	return 0;
}
void Busqueda(int *a, int ndatos)
{
	int number;
	cout<<"Escribe numero a buscar"<<endl;
	cin>>number;
	bool encontrado = false;
	for (int i = 0; i < ndatos; i++)
	{
		if (a[i] == number)
		{
			cout<<"Se encontro el numero: "<<number<<" en la posicion "<<i<<endl;
			encontrado = true;
		}
	}
	if (encontrado == false)
		cout<<"El numero ingresado no se encuentra en el arreglo"<<endl;
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