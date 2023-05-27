#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <conio.h>
#include <Windows.h>

using namespace std;

struct articulos
{
	int item{}, anio{};
	char nombre[50]{}, carac[50]{};
	string descripcion, status,genero, clasificacion, consola;
	float precioT{}, precio{};
};
articulos *menu; //puntero
int nalta, con, gen, clas;
HANDLE Conh = GetStdHandle(STD_OUTPUT_HANDLE); //color

void Alta();
void Lista(); 
void Eliminar();
void Modificar();
void Archivos();

int main()
{
	system("color F1"); //color
	int opcion;
		printf("----------------------------------\n");
		printf("\t Men%c de opci%cnes \n", 163, 1);
		printf("----------------------------------\n");
		printf("1. Alta\n");
		printf("2. Modificaci%cn\n", 162);
		printf("3. Baja\n");
		printf("4. Lista\n");
		printf("5. Limpiar pantalla\n");
		printf("6. Archivo\n");
		printf("7. Salir\n");
		printf("----------------------------------\n");
		scanf_s("%d", &opcion);

		switch (opcion)
		{
		case 1: //Alta
			Alta();
			return main();
			break;

		case 2: //Modificar
			Modificar();
			return main();
			break;

		case 3: //Baja
			Eliminar();
			return main();
			break;

		case 4: //Lista
			Lista();
			return main();
			break;

		case 5: //Limpiar pantalla
			system("cls");
			return main();
			break;

		case 6: //archivos
			Archivos();
			return main();
			break;

		case 7: //salir
			exit(1);
			break;

		default: //opciones no existentes
			SetConsoleTextAttribute(Conh, 244); 
			printf("Opci%cn inv%clida\n",162,160); SetConsoleTextAttribute(Conh, 241);
			return main();
			break;
		}
	system("pause");
}
void Alta()
{
	printf("%cCu%cntos registros desea dar de alta? \n",168,160);
	scanf_s("%d", &nalta);
	menu = new articulos[nalta];
	

	for (int i = 0; i < nalta; i++)
	{
			printf("Ingrese el n%cmero de item\n", 163);
			scanf_s("%d",&menu[i].item);
			cin.ignore();
   for (int j=-1; j<i; j++)
   {if(menu[i].item==menu[j].item)
     {do{
         printf("Numero de item no disponible. Ingresa uno nuevo");
         scanf_s("%d",&menu[i].item);
        }while(menu[i].item==menu[j].item);
   } }
			printf("Nombre del art%cculo\n", 161);
			gets_s(menu[i].nombre);
			while (getchar() != '\n');
			printf("A%co de lanzamiento\n", 164);
			scanf_s("%d", &menu[i].anio);

			//Opciones de género
			do {
				printf("----------------------------------\n");
				printf("Seleccione el g%cnero del juego\n", 130);
				printf("1. Acci%cn\n2. Estrategia\n", 162);
				printf("3. Rol\n4. Deportes\n");
				printf("5. Aventura\n6. Simulaci%cn\n7. Otro (espec%cficar)\n", 162, 161);
				scanf_s("%d", &gen);
				while (getchar() != '\n');
				if (gen == 1) { menu[i].genero = "Accion"; }
				if (gen == 2) { menu[i].genero = "Estrategia"; }
				if (gen == 3) { menu[i].genero = "Rol"; }
				if (gen == 4) { menu[i].genero = "Deportes"; }
				if (gen == 5) { menu[i].genero = "Aventura"; }
				if (gen == 6) { menu[i].genero = "Simulacion"; }
				if (gen == 7)
				{
					printf("Especificaci%cn del g%cnero\n", 162, 130); getline(cin, menu[i].genero);
				}
				printf("----------------------------------\n");
				if (gen < 1 || 7 < gen) { SetConsoleTextAttribute(Conh, 244); printf("Opcion no valida\n"); SetConsoleTextAttribute(Conh, 241); }
			} while (gen < 1 || 7 < gen);
			//Fin de género

			//opciones de clasificación
			do {
				printf("Seleccione la clasificaci%cn\n", 162);
				printf("1. Todas las edades\n2. Todos (+10)\n3. +13\n4. +17\n5. Solo adultos (+18)\n");
				scanf_s("%d", &clas);
				while (getchar() != '\n');
				if (clas == 1) { menu[i].clasificacion = "Todas las edades"; }
				if (clas == 2) { menu[i].clasificacion = "Todos (+10)"; }
				if (clas == 3) { menu[i].clasificacion = "+13"; }
				if (clas == 4) { menu[i].clasificacion = "+17"; }
				if (clas == 5) { menu[i].clasificacion = "Solo adultos (+18)"; }
				printf("----------------------------------\n");
				if (clas < 1 || 5 < clas) { SetConsoleTextAttribute(Conh, 244); printf("Opcion no valida\n"); SetConsoleTextAttribute(Conh, 241); }
			} while (clas < 1 || 5 < clas); //fin de clasificación

			//opciones de consola
			do {
				printf("Seleccione la consola\n");
				printf("1. Play Station\n2. Xbox\n3. Nintendo\n4. Steam Deck\n5. Otro (espec%cficar)\n", 161);
				scanf_s("%d", &con);
				while (getchar() != '\n');
				if (con == 1) { menu[i].consola = "Play Station"; }
				if (con == 2) { menu[i].consola = "Xbox"; }
				if (con == 3) { menu[i].consola = "Nintendo"; }
				if (con == 4) { menu[i].consola = "Steam Deck"; }
				if (con == 5) { printf("Especificaci%cn de la consola\n", 162); getline(cin, menu[i].consola); }
				printf("----------------------------------\n");
				if (clas < 1 || 5 < clas) { SetConsoleTextAttribute(Conh, 244); printf("Opcion no valida\n"); SetConsoleTextAttribute(Conh, 241); }
			} while (con < 1 || 5 < con);
			//fin de consola

			printf("Ingrese caracter%csticas notables\n", 161);
			gets_s(menu[i].carac);
			printf("Agregue una descripci%cn breve\n", 162);
			getline(cin, menu[i].descripcion);
			cin.ignore();
			printf("Ingrese el precio unitario\n");
			scanf_s("%f", &menu[i].precio);
			menu[i].precioT = menu[i].precio + (menu[i].precio * 16) / 100;
			printf("\n");
	}
}

void Modificar()
{
	int j, opc, op2,op3,a=0;
	
	do
	{
		printf("N%cmero de registro a modificar\n",163);
		scanf_s("%d", &j);
		j = j - 1;
		for (int i = j; i == j; i++)
		{
			if ((menu[i].status == "ELIMINADO"))
			{
				printf("Registro %d eliminado\n", i + 1);
				printf("Ingrese un registro v%clido \n",160);
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}
	} while (op2 == 1);

	while (a==0)
	{ 
	printf("----------------------------------\n");
	printf("\t Men%c de m%cdificaci%cn \n",163,1, 162);
	printf("----------------------------------\n");
	printf("Ingrese que informaci%cn desea modicar\n",162);
	printf("1. N%cmero de item\n",163); 
	printf("2. Nombre del art%cculo\n", 161);
	printf("3. A%co de lanzamiento\n",164);
	printf("4. G%cnero\n",130);
	printf("5. Clasificaci%cn\n",162);
	printf("6. Consola\n");
	printf("7. Caracter%csticas\n",161);
	printf("8. Descripci%cn\n",162);
	printf("7. Precio unitario\n");
	printf("----------------------------------\n");
	scanf_s("%d",&opc);
	while (getchar() != '\n');
	switch (opc)
	{
		case 1: //Número de item
			for (int i = j; i == j; i++)
			{
				printf("Ingrese el n%cmero de item\n", 163);
				scanf_s("%d", &menu[i].item);
			}
			break;
		case 2: //Nombre del artículo
			for (int i = j; i == j; i++)
			{
				printf("Nombre del art%cculo\n", 161);
				gets_s(menu[i].nombre);
			}
			break;
		case 3: //Año
			for (int i = j; i == j; i++)
			{
				printf("A%co de lanzamiento\n", 164);
				scanf_s("%d", &menu[i].anio);
			}
			break;
		case 4: //Género
			for (int i = j; i == j; i++)
			{
				do {
					printf("----------------------------------\n");
					printf("Seleccione el g%cnero del juego\n", 130);
					printf("1. Acci%cn\n2. Estrategia\n", 162);
					printf("3. Rol\n4. Deportes\n");
					printf("5. Aventura\n6. Simulaci%cn\n7. Otro (espec%cficar)\n", 162, 161);
					scanf_s("%d", &gen);
					while (getchar() != '\n');
					if (gen == 1) { menu[i].genero = "Accion"; }
					if (gen == 2) { menu[i].genero = "Estrategia"; }
					if (gen == 3) { menu[i].genero = "Rol"; }
					if (gen == 4) { menu[i].genero = "Deportes"; }
					if (gen == 5) { menu[i].genero = "Aventura"; }
					if (gen == 6) { menu[i].genero = "Simulacion"; }
					if (gen == 7)
					{
						printf("Especificaci%cn del g%cnero\n", 162, 130); getline(cin, menu[i].genero);
					}
					printf("----------------------------------\n");
					if (gen < 1 || 7 < gen) { SetConsoleTextAttribute(Conh, 244); printf("Opcion no valida\n"); SetConsoleTextAttribute(Conh, 241); }
				} while (gen < 1 || 7 < gen);
			}
			break;
		case 5: //Clasificación
			for (int i = j; i == j; i++)
			{
				do {
					printf("Seleccione la clasificaci%cn\n", 162);
					printf("1. Todas las edades\n2. Todos (+10)\n3. +13\n4. +17\n5. Solo adultos (+18)\n");
					scanf_s("%d", &clas);
					while (getchar() != '\n');
					if (clas == 1) { menu[i].clasificacion = "Todas las edades"; }
					if (clas == 2) { menu[i].clasificacion = "Todos (+10)"; }
					if (clas == 3) { menu[i].clasificacion = "+13"; }
					if (clas == 4) { menu[i].clasificacion = "+17"; }
					if (clas == 5) { menu[i].clasificacion = "Solo adultos (+18)"; }
					printf("----------------------------------\n");
					if (clas < 1 || 5 < clas) { SetConsoleTextAttribute(Conh, 244); printf("Opcion no valida\n"); SetConsoleTextAttribute(Conh, 241); }
				} while (clas < 1 || 5 < clas);
			}
			break;
		case 6: //Consola
			for (int i = j; i == j; i++)
			{
				do {
					printf("Seleccione la consola\n");
					printf("1. Play Station\n2. Xbox\n3. Nintendo\n4. Steam Deck\n5. Otro (espec%cficar)\n", 161);
					scanf_s("%d", &con);
					while (getchar() != '\n');
					if (con == 1) { menu[i].consola = "Play Station"; }
					if (con == 2) { menu[i].consola = "Xbox"; }
					if (con == 3) { menu[i].consola = "Nintendo"; }
					if (con == 4) { menu[i].consola = "Steam Deck"; }
					if (con == 5) { printf("Especificaci%cn de la consola\n", 162); getline(cin, menu[i].consola); }
					printf("----------------------------------\n");
					if (con < 1 || 5 < con) { SetConsoleTextAttribute(Conh, 244); printf("Opcion no valida\n"); SetConsoleTextAttribute(Conh, 241); }
				} while (con < 1 || 5 < con);
			}
			break;
		case 7: //Características
			for (int i = j; i == j; i++)
			{
				printf("Ingrese caracter%csticas notables\n", 161);
				gets_s(menu[i].carac);
			}
			break;
		case 8: //Descripción
			for (int i = j; i == j; i++)
			{
				printf("Agregue una descripci%cn breve\n", 162);
				getline(cin, menu[i].descripcion);
			}
			break;
		case 9: //precio unitario
			for (int i = j; i == j; i++)
			{
				printf("Ingrese el precio unitario\n");
				scanf_s("%f", &menu[i].precio);
				menu[i].precioT = menu[i].precio + (menu[i].precio * 16) / 100;
			}
			break;
		default:
			SetConsoleTextAttribute(Conh, 244);
			printf("Opci%cn inv%clida\n", 162, 160); SetConsoleTextAttribute(Conh, 241);
			break;
	}
	printf("%cDesea modificar algo m%cs del item?\n1. Si\t2. No\n", 168, 160);
	scanf_s("%d", &op3);
	if (op3==2){a = 1;}
	}
}

void Lista()
{
	for (int i = 0; i < nalta; i++)
	{
		if (menu[i].status == "ELIMINADO")
		{
			printf("Registro eliminado %d\n", i + 1);
		}
		else
		{
			printf(" Registro n%cmero %d\n", 163, i + 1);
			printf("N%cmero de item: %d \n",163, menu[i].item);
			printf("Nombre del art%cculo: %s \n",161, menu[i].nombre);
			printf("A%co de lanzamiento: %d\n", 164,menu[i].anio);
			printf("G%cnero: %s \n",130, menu[i].genero.c_str());
			printf("Clasificaci%cn: %s \n",162, menu[i].clasificacion.c_str());
			printf("Consola: %s \n", menu[i].consola.c_str());
			printf("Caracter%csticas principales: %s\n", 161, menu[i].carac);
			printf("Descripici%cn: %s \n",162, menu[i].descripcion.c_str());
			printf("Precio unitario: %f \n", menu[i].precio);
			printf("Precio total: %f \n \n", menu[i].precioT);
		}
	}
}

void Eliminar()
{
	int j;
	printf("Ingrese el n%cmero de registro que desea eliminar\n",163);
	scanf_s("%d", &j);
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		printf("Eliminando registro %d\n", j + 1);
		menu[i].status = "Eliminado";
	}
}

void Archivos()
{
	ofstream archivo; //leer archivos
	string nombre;
	int texto;
	string texto2;
	float texto3;
	nombre = "videojuegosymas.txt";
	archivo.open(nombre.c_str(), ios::out);
	if (archivo.fail())
	{
		printf("Ocurri%c un error al tratar de generar el archivo\n", 162);
		exit(1);
	}
	archivo << "Item" << "\t" << "\t";
	archivo << "|Nombre" << "\t" << "\t" << "\t";
	archivo << "|Año" << "\t" << "\t";
	archivo << "|Genero" << "\t" << "\t";
	archivo << "|Clasificacion" << "\t" << "\t";
	archivo << "|Consola" << "\t" << "\t";
	archivo << "|Caracteristicas" << "\t" << "\t";
	archivo << "|Descripcion" << "\t" << "\t";
	archivo << "|Precio total" << "\n";

	for (int i = 0; i < nalta; i++)
	{
		if (menu[i].status == "Eliminado")
		{
			texto2 = "Registro eliminado";
			texto = i;
			archivo << texto2 << texto << "\n";
		}
		else
		{
			texto = menu[i].item;
			archivo <<texto << "\t" << "\t";
			texto2 = menu[i].nombre;
			archivo << "|"<<texto2 << "\t" << "\t";
			texto = menu[i].anio;
			archivo << "|" << texto << "\t" << "\t";
			texto2 = menu[i].genero;
			archivo << "|" << texto2 << "\t" << "\t";
			texto2 = menu[i].clasificacion;
			archivo << "|" << texto2 << "\t";
			texto2 = menu[i].consola;
			archivo << "|" << texto2 << "\t" << "\t";
			texto2 = menu[i].carac;
			archivo << "|" << texto2 << "\t" << "\t";
			texto2 = menu[i].descripcion;
			archivo << "|" << texto2 << "\t" << "\t";
			texto3 = menu[i].precioT;
			archivo << "|" << texto3 << "\n";
		}
	}
	archivo.close();
}
