#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "funciones2.h"
using namespace std;

int main() {

    // FUNCION CARGAR VECTORES
    vector<string> vec = cargarCartas();
    int TAM2 = vec.size();


    //FUNCION CARGAR LOS PALOS
    vector<string> vecPalo = cargarPalos(TAM2);


    //FUNCION CARGAR PUNTOS
    vector<int> vecPuntos = cargarPuntos(TAM2);

    // FUNCION MOSTRAR LA CARTA, SU VALOR Y EL NUMERO DE PALO
   // mostrarCartas3(vec, vecPalo, vecPuntos);


    //FUNCION REPARTIR CARTAS
    const int TAM = 5;
    int vector1[TAM] = {}; // Jugador 1
    int vector2[TAM] = {}; // Jugador 2

    repartirCartas(vec, vector1, vector2);

    // Mostrar cartas del Jugador 1
    cout << "Cartas del Jugador 1:" << endl;
    mostrarCartas(vec, vector1, TAM);
    cout << endl;

    // Mostrar cartas del Jugador 2
    cout << "Cartas del Jugador 2:" << endl;
    mostrarCartas(vec, vector2, TAM);
    cout << endl;

    // FUNCION ESTABLECER CARTA EMBAUCADORA
    string xembaucado = tipodeEmbaucado();
    cout << "La carta EMBAUCADORA actual es: " << xembaucado <<endl;


    //FUNCION SUMAR PUNTOS
    int puntosJugador1 = sumarPuntos(vecPuntos, vecPalo, vector1, TAM, xembaucado);
    int puntosJugador2 = sumarPuntos(vecPuntos, vecPalo, vector2, TAM, xembaucado);

    cout << "Puntos del Jugador 1: " << puntosJugador1 << endl;
    cout << "Puntos del Jugador 2: " << puntosJugador2 << endl;


    return 0;
}








