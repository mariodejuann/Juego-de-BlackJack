#include "Carta.h"

Carta::Carta() { //para una carta por defecto no le asignamos palo ni valor
    palo = Palos::SIN_PALO;
    valor = 0;
}

Carta::Carta(Palos pal, int val) { //creamos una carta con el valor y palo que nos dicen
    palo = pal;
    if (val < 1 ||val > 12) { // A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K. Si le pasan a la función un valor que no se encuentra en la baraja de poker
        cout << "[!] Valor no e existente en la baraja de poker" << endl;
    }
    valor = val;
}

string Carta::conseguirPalo() { //función para devolver el palo de una carta. Transformando el enumclass a un string
    switch(palo) { //swith para todos los casos posibles
        case Palos::SIN_PALO:return "SIN_PALO";
        case Palos::DIAMANTES:return "Diamantes";
        case Palos::CORAZONES:return "Corazones";
        case Palos::PICAS:return "Picas";
        case Palos::TREBOLES:return "Treboles";
    }
}

int Carta::conseguirValor() { //devuelve el valor
    return valor;
}

void Carta::setPalo(Palos pal) { //setea el palo pasado por valor
    palo = pal;
}

void Carta::setValor(int val) { //setea el valor pasado por valor
    valor = val;
}