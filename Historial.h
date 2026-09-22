#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <fstream>
#include <vector>
#include <iostream>

using namespace std;


class Historial { //definimos clase Historial
private:
    struct HistorialJugador { //definición de struct con la información para cada jugador
        string nombre;
        int ganadas;
        int perdidas;
        int empatadas;
    };
    vector<HistorialJugador> historial; // Vector para almacenar el historial (los structs)
public:
    Historial(); //constructor por defecto para cargar el historial desde el archivo

    //función para buscar un jugador en el historial por su nombre
    int buscarJugador(const string& nombre);

    //función para guardar el historial en el archivo
    void guardarHistorial();

    //función para actualizar el historial después de una partida
    void actualizarHistorial(const string& nombre, const string& resultado);

    //función para mostrar el historial en consola
    void mostrarHistorial();
};



#endif //HISTORIAL_H
