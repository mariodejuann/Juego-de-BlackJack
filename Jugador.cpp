#include "Jugador.h"

void Jugador::verMano() { //función para imprimir con representación "gráfica" las cartas del jugador
    //♥♠♣
    for (int i=0; i<mano.size(); i++) { //desde 0 hasta la última carta del jugador. Si el valor y el palo coincide con la condición imprime cierta carta concreta
        if ((mano[i].conseguirValor() == 1) && (mano[i].conseguirPalo() == "Diamantes")) {
            cout << " _____" << endl;
            cout << "|A ^  |"  << endl;
            cout << "| / \\ |"  << endl; //para el resto de cartas igual: ponemos doble "\\" para que no se piense el ide que vamos a introducir un salto de línea o cualquier cosa
            cout << "| \\ / |"  << endl;
            cout << "|  .  |"   << endl;
            cout << "|____V|"            << endl;
        } else if ((mano[i].conseguirValor() == 1) && (mano[i].conseguirPalo() == "Corazones")) {
            cout << " _____" << endl;
            cout << "|A_ _ |"  << endl;
            cout << "|( v )|"  << endl;
            cout << "| \\ / |"  << endl;
            cout << "|  .  |"  << endl;
            cout << "|____V|"  << endl;
        } else if ((mano[i].conseguirValor() == 1) && (mano[i].conseguirPalo() == "Picas")) {
            cout << " _____" << endl;
            cout << "|A .  |"  << endl;
            cout << "| /.\\ |"  << endl;
            cout << "|(_._)|"  << endl;
            cout << "|  |  |"  << endl;
            cout << "|____V|"  << endl;
        } else if ((mano[i].conseguirValor() == 1) && (mano[i].conseguirPalo() == "Treboles")) {
            cout << " _____" << endl;
            cout << "|A _  |" << endl;
            cout << "| ( ) |" << endl;
            cout << "|(_'_)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____V|" << endl;
            //fin as
        } else if ((mano[i].conseguirValor() == 2) && (mano[i].conseguirPalo() == "Diamantes")) {
            cout << " _____" << endl;
            cout << "|2 ^  |"  << endl;
            cout << "| / \\ |"  << endl;
            cout << "| \\ / |"  << endl;
            cout << "|  .  |"   << endl;
            cout << "|____Z|"            << endl;
        } else if ((mano[i].conseguirValor() == 2) && (mano[i].conseguirPalo() == "Corazones")) {
            cout << " _____" << endl;
            cout << "|2_ _ |"  << endl;
            cout << "|( v )|"  << endl;
            cout << "| \\ / |"  << endl;
            cout << "|  .  |"  << endl;
            cout << "|____Z|"  << endl;
        } else if ((mano[i].conseguirValor() == 2) && (mano[i].conseguirPalo() == "Picas")) {
            cout << " _____" << endl;
            cout << "|2 .  |"  << endl;
            cout << "| /.\\ |"  << endl;
            cout << "|(_._)|"  << endl;
            cout << "|  |  |"  << endl;
            cout << "|____Z|"  << endl;
        } else if ((mano[i].conseguirValor() == 2) && (mano[i].conseguirPalo() == "Treboles")) {
            cout << " _____" << endl;
            cout << "|2 _  |" << endl;
            cout << "| ( ) |" << endl;
            cout << "|(_'_)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____Z|" << endl;
        } else if ((mano[i].conseguirValor() == 3) && (mano[i].conseguirPalo() == "Diamantes")) {
            cout << " _____" << endl;
            cout << "|3 ^  |" << endl;
            cout << "| / \\ |" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____E|" << endl;
        } else if ((mano[i].conseguirValor() == 3) && (mano[i].conseguirPalo() == "Corazones")) {
            cout << " _____" << endl;
            cout << "|3_ _ |" << endl;
            cout << "|( v )|" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____E|" << endl;
        } else if ((mano[i].conseguirValor() == 3) && (mano[i].conseguirPalo() == "Picas")) {
            cout << " _____" << endl;
            cout << "|3 .  |" << endl;
            cout << "| /.\\ |" << endl;
            cout << "|(_._)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____E|" << endl;
        } else if ((mano[i].conseguirValor() == 3) && (mano[i].conseguirPalo() == "Treboles")) {
            cout << " _____" << endl;
            cout << "|3 _  |" << endl;
            cout << "| ( ) |" << endl;
            cout << "|(_'_)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____E|" << endl;
        } else if ((mano[i].conseguirValor() == 4) && (mano[i].conseguirPalo() == "Diamantes")) {
            cout << " _____" << endl;
            cout << "|4 ^  |" << endl;
            cout << "| / \\ |" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____h|" << endl;
        } else if ((mano[i].conseguirValor() == 4) && (mano[i].conseguirPalo() == "Corazones")) {
            cout << " _____" << endl;
            cout << "|4_ _ |" << endl;
            cout << "|( v )|" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____h|" << endl;
        } else if ((mano[i].conseguirValor() == 4) && (mano[i].conseguirPalo() == "Picas")) {
            cout << " _____" << endl;
            cout << "|4 .  |" << endl;
            cout << "| /.\\ |" << endl;
            cout << "|(_._)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____h|" << endl;
        } else if ((mano[i].conseguirValor() == 4) && (mano[i].conseguirPalo() == "Treboles")) {
            cout << " _____" << endl;
            cout << "|4 _  |" << endl;
            cout << "| ( ) |" << endl;
            cout << "|(_'_)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____h|" << endl;
        } else if ((mano[i].conseguirValor() == 5) && (mano[i].conseguirPalo() == "Diamantes")) {
            cout << " _____" << endl;
            cout << "|5 ^  |" << endl;
            cout << "| / \\ |" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____S|" << endl;
        } else if ((mano[i].conseguirValor() == 5) && (mano[i].conseguirPalo() == "Corazones")) {
            cout << " _____" << endl;
            cout << "|5_ _ |" << endl;
            cout << "|( v )|" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____S|" << endl;
        } else if ((mano[i].conseguirValor() == 5) && (mano[i].conseguirPalo() == "Picas")) {
            cout << " _____" << endl;
            cout << "|5 .  |" << endl;
            cout << "| /.\\ |" << endl;
            cout << "|(_._)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____S|" << endl;
        } else if ((mano[i].conseguirValor() == 5) && (mano[i].conseguirPalo() == "Treboles")) {
            cout << " _____" << endl;
            cout << "|5 _  |" << endl;
            cout << "| ( ) |" << endl;
            cout << "|(_'_)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____S|" << endl;
        } else if ((mano[i].conseguirValor() == 6) && (mano[i].conseguirPalo() == "Diamantes")) {
            cout << " _____" << endl;
            cout << "|6 ^  |" << endl;
            cout << "| / \\ |" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____9|" << endl;
        } else if ((mano[i].conseguirValor() == 6) && (mano[i].conseguirPalo() == "Corazones")) {
            cout << " _____" << endl;
            cout << "|6_ _ |" << endl;
            cout << "|( v )|" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____9|" << endl;
        } else if ((mano[i].conseguirValor() == 6) && (mano[i].conseguirPalo() == "Picas")) {
            cout << " _____" << endl;
            cout << "|6 .  |" << endl;
            cout << "| /.\\ |" << endl;
            cout << "|(_._)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____9|" << endl;
        } else if ((mano[i].conseguirValor() == 6) && (mano[i].conseguirPalo() == "Treboles")) {
            cout << " _____" << endl;
            cout << "|6 _  |" << endl;
            cout << "| ( ) |" << endl;
            cout << "|(_'_)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____9|" << endl;
        } else if ((mano[i].conseguirValor() == 7) && (mano[i].conseguirPalo() == "Diamantes")) {
            cout << " _____" << endl;
            cout << "|7 ^  |" << endl;
            cout << "| / \\ |" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____L|" << endl;
        } else if ((mano[i].conseguirValor() == 7) && (mano[i].conseguirPalo() == "Corazones")) {
            cout << " _____" << endl;
            cout << "|7_ _ |" << endl;
            cout << "|( v )|" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____L|" << endl;
        } else if ((mano[i].conseguirValor() == 7) && (mano[i].conseguirPalo() == "Picas")) {
            cout << " _____" << endl;
            cout << "|7 .  |" << endl;
            cout << "| /.\\ |" << endl;
            cout << "|(_._)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____L|" << endl;
        } else if ((mano[i].conseguirValor() == 7) && (mano[i].conseguirPalo() == "Treboles")) {
            cout << " _____" << endl;
            cout << "|7 _  |" << endl;
            cout << "| ( ) |" << endl;
            cout << "|(_'_)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____L|" << endl;
        } else if ((mano[i].conseguirValor() == 8) && (mano[i].conseguirPalo() == "Diamantes")) {
            cout << " _____" << endl;
            cout << "|8 ^  |" << endl;
            cout << "| / \\ |" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____8|" << endl;
        } else if ((mano[i].conseguirValor() == 8) && (mano[i].conseguirPalo() == "Corazones")) {
            cout << " _____" << endl;
            cout << "|8_ _ |" << endl;
            cout << "|( v )|" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____8|" << endl;
        } else if ((mano[i].conseguirValor() == 8) && (mano[i].conseguirPalo() == "Picas")) {
            cout << " _____" << endl;
            cout << "|8 .  |" << endl;
            cout << "| /.\\ |" << endl;
            cout << "|(_._)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____8|" << endl;
        } else if ((mano[i].conseguirValor() == 8) && (mano[i].conseguirPalo() == "Treboles")) {
            cout << " _____" << endl;
            cout << "|8 _  |" << endl;
            cout << "| ( ) |" << endl;
            cout << "|(_'_)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____8|" << endl;
        } else if ((mano[i].conseguirValor() == 9) && (mano[i].conseguirPalo() == "Diamantes")) {
            cout << " _____" << endl;
            cout << "|9 ^  |" << endl;
            cout << "| / \\ |" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____6|" << endl;
        } else if ((mano[i].conseguirValor() == 9) && (mano[i].conseguirPalo() == "Corazones")) {
            cout << " _____" << endl;
            cout << "|9_ _ |" << endl;
            cout << "|( v )|" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____6|" << endl;
        } else if ((mano[i].conseguirValor() == 9) && (mano[i].conseguirPalo() == "Picas")) {
            cout << " _____" << endl;
            cout << "|9 .  |" << endl;
            cout << "| /.\\ |" << endl;
            cout << "|(_._)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____6|" << endl;
        } else if ((mano[i].conseguirValor() == 9) && (mano[i].conseguirPalo() == "Treboles")) {
            cout << " _____" << endl;
            cout << "|9 _  |" << endl;
            cout << "| ( ) |" << endl;
            cout << "|(_'_)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____6|" << endl;
        } else if ((mano[i].conseguirValor() == 10) && (mano[i].conseguirPalo() == "Diamantes")) {
            cout << " _____" << endl;
            cout << "|10^  |" << endl;
            cout << "| / \\ |" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|___0I|" << endl;
        } else if ((mano[i].conseguirValor() == 10) && (mano[i].conseguirPalo() == "Corazones")) {
            cout << " _____" << endl;
            cout << "|10_ _|" << endl;
            cout << "|( v )|" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|___0I|" << endl;
        } else if ((mano[i].conseguirValor() == 10) && (mano[i].conseguirPalo() == "Picas")) {
            cout << " _____" << endl;
            cout << "|10.  |" << endl;
            cout << "| /.\\ |" << endl;
            cout << "|(_._)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|___0I|" << endl;
        } else if ((mano[i].conseguirValor() == 10) && (mano[i].conseguirPalo() == "Treboles")) {
            cout << " _____" << endl;
            cout << "|10_  |" << endl;
            cout << "| ( ) |" << endl;
            cout << "|(_'_)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|___0I|" << endl;
        } else if ((mano[i].conseguirValor() == 11) && (mano[i].conseguirPalo() == "Diamantes")) {
            cout << " _____" << endl;
            cout << "|J ^  |" << endl;
            cout << "| / \\ |" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____L|" << endl;
        } else if ((mano[i].conseguirValor() == 11) && (mano[i].conseguirPalo() == "Corazones")) {
            cout << " _____" << endl;
            cout << "|J_ _ |" << endl;
            cout << "|( v )|" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____L|" << endl;
        } else if ((mano[i].conseguirValor() == 11) && (mano[i].conseguirPalo() == "Picas")) {
            cout << " _____" << endl;
            cout << "|J .  |" << endl;
            cout << "| /.\\ |" << endl;
            cout << "|(_._)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____L|" << endl;
        } else if ((mano[i].conseguirValor() == 11) && (mano[i].conseguirPalo() == "Treboles")) {
            cout << " _____" << endl;
            cout << "|J _  |" << endl;
            cout << "| ( ) |" << endl;
            cout << "|(_'_)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____L|" << endl;
        } else if ((mano[i].conseguirValor() == 12) && (mano[i].conseguirPalo() == "Diamantes")) {
            cout << " _____" << endl;
            cout << "|Q ^  |" << endl;
            cout << "| / \\ |" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____Q|" << endl;
        } else if ((mano[i].conseguirValor() == 12) && (mano[i].conseguirPalo() == "Corazones")) {
            cout << " _____" << endl;
            cout << "|Q_ _ |" << endl;
            cout << "|( v )|" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____Q|" << endl;
        } else if ((mano[i].conseguirValor() == 12) && (mano[i].conseguirPalo() == "Picas")) {
            cout << " _____" << endl;
            cout << "|Q .  |" << endl;
            cout << "| /.\\ |" << endl;
            cout << "|(_._)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____Q|" << endl;
        } else if ((mano[i].conseguirValor() == 12) && (mano[i].conseguirPalo() == "Treboles")) {
            cout << " _____" << endl;
            cout << "|Q _  |" << endl;
            cout << "| ( ) |" << endl;
            cout << "|(_'_)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____Q|" << endl;
        } else if ((mano[i].conseguirValor() == 13) && (mano[i].conseguirPalo() == "Diamantes")) {
            cout << " _____" << endl;
            cout << "|K ^  |" << endl;
            cout << "| / \\ |" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____K|" << endl;
        } else if ((mano[i].conseguirValor() == 13) && (mano[i].conseguirPalo() == "Corazones")) {
            cout << " _____" << endl;
            cout << "|K_ _ |" << endl;
            cout << "|( v )|" << endl;
            cout << "| \\ / |" << endl;
            cout << "|  .  |" << endl;
            cout << "|____K|" << endl;
        } else if ((mano[i].conseguirValor() == 13) && (mano[i].conseguirPalo() == "Picas")) {
            cout << " _____" << endl;
            cout << "|K .  |" << endl;
            cout << "| /.\\ |" << endl;
            cout << "|(_._)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____K|" << endl;
        } else if ((mano[i].conseguirValor() == 13) && (mano[i].conseguirPalo() == "Treboles")) {
            cout << " _____" << endl;
            cout << "|K _  |" << endl;
            cout << "| ( ) |" << endl;
            cout << "|(_'_)|" << endl;
            cout << "|  |  |" << endl;
            cout << "|____K|" << endl;
        }
    }
}

void Jugador::agregarCarta(Carta c) { //añadir la carta pasada por valor a la mano del jugador
    mano.push_back(c); //la mete dentro del vector
}

//las figuras (J, Q, K) valen 10 puntos.
//el As puede valer 1 u 11 puntos, según convenga al jugador.
int Jugador::calcularPuntuaje() {
    int puntos = 0; //inicializamos el puntuaje a 0.
    int contadorAses = 0;
    for (int i = 0; i < mano.size() ; i++) { //iteramos sobre cada carta de la mano del jugador
        if (mano[i].conseguirValor() == 1){  //Si la carta es un As, incrementamos contador
            contadorAses++;
        }

        if (mano[i].conseguirValor() > 10) { //si la carta es J, Q o K
            puntos += 10;
        } else if (mano[i].conseguirValor() == 1) { //que el As principalmente valga 11
            puntos += 11;
        } else { //el resto de cartas que valgan su valor original
            puntos += mano[i].conseguirValor();
        }
    }

    while (puntos > 21 && contadorAses > 0) { //mientras tenga más de 21 puntos y tenga algún As, que vuelva a calcular los puntos pero ajustando uno por uno los Ases con valor de 1 hasta intentar llegar a un valor por debajo de 21
        puntos -= 10; //le cambias al valor de 1 al As
        contadorAses--; //quitas un As de la lista
    } //una vez los puntos sean <= a 21 o no haya más Ases, o ambas, se sale del buble

    return puntos; //devuelve los puntos
}

Jugador::Jugador(string nombre) { //setea el nombre pasado por valor
    name = nombre;
}

string Jugador::getName() { //devuelve el nombre del jugador
    return name;
}

std::vector<Carta> Jugador::getMano() { //devuelve la mano del jugador
    return mano;
}

void Jugador::listoParaJugar() { //imprime que el jugador está listo para jugar
    cout << "[+] Jugador " << this->getName() << ", listo para jugar!" << endl;
}


