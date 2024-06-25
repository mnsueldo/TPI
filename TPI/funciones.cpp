#include <iostream>
#include <string>
#include <limits>
#include <locale.h>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "funciones.h"
using namespace std;

void jugar(){
    string jugador1;
    string jugador2; //Almaceno los nombres
    string confirm = "N";
    int ronda = 1;


            /*-----------------------------*/
            cout << " " << endl;
            cout << " " << endl;
            cout << "---------------------------------------------------" << endl;
            cout << " " << endl;
            cout << "        ¡¡¡¡¡BIENVENIDO AL JUEGO DE EL...          " << endl;
            cout << "                   EMBAUCADO!!!!!                  " << endl;
            cout << " " << endl;
            cout << "---------------------------------------------------" << endl;
            cout << "Antes de comenzar deben registrar sus nombres:" << endl;
            cout << "¿Nombre del Jugador 1? " ;
            cin >> jugador1;
            cout << " " << endl;
            cout << "¿Nombre del Jugador 2? ";
            cin >> jugador2;
            cout << "¿Confirmar nombres? (S/N) ";
            cin >> confirm;
            cout << " " << endl;
            cout << " " << endl;
            cout << "---------------------------------------------------"  << endl;
            /*-----------------------------*/
            /*-------------- comienzo repartir---------------*/
            /*-----------------------------*/


             if(confirm == "S" || confirm == "s") {
                        //RONDA 1


                    repartirCartas();





                        // RONDA 2

                        //RONDA 3
}


}


//FUNCION REPARTIR CARTAS

void repartirCartas(){

    vector<string> vec = cargarCartas();
    int TAM2 = vec.size();

    vector<string> vecPalo = cargarPalos(TAM2);

    vector<int> vecPuntos = cargarPuntos(TAM2);


    const int TAM = 5;
    int vector1[TAM] = {};
    int vector2[TAM] = {};

    {
        const int TAM_TOTAL = 10;
        int vector12[TAM_TOTAL] = {};
        int i, indice;

        srand(time(0));
        int xtam = vec.size();

        for (i = 0; i < TAM_TOTAL; i++) {
            indice = rand() % xtam;

            while (repetido(vector12, indice, i)) {
                indice = rand() % xtam;
            }

            vector12[i] = indice;

            if (i < 5) {
                vector1[i] = indice;
            } else {
                vector2[i - 5] = indice;
            }
        }
    }

    cout << "Cartas del Jugador 1:" << endl;
    mostrarCartas(vec, vector1, TAM);
    cout << endl;


    cout << "Cartas del Jugador 2:" << endl;
    mostrarCartas(vec, vector2, TAM);
    cout << endl;

    string xembaucado = tipodeEmbaucado();
    cout << "La carta EMBAUCADORA actual es: " << xembaucado << endl;


    int puntosJugador1 = sumarPuntos(vecPuntos, vecPalo, vector1, TAM, xembaucado);
    int puntosJugador2 = sumarPuntos(vecPuntos, vecPalo, vector2, TAM, xembaucado);

    cout << "Puntos del Jugador 1: " << puntosJugador1 << endl;
    cout << "Puntos del Jugador 2: " << puntosJugador2 << endl;
}

//FUNCION REPETIDO

bool repetido(int vector12[], int indice, int i) {
    for (int x = 0; x < i; x++) {
        if (indice == vector12[x]) {
            return true;
        }
    }
    return false;
}

//FUNCION CARTA EMBAUCADORA RANDOM
string tipodeEmbaucado(){
    int i;
    srand(time(0));
    vector<string> vec = {"Corazon", "Diamante","Pica","Trebol"};
    int tamanoArreglo = vec.size();
    int indice = rand() % tamanoArreglo;
    string texto = vec[indice];

    return texto;
}

//FUNCION ASIGNAR EL NOMBRE DE LAS CARTAS
vector<string> cargarCartas() {
    return {"10 de Corazon", "J de Corazon", "Q de Corazon", "K de Corazon", "A de Corazon",
            "10 de Diamante", "J de Diamante", "Q de Diamante", "K de Diamante", "A de Diamante",
            "10 de Pica", "J de Pica", "Q de Pica", "K de Pica", "A de Pica",
            "10 de Trebol", "J de Trebol", "Q de Trebol", "K de Trebol", "A de Trebol"};
}

// FUNCION ASIGNAR EL PALO A LAS CARTAS
vector<string> cargarPalos(int TAM2) {
    vector<string> vecPalo(TAM2);
    for (int i = 0; i < 20; i++) {
        if (i < 5) {
            vecPalo[i] = "Corazon"; // 1 o Corazon
        } else if (i < 10) {
            vecPalo[i] = "Diamante"; // 2 o Diamante
        } else if (i < 15) {
            vecPalo[i] = "Pica"; // 3 o Pica
        } else {
            vecPalo[i] = "Trebol"; // 4 o Trebol
        }
    }
    return vecPalo;
}
// FUNCION PARA ASIGNAR LOS PUNTOS DE LAS CARTAS
vector<int> cargarPuntos(int TAM2) {
    return {
        10, 11, 12, 15, 20,
        10, 11, 12, 15, 20,
        10, 11, 12, 15, 20,
        10, 11, 12, 15, 20};
}


// FUNCION PARA MOSTRAR LAS CARTAS, SUS VALORES Y SUS PALOS
void mostrarCartas3(const vector<string>& vec, const vector<string>& vecPalo, const vector<int>& vecPuntos) {
    int TAM2 = vec.size();
    for (int i = 0; i < TAM2; i++) {
        cout << vec[i] << " -> Puntos: " << vecPuntos[i] << ", Palo: " << vecPalo[i] << endl;
    }
}

//FUNCION REPARTIR CARTAS
    void repartirCartas(vector<string>& vec, int vector1[], int vector2[]) {
    const int TAM = 10;
    int vector12[TAM] = {}; // Contiene las 10 cartas
    int i, indice;

    srand(time(0));

    int xtam = vec.size(); // Tamaño del vec

    for (i = 0; i < TAM; i++) {
        indice = rand() % xtam; // Genera el índice (posición) de la carta en el vec.

        while (repetido(vector12, indice, i)) { // Corrobora si está repetido
            indice = rand() % xtam; // En caso que sea repetido, vuelve a generar otro número de posición.
        }

        vector12[i] = indice; // Guardo las 10 cartas

        if (i < 5) {
            vector1[i] = indice; // Si es menor a 5 es del jugador 1
        } else {
            vector2[i - 5] = indice; // Si es mayor a 5 es del jugador 2
        }
    }
}

//FUNCION MOSTRAR CARTAS

void mostrarCartas(const vector<string>& vec, int vector[], int size) {
    for (int i = 0; i < size; i++) {
        cout << vec[vector[i]] << endl;
    }
}

int sumarPuntos(const vector<int>& vecPuntos, const vector<string>& vecPalo, const int* vectorJugador, int TAM, const string& xembaucado) {
    int suma = 0;
    for (int i = 0; i < TAM; i++) {
        if (vecPalo[vectorJugador[i]] != xembaucado) {
            suma += vecPuntos[vectorJugador[i]];
        }
    }
    return suma;
}





            /*-----------------------------*/
            /*-------------- fin repartir---------------*/
            /*-----------------------------*/








/*============================ FUNCIONES DEL MENU===================================*/
void menu() {
    cout << "EMBAUCADO" << endl;
    cout << "---------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADÍSTICAS" << endl;
    cout << "3 - CRÉDITOS" << endl;
    cout << "---------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "Elige una opción (0-3): ";
}


/*
void estadisticas(){

    vector<string> nombreJugador = {"Lucas", "Mariano", "Luciana"};
    vector<string> puntajeTotal = { "350", "676", "821"};

    cout << "               Estadísticas        " << endl;
    cout << "Nombre de jugador  Puntaje" << endl;
    for (int i= 0; i < nombreJugador.size(); i++){
    cout << nombreJugador[i] <<"      " << puntajeTotal[i] << endl;}
    cout << "Pulsa cualquier tecla para volver al menú";
    int tecla;
    cin >> tecla;

}*/

void creditos(){

    cout << " " << endl;
    cout << "Créditos:" << endl;
    cout << "Nombre del grupo: Grupo 33" << endl;
    cout << "Integrantes:" << endl;
    cout << "Nicolas Gabriel Vella Martinez" << endl;
    cout << "Eliana Giselle Miwszuk " << endl;
    cout << "Hernan Alberto Ramirez" <<endl;
    cout << "Martin Sueldo" << endl;
    cout << "Pulsa 0 para Volver." << endl;
    int tecla;
    cin >> tecla;
}
