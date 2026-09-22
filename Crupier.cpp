#include "Crupier.h"

Crupier::Crupier(string nombre) : Jugador(nombre) {} //le pasamos al constructor con parámetros de Jugador, el nombre del crupier

ostream& operator<<(ostream& os, Crupier& crupier) {
    os << crupier.calcularPuntuaje(); //cargamos en el operador de salida el puntuaje del crupier
    return os; //devolvermos por referencia el mismo operador de salida pero sobrecargado
}

void Crupier::listoParaJugar() { //imprime que el crupier está listo para jugar
    cout << "[+] Crupier " << this->getName() << ", listo para jugar!" << endl;
}
