#ifndef FUNCIONES2_H_INCLUDED
#define FUNCIONES2_H_INCLUDED

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <vector>
#include <string>
#include <iostream>


using namespace std;
//FUNCION REPETIDO
bool repetido(int vector12[], int indice, int i);

//FUNCION CARTA EMBAUCADORA RANDOM
string tipodeEmbaucado();

//FUNCION ASIGNAR EL NOMBRE DE LAS CARTAS
vector<string> cargarCartas();

//FUNCION ASIGNAR EL PALO DE LAS CARTAS
vector<string> cargarPalos(int TAM2);

//FUNCION ASIGNAR PUNTOS DE LAS CARTAS
vector<int> cargarPuntos(int TAM2);

// FUNCION PARA MOSTRAR LAS CARTAS, SUS VALORES Y SUS PALOS
void mostrarCartas3(const vector<string>& vec, const vector<string>& vecPalo, const vector<int>& vecPuntos);

//FUNCION REPARTIR CARTAS
void repartirCartas(vector<string>& vec, int vector1[], int vector2[]);

//FUNCION MOSTRAR CARTAS
void mostrarCartas(const vector<string>& vec, int vector[], int size);


//FUNCION SUMAR PUNTOS TOTALES
int sumarPuntos(const vector<int>& vecPuntos, const vector<string>& vecPalo, const int* vectorJugador, int TAM, const string& xembaucado);

#endif // FUNCIONES_H_INCLUDED

#endif // FUNCIONES2_H_INCLUDED
