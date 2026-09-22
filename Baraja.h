#include "Carta.h"
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

#ifndef BARAJA_H
#define BARAJA_H



class Baraja { //definimos clase Baraja
private:
    vector<Carta> cartas; //define un contenedor de tipo std::vector que almacenará objetos de la clase "Carta". Tiene el nombre "cartas".
public:
    Baraja(); //constructor por defecto
    //funciones:
    void barajarCartas();
    Carta quitarCarta();
};



#endif //BARAJA_H
