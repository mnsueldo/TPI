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
        menu();
        cin >> opcion;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opción no válida. Por favor, intenta nuevamente." << endl << endl;
            continue;
}
        switch (opcion) {
            case 1:

                  jugar();


                break;
            case 2:
                cout << "Aca irian las estadisticas" << endl;
                break;


            case 3:
                creditos();
                break;



            case 0:
                cout << "¿Estás seguro que deseas salir? (S/N): ";
                char confirmacion;
                cin >> confirmacion;
                if (toupper(confirmacion) == 'S') {
                    cout << "Saliendo del juego..." << endl;
                    return 0;
                }
            //VER COMO LIMPIAR LA CONSOLA CADA VEZ QUE SE ENTRA A UNA NUEVA "VENTANA"


        }
    } while (true);
    return 0;
}
