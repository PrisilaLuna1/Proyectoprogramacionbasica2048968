#include <iostream>
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>

using namespace std;

struct articulos
{
	int item;
	char nombre[50], genero[50], clasificacion[50], consola[50];
	string descripcion;
	float precioT, precio;
};

int main()
{
	articulos menu[3];
	int opcion;

	do
	{
		printf("\t Menu de opciones \n");
		printf("1. Alta\n");
		printf("2. Modificacion\n");
		printf("3. Baja\n");
		printf("4. Lista\n");
		printf("5. Limpiar pantalla\n");
		printf("6. Salir\n");
		scanf_s("%d", &opcion);

		switch (opcion)
		{
		case 1: //Alta
			for (int i = 0; i < 3; i++)
			{
				printf("Ingrese el numero de item\n");
				scanf_s("%d", &menu[i].item);
				cin.ignore();
				printf("Nombre del articulo\n");
				gets_s(menu[i].nombre);
				printf("Agregue una descripcion breve\n");
				getline(cin, menu[i].descripcion);
				printf("Ingrese el genero del juego\n");
				gets_s(menu[i].genero);
				printf("Ingrese la clasificacion\n");
				gets_s(menu[i].clasificacion);
				printf("Ingrese la consola\n");
				gets_s(menu[i].consola);

				printf("Ingrese el precio unitario\n");
				scanf_s("%f", &menu[i].precio);
				menu[i].precioT = menu[i].precio + (menu[i].precio * 16) / 100;
				printf("\n");
			}
			break;

		case 2:
			break;

		case 3:
			break;

		case 4: //Lista
			for (int i = 0; i < 3; i++)
			{
				printf("Numero de item: %d \n", menu[i].item);
				printf("Nombre del articulo: %s \n", menu[i].nombre);
				printf("Descripicion: %s \n", menu[i].descripcion.c_str());
				printf("Genero: %s \n", menu[i].genero);
				printf("Clasificacion: %s \n", menu[i].clasificacion);
				printf("Consola: %s \n", menu[i].consola);
				printf("Precio unitario: %f \n", menu[i].precio);
				printf("Precio total: %f \n \n", menu[i].precioT);
			}
			break;

		case 5: //Limpiar pantalla
			system("cls");
			break;

		case 6: //salir
			exit(1);
			break;

		default: //opciones no existentes
			cout << "opcion invalida" << endl;
			break;
		}
	} while (opcion != 6);

	system("pause");
}
