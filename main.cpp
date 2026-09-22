#include <iostream>
#include <fstream> //para el manejo de archivos
#include <unistd.h> //para poder hacer sleeps
//#include <windows.h> //para interactuar con el sistema del usuario
#include "Jugador.h"
#include "Crupier.h"
#include "Historial.h"
#include "Baraja.h"

using namespace std; //para evitar poner std::vector y demás

int juego(string name) { //Lógica del juego
    Historial historial; //creamos un historial
    Jugador player(name); //creamos un jugador
    Crupier crupier("Federic"); //creamos un crupier
    Baraja baraja; //baraja general de 52 cartas

    cout << "\n\n[+] Juegas contra el crupier " << crupier.getName() << "!" << endl;
    //llamamos a las funciones para reportar por pantalla que los jugadores están listos
    player.listoParaJugar();
    crupier.listoParaJugar();
    cout << "\n";

    baraja.barajarCartas(); //barajamos el mazo de cartas

    Carta carta; //creamos una carta para poder ir metiendola en la mano de los jugadores

    //Mano jugador
    carta = baraja.quitarCarta();
    player.agregarCarta(carta);
    carta = baraja.quitarCarta();
    player.agregarCarta(carta);

    //Mano Crupier
    carta = baraja.quitarCarta();
    crupier.agregarCarta(carta);
    carta = baraja.quitarCarta();
    //aún no agregamos la carta a la mano del crupier para no imprimirla al principio del juego

    Carta temp;
    int opcion;
    while (true) {
        cout << "Tu mano: " << endl;
        player.verMano(); //mostramos mano jugador
        cout << "\n- Puntuación: " << player.calcularPuntuaje() << endl; //calculamos puntuaje jugador

        cout << "\nMano del Crupier: " << endl;
        crupier.verMano(); //mostramos mano crupier
        //simulamos la otra carta del crupier dada la vuelta
        cout << " _____" << endl;
        cout << "|\\ ~ /|"  << endl;
        cout << "|}}:{{|"  << endl;
        cout << "|}}:{{|"  << endl;
        cout << "|}}:{{| "  << endl;
        cout << "|/_~_\\| "  << endl;
        cout << "\n- Puntuación: " << crupier.calcularPuntuaje() << endl; //mostramos puntuaje crupier
        cout << "\n[+] Quieres otra carta[0] o plantarte[1]? \n-> "; //preguntamos al jugador si quiere plantarse o pedir una carta
        cin >> opcion;

        if (opcion == 1) { //jugador se quiere plantar
            //destapa la otra carta el crupier
            cout << "\n[+] Crupier levanta su otra carta y tiene de mano: " << endl;
            //agregamos la carta a su mano y e imprimimos esta
            crupier.agregarCarta(carta);
            crupier.verMano();
            cout << "\n- Puntuación de Crupier " << crupier.getName() << ": " << crupier << endl; //calculamos puntuación con la carta destapada

            //Crupier con 2 cartas levantadas. DECISIONES
            while (crupier.calcularPuntuaje() < 17) { //mientras la puntuación del crupier esté por debajo de 17:
                if ((crupier.calcularPuntuaje() >= 17) && (crupier.calcularPuntuaje() <= 21)) { //si llega a 17 sin pasarse de 21 que se plante
                    //crupier se planta
                    cout << "\n[!] Crupier: Me planto!" << endl;
                    break;
                } else if (crupier.calcularPuntuaje() > 21) { //si se pasa de 21 pierde
                    //crupier se pasa de 21
                    cout << "\n[!] Crupier se pasa de 21!" << endl;
                    break;
                } else if (crupier.calcularPuntuaje() < 17) { //si tiene menos de 17 que pida otra carta
                    //si la puntuación del crupier es < que 17
                    //crupier se da otra carta
                    cout << "\n[!] Crupier se da otra carta" << endl;
                    temp = baraja.quitarCarta();
                    crupier.agregarCarta(temp); //agregamos carta a la mano del crupier
                    sleep(2); //hacemos una espera de 2 segundos, para que le dé tiempo al usuario a leer la anterior carta obtenida
                    crupier.verMano(); //mostramos mano crupier
                    cout << "\n- Puntuación de Crupier " << crupier.getName() << ": " << crupier << endl; //calculamos puntuaje con la carta obtenida
                }
            }


            // CONDICIONES PARA DETERMINAR RESULTADO
            if (player.calcularPuntuaje() > crupier.calcularPuntuaje()) { //si puntuación jugador > puntiación crupier, gana Jugador
                cout << "\n[!] Jugador " << player.getName() << ", has ganado! " << endl;
                cout << "\n- Puntuación  " << player.getName() << ": " << player.calcularPuntuaje() << endl;
                cout << "\n- Puntuación de Crupier " << crupier.getName() << ": " << crupier << endl;
                historial.actualizarHistorial(name, "ganada"); //actualizamos el historial con el nombre del jugador y el resultado
                return 0;

            } else if ((player.calcularPuntuaje() == 21) && (crupier.calcularPuntuaje() == 21)) { //emptate de 21, salimos del bucle para comprobar qué 21 tiene mayor prioridad
                break;

            } else if (player.calcularPuntuaje() == crupier.calcularPuntuaje()) { //si hay empate de otro número distinto a 21
                cout << "\n[!] Ha habido un empate! Buena partida." << endl;
                historial.actualizarHistorial(name, "empatada"); //actualizamos el historial con el nombre del jugador y el resultado
                break;

            } else if (crupier.calcularPuntuaje() == 21) { //si puntuación crupier es 21
                cout << "\n[-] Tu Puntuación es menor que la del crupier, lo siento, pierdes!" << endl;
                cout << "\n- Puntuación  " << player.getName() << ": " << player.calcularPuntuaje() << endl;
                cout << "\n- Puntuación de Crupier " << crupier.getName() << ": " << crupier << endl;
                historial.actualizarHistorial(name, "perdida"); //actualizamos el historial con el nombre del jugador y el resultado
                break;

            } else if (crupier.calcularPuntuaje() > 21) { //si crupier se pasa de 21
                cout << "\n[!] El crupier se ha pasado de 21!\n\n[+] Jugador " << player.getName() <<", has ganado! " << endl;
                cout << "\n- Puntuación  " << player.getName() << ": " << player.calcularPuntuaje() << endl;
                cout << "\n- Puntuación de Crupier " << crupier.getName() << ": " << crupier << endl;
                historial.actualizarHistorial(name, "ganada"); //actualizamos el historial con el nombre del jugador y el resultado
                break;

            } else if (crupier.calcularPuntuaje() < 21){ //si puntuacion crupier menor que 21
                cout << "\n[-] Tu Puntuación es menor que la del crupier, lo siento, pierdes!" << endl;
                cout << "\n- Puntuación  " << player.getName() << ": " << player.calcularPuntuaje() << endl;
                cout << "\n- Puntuación de Crupier " << crupier.getName() << ": " << crupier << endl;
                historial.actualizarHistorial(name, "perdida"); //actualizamos el historial con el nombre del jugador y el resultado
                return 0;
            }


        } else if (opcion == 0){ //si pide otra carta el jugador
            temp = baraja.quitarCarta();
            player.agregarCarta(temp); //agregamos carta a la mano del jugador
            if (player.calcularPuntuaje() > 21) { //calculamos puntuaje, y si se pasa de 21
                cout << "\nTu mano:" << endl;
                player.verMano(); //mostramos mano jugador
                cout << "\nMano del crupier: " << endl;
                crupier.verMano(); //mostramos mano crupier
                cout << "\n[-] Te has pasado de 21, pierdes." << endl; //jugador pierde
                //mostramos puntuaciones finales
                cout << "\n- Puntuación  " << player.getName() << ": " << player.calcularPuntuaje() << endl;
                cout << "\n- Puntuación de Crupier " << crupier.getName() << ": " << crupier << endl;
                historial.actualizarHistorial(name, "perdida"); //actualizamos el historial con el nombre del jugador y el resultado
                break;
            }
            //vuelta al inicio del bucle (si no se ha pasado de 21 el jugador)
        } else { //si el usuario introduce algo distinto de 0 o 1
            cout << "\n[!] Opcion no valida!" << endl;
            return 1; //parar partida y volver al menú, devolviendo 1 indicando que ha habido un error
        }

    } //salida del bucle

    if ((player.calcularPuntuaje() == 21) && (crupier.calcularPuntuaje() == 21)) { //si ambos tienen 21 de puntuación
        //cambiar 21 limpio. y si m paso de 21, ver mano crupier
        //comparar manos
        vector<Carta> mano_player;
        mano_player = player.getMano();
        vector<Carta> mano_crupier;
        mano_crupier = crupier.getMano();

        //Gana el jugador que tenga un 21 natural (Black Jack).
        //si tiene (J, Q o K) + (1 As). Si tiene 1 As -> 2 cartas en total
        if (mano_player.size() == 2 && (mano_player.back().conseguirValor() == 1 or mano_player.begin()->conseguirValor() == 1)) { //Comprobar si el jugador tiene 21 natural (Black Jack)
            cout << "\n[+] Gana el jugador " << player.getName() << " por un 21 natural!" << endl;
            historial.actualizarHistorial(name, "ganada"); //actualizamos el historial con el nombre del jugador y el resultado

        } else if (mano_crupier.size() == 2 && (mano_crupier.back().conseguirValor() == 1 or mano_crupier.begin()->conseguirValor() == 1)) { //Comprobar si el crupier tiene 21 natural (Black Jack)
            cout << "\n[-] Gana el crupier " << crupier.getName() << " por un 21 natural!" << endl;
            historial.actualizarHistorial(name, "perdida"); //actualizamos el historial con el nombre del jugador y el resultado

        } else { //empate de 21 naturales
            cout << "\n[!] Ha habido un empate de 21 Natural!" << endl;
            historial.actualizarHistorial(name, "empatada"); //actualizamos el historial con el nombre del jugador y el resultado
        }

    }
    return 0;
}


int main() {
    int opcion=0; //para almacenar la opción introducida por el usuario


    cout << " _______   __                      __                 _____                      __"       << endl;
    cout << "/       \\ /  |                    /  |               /     |                    /  |"      << endl;
    cout << "$$$$$$$  |$$ |  ______    _______ $$ |   __          $$$$$ |  ______    _______ $$ |   __" << endl;
    cout << "$$ |__$$ |$$ | /      \\  /       |$$ |  /  |            $$ | /      \\  /       |$$ |  /  |"<< endl;
    cout << "$$    $$< $$ | $$$$$$  |/$$$$$$$/ $$ |_/$$/        __   $$ | $$$$$$  |/$$$$$$$/ $$ |_/$$/" << endl;
    cout << "$$$$$$$  |$$ | /    $$ |$$ |      $$   $$<        /  |  $$ | /    $$ |$$ |      $$   $$<"  << endl;
    cout << "$$ |__$$ |$$ |/$$$$$$$ |$$ \\_____ $$$$$$  \\       $$ \\__$$ |/$$$$$$$ |$$ \\_____ $$$$$$  \\" << endl;
    cout << "$$    $$/ $$ |$$    $$ |$$       |$$ | $$  |      $$    $$/ $$    $$ |$$       |$$ | $$  |"<< endl;
    cout << "$$$$$$$/  $$/  $$$$$$$/  $$$$$$$/ $$/   $$/        $$$$$$/   $$$$$$$/  $$$$$$$/ $$/   $$/" << endl;
    cout << "\n";
    cout << "                                                                        By Mario De Juan." << endl;

    //Imprimir menú
    cout << "Bienvenid@ al juego del Black Jack!\n" << endl;

    while (true) {
        try {
            cout << "Seleccione una opción:" << endl;
            cout << "[1] Iniciar partida" << endl;
            cout << "[2] Consultar histórico de partidas" << endl;
            cout << "[3] Instrucciones" << endl;
            cout << "[4] Salir" << endl;

            cout << "\n-> ";
            cin >> opcion; //almacenar opción introducida por el ususario

            if (opcion == 1) { //si el usuario quiere iniciar la partida
                string name;
                cout << "Ingresa el nombre del jugador: ";
                cin >> name;
                juego(name); //llamamos a la función para jugar, pasándole el nombre del jugador como parámetro
                sleep(3); //hacemos un sleep de 3 segundos para que le de tiempo al jugador de observar el resultado de la partida
                cout << "\n\n\n\n" << endl; //limpiar la consola tras la partida

            } else if (opcion == 2) { //usuario quiere ver el historial de partidas
                Historial historial; //creamos el objeto historial justo ahora (en vez de al principio del main) para que abra el archivo "Historico-partidas.txt" con los últimos resultados actualizados
                historial.mostrarHistorial();

            } else if (opcion == 3) { //usuario quiere ver las instrucciones
                cout << "\n*************************************************************\n";
                cout << "*                   REGLAS DEL BLACKJACK                   *\n";
                cout << "*************************************************************\n";
                cout << "* - El objetivo del juego es sumar un valor lo más          *\n";
                cout << "*   próximo a 21 sin pasarse.                               *\n";
                cout << "* - Se juega con barajas inglesas de 52 cartas sin comodines.*\n";
                cout << "* - Las cartas numéricas (2-10) valen su valor nominal.      *\n";
                cout << "* - Las figuras (J, Q, K) valen 10 puntos.                   *\n";
                cout << "* - El As puede valer 1 u 11 puntos, según convenga.         *\n";
                cout << "* - Cada jugador recibe dos cartas al inicio.               *\n";
                cout << "* - Los jugadores pueden pedir más cartas (hit) o           *\n";
                cout << "*   plantarse (stand).                                       *\n";
                cout << "* - Si un jugador supera los 21 puntos, pierde (bust).       *\n";
                cout << "*************************************************************\n";
                cout << "*                   REGLAS DEL CRUPIER                      *\n";
                cout << "*************************************************************\n";
                cout << "* - El crupier sigue reglas fijas y no puede tomar           *\n";
                cout << "*   decisiones arbitrarias.                                  *\n";
                cout << "* - Debe pedir carta si su puntuación es 16 o menos.         *\n";
                cout << "* - Debe plantarse si su puntuación es 17 o más.             *\n";
                cout << "* - Para el crupier, los ases valen 11 mientras no se pase   *\n";
                cout << "*   de 21, y 1 en caso contrario.                            *\n";
                cout << "*************************************************************\n";
                cout << "*                   INFORMACIÓN ADICIONAL                   *\n";
                cout << "*************************************************************\n";
                cout << "* - Cada jugador juega únicamente contra el crupier.         *\n";
                cout << "* - La mejor jugada es un Blackjack (As + carta de valor 10).*\n";
                cout << "* - Un Blackjack gana sobre un 21 conseguido con más         *\n";
                cout << "*   de dos cartas.                                           *\n";
                cout << "*************************************************************\n\n";

            } else if (opcion == 4) { //usuario quiere salir del juego
                return 0;

            } else { //si el usuario introduce una opción inválida, que lance una excepción el código
                throw "[!] Opción inválida!"; //lanza la excepción "[!] Opción inválida!" si el ususario introduce un número no listado en el menú
            }

        } catch (const char* msg) { //atrapa la excepción lanzada de opción inválida de menú
            cout << msg << "\n" << endl; //maneja la excepción (imprimiéndola por pantalla).

        } catch (...) { //atrapa cualquier excepción
            cout << "[!] Ha ocurrido un error!" << endl; //la maneja imprimiéndola
        }
    }

}