#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int ndatos;
	int	refmayor;
	int *datos;
	do
	{
		cout<<"Ordenamiento Burbuja"<<endl;
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
	cout<<"     ";
	for (int i = 0; i < ndatos; i++)
	{
		cout<<datos[i]<<" ";
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
			cout<<datos[i]<<" ";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}