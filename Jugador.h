#include <vector>
#include <iostream>
#include "Carta.h"

#ifndef JUGADOR_H
#define JUGADOR_H

using namespace std;

class Jugador { //definimos clase Jugador
protected: //ponemos los atributos protegidos para que los pueda heredar la clase Crupier
    string name;
    vector<Carta> mano; //el jugador tendrá su propia mano
public:
    Jugador(string); //constructor con parámetro

    //funciones:
    void verMano();
    int calcularPuntuaje();
    void agregarCarta(Carta);
    string getName();
    std::vector<Carta> getMano();

    virtual void listoParaJugar(); //función para representar el polimorfismo
};



#endif //JUGADOR_H
