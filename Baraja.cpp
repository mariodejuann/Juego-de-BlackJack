#include "Baraja.h"

Baraja::Baraja() { // 4 palos
    Carta temp(Palos::SIN_PALO, 1); //creamos carta temporal para ir seteándole el palo y el número
    for (int i=static_cast<int>(Palos::DIAMANTES); i<static_cast<int>(Palos::SIN_PALO); i++) { //desde DIAMANTES hasta SIN_PALO (sin incluirlo)
        for (int j=1; j<=13; j++) { //13 cartas en cada palo
            temp.setPalo(static_cast<Palos>(i)); //seteamos palo
            temp.setValor(j); //seteamos valor
            cartas.push_back(temp); //metemos en el vector de cartas, la carta temporal
        }
    }
} //termina generando las 52 cartas de la baraja de poker

void Baraja::barajarCartas() {
    //inicializar un motor mt19937 con una semilla basada en el tiempo
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rng(seed);
    shuffle(cartas.begin(), cartas.end(), rng); //barajamos el mazo de cartas
}

Carta Baraja::quitarCarta() {
    //quita la carta del vector de cartas general y la devuelve
    Carta ultima = cartas.back();
    cartas.pop_back();
    return ultima;
}