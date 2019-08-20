#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
using namespace std;
int checkletter(int dato);
int _tmain(int argc, _TCHAR* argv[])
{
	int ndatos, refmayor, *datos, indice;
	bool mistake = false;
	float dato;
	int again;
	do
	{
		indice=0;
		do
		{
			cout<<"Ordenamiento Shell"<<endl;
			cout<<"Escribe el numero de datos a ingresar, debe ser entre 1 y 20"<<endl;
			do
			{
				cin>>dato;
				mistake = checkletter(dato);
			} while (mistake==true);
			ndatos = (int)dato;
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
		cout<<"A:";
		for (int i = 0; i < ndatos; i++)
		{
			cout << setw(5);
			cout<<datos[i];
		}
		cout<<endl<<endl;
		int n;
		int marcador=datos[0];
		int saveri, cas;
		for (n = ndatos/2; n >= 1; n/=2)
		{
			for (cas = 0; cas < n; cas++)
			{
				for (i=cas; i < ndatos; i+=n)
				{
					saveri = i;
					marcador = datos[i];
					a = i-n; 

					if (a>=0)
					{
						if (datos[i]<datos[a])
						{
							do
							{
								mayor = datos[a];
								datos[a]=datos[i];
								datos[i]=mayor;
								i-=n;
								a = i;
								a-=n;
							} while (marcador<datos[a]&&a>=0);
							i= saveri;
							a-=n;
						}
						else
						{
							marcador = datos[i+1];
							a-=n;
						}
					}
				}
			}
			indice++;
			cout<<indice<<":";
			for (int i = 0; i < ndatos; i++)
			{
				cout << setw(5);
				cout<<datos[i];
			}
			cout << setw(5);
			cout<<"n: "<<n<<endl;
		}
		cout<<"Deseas ordenar otro arreglo? 1:SI  2:NO"<<endl;
		do
		{
			cin>>again;
			mistake = checkletter(again);
		} while (mistake == true);
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