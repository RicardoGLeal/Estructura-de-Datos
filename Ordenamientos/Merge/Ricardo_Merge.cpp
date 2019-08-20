#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
int checkletter(int dato);
void DividirM(int *a, int izq, int der);
void Merge(int *a, int izq, int der, int mitad);
void Printarray(int arre[], int inicio, int end);
int *datos,*mismoelemento,ndatos,m,indice = 0;
float dato;
int _tmain(int argc, _TCHAR* argv[])
{
	int refmayor, again;
	bool mistake = false;
	do
	{
		indice = 0;
		do
		{
			cout<<"Ordenamiento Merge"<<endl;
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
		Printarray(datos, 0, ndatos);
		cout<<endl<<endl;
		DividirM(datos, 0, ndatos-1);
		cout<<"Deseas ordenar otro arreglo? 1:SI  2:NO"<<endl;
		do
		{
			cin>>again;
			mistake = checkletter(again);
		} while (mistake == true);
	} while (again==1);

	system("pause");
	return 0;
}
void DividirM(int *a, int izq, int der)
{
	int mitad;
	if (izq < der)
	{
		mitad = (izq + der) / 2;
		DividirM(a, izq, mitad);
		DividirM(a, mitad + 1, der);
		Merge(a, izq, der, mitad);
		Printarray(datos,0,ndatos);
		cout << endl;
	}
}
void Merge(int *a, int izq, int der, int mitad)
{
	int i, j, k;
	mismoelemento=new int[der - izq + 1];
	i = izq;
	k = 0;
	j = mitad + 1;
	while (i <= mitad && j <= der)	{
		if (a[i] < a[j]){
			mismoelemento[k] = a[i];
			k++;
			i++;
		}
		else{
			mismoelemento[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mitad){
		mismoelemento[k] = a[i];
		k++;
		i++;
	}
	while (j <= der){
		mismoelemento[k] = a[j];
		k++;
		j++;
	}
	for (i = izq; i <= der; i++) {
		a[i] = mismoelemento[i - izq];
	}
}
void Printarray(int arre[], int inicio, int end)
{
	if (indice > 0)
		cout<<indice<<":";
	for (int i = inicio; i < end; i++)
	{
		cout << setw(5);
		cout<<arre[i];
	}
	indice++;
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