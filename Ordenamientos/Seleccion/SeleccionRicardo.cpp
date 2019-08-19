#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int ndatos, refmayor, *datos;
	do
	{
		cout<<"Ordenamiento Insersion"<<endl;
		cout<<"Escribe el numero de datos a ingresar, debe ser entre 1 y 20"<<endl;
		cin>>ndatos;
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
			cout<<"Dato "<<i+1<<endl;
			cin>>datos[i];
			for (z = i-1; z >= 0; z--)
			{
				if (datos[i]==datos[z])
				{
					cout<<"El dato ingresado ya habia introducido..."<<endl<<"Repite"<<endl;
					break;
				}
			}
		} while (datos[i]==datos[z]);
	}
	cout<<"A:";
	for (int i = 0; i < ndatos; i++)
		{
			cout << setw(5);
			cout<<datos[i];
		}
		cout<<endl<<endl;


	int menor=datos[0], posm;
	for (i = 0; i < ndatos; i++)
	{
		menor=datos[i];
		posm=i;
		for (a = i+1; a < ndatos; a++)
		{
			if (datos[a]<menor)
			{
				menor= datos[a];
				posm = a;
			}
			if (a==ndatos-1)
			{
				datos[posm]=datos[i];
				datos[i]=menor;
			}
		}
		cout<<i+1<<":";
		for (int i = 0; i < ndatos; i++)
		{
			cout << setw(5);
			cout<<datos[i];
		}
		cout<<endl;
	}

	system("pause");
	return 0;
}