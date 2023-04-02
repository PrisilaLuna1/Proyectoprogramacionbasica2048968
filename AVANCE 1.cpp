#include <iostream>

using namespace std;
int main()
{
	int opcion, item, de;
	char nombre[50], descripcion[256], genero[50], clasificacion[50], consola [50];
	float precioT, precio;

	cout << "\t Menú de opciones" << endl;
	cout << "1. Alta" << endl;
	cout<< "2. Modificacion" << endl;
	cout << "3. Baja" << endl;
	cout << "4. Lista" << endl;
	cout << "5. Limpiar pantalla" << endl;
	cout << "6. Salir" << endl;
	cin >> opcion;

	switch (opcion)
	{
	case 1: //Alta
		cout << "Ingrese el numero de item" << endl;
		cin >> item;
		cout << "Nombre del articulo" << endl;
		cin >> nombre;
		cout << "Agregue una descripcion breve" << endl;
		cin >> descripcion;
		cout << "Ingrese el genero del juego" << endl;
		cin >> genero;
		cout << "Ingrese la clasificacion" << endl;
		cin >> clasificacion;
		cout << "Ingrese la consola" << endl;
		cin >> consola;

		cout << "Ingrese el precio unitario" << endl;
		cin >> precio;
		precioT = precio + (precio * 16) / 100;

		cout << "Desea regresar al menu" << endl << "1. si  2. no" << endl; //MENU
		cin >> de;
		if (de == 1)
		{
			return main();
		}
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	case 5: //Limpiar pantalla
		system("cls");
		return main();
		break;

	case 6: //salir
		exit(1);
		break;

	default: //opciones no existentes
		cout << "opcion invalida" << endl;
		return main();
		break;
	}
	system("pause");
}
