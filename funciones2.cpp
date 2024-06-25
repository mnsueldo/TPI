#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "funciones2.h"

using namespace std;


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
