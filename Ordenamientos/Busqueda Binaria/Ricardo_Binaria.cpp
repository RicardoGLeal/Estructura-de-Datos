#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
int checkletter(int dato);
void Binsearch(int datos[], int ndatos);
using namespace std;
float dato;
int _tmain(int argc, _TCHAR* argv[])
{
	int ndatos;
	int repbusq, repall;
	bool mistake = false;
	int	refmayor;
	int *datos;
	do
	{
		do
		{
			cout<<"Busqueda Binaria"<<endl;
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
				for (z = i-1; z >= 0; z--)
				{
					if (datos[i]==datos[z])
					{
						cout<<"El dato ingresado ya habia introducido..."<<endl<<"Repite"<<endl;
						mistake = true;
						break;
					}
				}
			} while (mistake == true);
		}
		cout<<"     ";
		for (int i = 0; i < ndatos; i++)
			{
				cout << setw(5);
				cout<<datos[i];
			}
		cout<<endl;

		for (a = 1; a < ndatos; a++)
		{
			for (i = 0; i < ndatos-1; i++)
			{
				if (datos[i]>datos[i+1])
				{
					refmayor = datos[i];
					datos[i]=datos[i+1];
					datos[i+1]=refmayor;
				}
			}
			if(a!=0)
				cout<<a<<":   ";

			for (int i = 0; i < ndatos; i++)
			{
				cout << setw(5);
				cout<<datos[i];
			}
			cout<<endl;
		}
		do
		{
			Binsearch(datos, ndatos);
			cout<<"Deseas encontrar otro numero? 1:Si 2:No"<<endl;
			cin>>repbusq;
		} while (repbusq==1);


		cout<<"Deseas ingresar otro arreglo? 1:Si 2:No"<<endl;
		cin>>repall;
	} while (repall == 1);
	system("pause");
	return 0;
}
void Binsearch(int datos[], int ndatos)
{
	int less = 0;
	int high = ndatos;
	int mitad;
	int unknown;
	bool found = false;
	cout<<"Escribe el numero a buscar"<<endl;
	cin>>unknown;
	while ((less+1) != high)
	{
		mitad = (less + high)/2;
		if (datos[mitad] == unknown)
		{
			found = true;
			break;
		}
		if(datos[mitad]>unknown)
		{
			high = mitad;
			mitad = (less + high)/2;
		}
		if (datos[mitad]<unknown)
		{
			less = mitad;
			mitad = (less + high)/2;
		}
	}
	if(unknown==datos[0])
	cout<<"Numero "<<unknown<<" encontrado en la posicion 0"<<endl;
	else
	{
	if(found == false)
		cout<<"EL numero "<<unknown<<" no ha sido encontrado"<<endl;
	else if(found == true)
		cout<<"Numero "<<unknown<<" encontrado en la posicion "<<mitad<<endl;
	}
	
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