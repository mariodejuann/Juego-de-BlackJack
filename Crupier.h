#include "Jugador.h"

#ifndef CRUPIER_H
#define CRUPIER_H



class Crupier : public Jugador { //definición de clase Crupier. Hereda de la clase Jugador sus atributos y métodos
public:
    Crupier(string); //constructor con parámetro para clase Crupier
    friend ostream& operator<<(ostream&, Crupier&); //sobrecarga del operador de salida

    virtual void listoParaJugar() override; //sobreescribimos la función "listoParaJugar" de la clase padre demostrando el polimorfismo
};



#endif //CRUPIER_H
