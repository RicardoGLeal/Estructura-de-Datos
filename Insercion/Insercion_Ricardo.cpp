#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
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

	int marcador=datos[0];
	int saveri;
	for (i = 0; i < ndatos; i++)
	{
		saveri = i;
		marcador = datos[i];
		a = i-1; 
		if(a>=0)
		{
			if (datos[i]<datos[a])
			{
				do
				{
					mayor = datos[a];
					datos[a]=datos[i];
					datos[i]=mayor;
					i--;
					a = i-1;
				} while (marcador<datos[a]);
				i= saveri;
			}
			else
				marcador = datos[i+1];
		}
		cout<<i+1<<":   ";
		for (int i = 0; i < ndatos; i++)
			cout<<datos[i]<<" ";
		cout<<endl;
	}
	system("pause");
	return 0;
}