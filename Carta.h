#include <iostream>

#ifndef CARTA_H
#define CARTA_H

using namespace std;

enum class Palos { //creamos un enum class de los palos posibles para las cartas
    DIAMANTES=1, CORAZONES=2, PICAS=3, TREBOLES=4, SIN_PALO=5
};

class Carta { //definimos clase carta
private: //cada carta tendrá su número y su palo
    Palos palo;
    int valor;
public:
    Carta(); //constructor por defecto
    Carta(Palos, int); //constructor con parámetros

    //funciones:
    string conseguirPalo();
    int conseguirValor();
    void setPalo(Palos);
    void setValor(int);
};



#endif //CARTA_H
