#include "Historial.h"

Historial::Historial() { //constructor por defecto. Para cargar el archivo
    ifstream archivo("Historico-partidas.txt"); //intentamos abrir el archivo del historial de partidas en modo lectura

    if (archivo.is_open() == false) { //si el archivo no existe, salimos para que no intente leer algo que no existe
        return;
    }

    //Lee todo el archivo de historial y mete "cada línea" en el vector de historial
    HistorialJugador jugador; //declaramos un struct del historial de datos para un jugador, con el nombre "jugador"
    while (archivo >> jugador.nombre >> jugador.ganadas >> jugador.perdidas >> jugador.empatadas) { //mientras haya una línea con datos, mete cada dato por posición, separados por espacios, en su respectiva variable del struct
        historial.push_back(jugador); //que meta todo el struct del jugador en el vector de "historial"
    }
    archivo.close(); //cierra el archivo
}

int Historial::buscarJugador(const string &nombre) { //sólo la llama la función "actualizarHistorial()"
    for (int i = 0; i < historial.size(); ++i) { //bucle desde 0 hasta el tamaño del vector "historial"
        if (historial[i].nombre == nombre) { //si el nombre del vector coincide con el nombre pasado por referencia a la función
            return i; //devolver el índice
        }
    }
    return -1; //si no encuentra el nombre devuelve -1
}

void Historial::guardarHistorial() { //sólo la llama la función "actualizarHistorial()"
    ofstream archivo("Historico-partidas.txt"); //carga el archivo de historial en modo "truncamiento" de forma que lo sobreescribirá
    for (const HistorialJugador& jugador : historial) { //para cada struct del tipo "jugador" en el vector "historial"
        archivo << jugador.nombre << " " << jugador.ganadas << " " << jugador.perdidas << " " << jugador.empatadas << "\n"; //que escriba todos los datos dentro de cada struct separados por espacios en el archivo. Una línea por cada struct en el vector "historial".
    }
    archivo.close(); //cerramos el archivo
}

void Historial::actualizarHistorial(const string &nombre, const string &resultado) { //recibe una referencia constante al nombre del jugador y al resultado de la partida
    int indice = buscarJugador(nombre);

    if (indice == -1) { //si el jugador no existe, lo agregamos con valores iniciales
        historial.push_back({nombre, 0, 0, 0}); //creamos struct con valores iniciales y el nombre del jugador
        indice = historial.size() - 1; //setea el índice a el último elemento del vector "historial"
    }

    //actualizamos el resultado según corresponda
    if (resultado == "ganada") {
        historial[indice].ganadas++; //+1 a partidas ganadas del struct de ese jugador
    } else if (resultado == "perdida") {
        historial[indice].perdidas++; //+1 a partidas perdidas del struct de ese jugador
    } else if (resultado == "empatada") {
        historial[indice].empatadas++; //+1 a partidas empatadas del struct de ese jugador
    }

    guardarHistorial(); //guardamos los cambios en el archivo
}

void Historial::mostrarHistorial() { //imprime el historial directamente desde el vector "historial"
    cout << "\n*****************************************************\n";
    cout << "*              HISTÓRICO DE PARTIDAS               *\n";
    cout << "*****************************************************\n";
    for (const HistorialJugador& jugador : historial) { //para cada struct del tipo "jugador" en el vector "historial"
        cout << "* " << jugador.nombre << " | " << "Ganadas: " << jugador.ganadas << " | " << "Perdidas: " << jugador.perdidas << " | " << "Empatadas: " << jugador.empatadas << " *\n"; //que imprima todos los datos dentro de cada struct separados por "|" en el archivo. Una línea por cada struct en el vector "historial".
    }
    cout << "*****************************************************\n\n";
}




