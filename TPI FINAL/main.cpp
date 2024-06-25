#include <iostream>
#include <string>
#include <limits>
#include <locale.h>
#include <vector>
#include <ctime>
#include "funciones.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    int opcion;
    do {
        menu(); //lamo al menu
        cin >> opcion; // tomo la opcion

        system("cls");
        switch (opcion) {
            case 1:

                jugar();

                system("pause");
                break;
            case 2:
                cout << "Aca irian las estadisticas" << endl;
                system("pause");
                break;

            case 3:
                creditos();
                system("pause");
                break;

            case 0:
                cout << "¿Estás seguro que deseas salir? (S/N): ";
                char confirmacion;
                cin >> confirmacion;
                if (toupper(confirmacion) == 'S') {
                    cout << "Saliendo del juego..." << endl;
                    return 0;
                }

                system("pause");
                break;
                default:

                cout << "Opcion no valida " <<endl;
                system("pause");
                break;

        }
        system("cls");
    } while (opcion <=3);
    return 0;
}

