#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
int checkletter(int dato);
void Quick(int ndatos, int datos[], int limIzq, int limDer, int total);
int indice=1;
int _tmain(int argc, _TCHAR* argv[])
{
	int again = 0;
	int ndatos, refmayor, *datos;
	float dato;
	do
	{
		indice = 1;
		do
		{
			cout<<"Ordenamiento Quick Sort"<<endl;
			cout<<"Escribe el numero de datos a ingresar, debe ser entre 2 y 20"<<endl;
			cin>>dato;
			checkletter(dato);
			ndatos = (int)dato;
			if ((ndatos<2)||(ndatos>20))
				cout<<"El numero de datos debe de ser mayor que 2 y menor que 20"<<endl;
		} while ((ndatos<2)||(ndatos>20));

		datos = new int[ndatos];
		int i, z;
		bool mistake = false;
		cout<<"Introduce los datos, deben ser enteros"<<endl;
		for (i = 0; i< ndatos; i++)
		{
			do
			{
				mistake = false;
				cout<<"Dato "<<i+1<<endl;
				cin>>dato;
				mistake = checkletter(dato);
				if (mistake == true)
					cout<<"Solo puedes ingresar numeros..."<<endl<<"Repite"<<endl;
				else
				{
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
				}
			} while (mistake == true);
		}
		cout << setw(2);
		cout<<" A:";
		for (int i = 0; i < ndatos; i++)
		{
			cout << setw(5);
			cout<<datos[i];
		}
		cout<<endl<<endl;
		Quick(ndatos, datos, 0, ndatos - 1, 0);
		cout<<"Deseas continuar? 1:Si   2:No"<<endl;
		cin>>again;
	} while (again == 1);

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
void Quick(int ndatos, int datos[], int limIzq, int limDer, int total)
{
	int tot, temp, der, izq, centro;
	tot = total;
	izq = limIzq;
	der = limDer;
	centro = datos[(izq + der) / 2];
	do
	{
		while (datos[izq] < centro && izq < limDer)
			izq++;
		while (centro<datos[der] && der>limIzq)
			der--;
		if (izq <= der)
		{
			temp = datos[izq];
			datos[izq] = datos[der];
			datos[der] = temp;
			izq++;
			der--;
		}
	} while (izq <= der);

	cout << setw(2);
	cout<<indice<<":";
	for (int i = 0; i < ndatos; i++)
	{
		cout << setw(5);
		cout << datos[i];
	}
	cout <<"   Pibote: "<<centro<< endl;
	indice++;
	tot++;

	if (limIzq < der)
		Quick(ndatos, datos, limIzq, der, tot);
	if (limDer > izq)
		Quick(ndatos, datos, izq, limDer, tot);
}