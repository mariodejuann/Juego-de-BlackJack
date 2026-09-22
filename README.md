# Blackjack en C++

Implementación del clásico juego de **Blackjack (21)** en C++, desarrollada como proyecto de la asignatura de Programación Orientada a Objetos (POO) en la Universidad San Jorge.

El objetivo del juego es alcanzar una puntuación lo más cercana posible a 21 sin pasarse, jugando contra un crupier controlado por reglas fijas. El proyecto incluye gestión de jugadores, baraja, cartas y un historial persistente de partidas.

## Características

- Partidas completas de Blackjack contra un crupier con reglas automáticas (se planta a partir de 17).
- Sistema de cartas y baraja de 52 cartas con barajado aleatorio.
- Historial de partidas persistente, guardado en archivo (ganadas, perdidas, empatadas).
- Manejo de excepciones con bloques `try-catch` para evitar cierres inesperados ante entradas inválidas.
- Diseño orientado a objetos con herencia (`Crupier` hereda de `Jugador`) y sobrecarga de operadores.

## Estructura del proyecto

```
BlackJack/
├── main.cpp          # Flujo principal del juego
├── Jugador.h/.cpp     # Clase base Jugador (mano, puntuación, etc.)
├── Crupier.h/.cpp     # Hereda de Jugador; reglas específicas del crupier
├── Baraja.h/.cpp      # Gestión de la baraja de 52 cartas
├── Carta.h/.cpp       # Propiedades de una carta (valor, palo)
├── Historial.h/.cpp   # Carga y guardado del historial de partidas
└── CMakeLists.txt     # Configuración de compilación con CMake
```

## Clases principales

### `Jugador`
Representa a un jugador de la partida.
- **Atributos:** `name`, `mano` (vector de `Carta`)
- **Métodos:** `verMano()`, `calcularPuntuaje()`, `agregarCarta(Carta)`, `getName()`, `getMano()`, `listoParaJugar()` *(virtual)*

### `Crupier` (hereda de `Jugador`)
Jugador especial con reglas fijas (se planta con 17 o más).
- Sobrescribe `listoParaJugar()`.
- Sobrecarga el operador `<<` para imprimir su puntuación.

### `Baraja`
Gestiona el mazo de 52 cartas.
- **Métodos:** `barajarCartas()`, `quitarCarta()`, `llenarBaraja()`

### `Carta`
Define una carta individual.
- **Atributos:** `valor` (1-11), `palo`
- **Métodos:** `conseguirValor()`, `mostrarCarta()`

### `Historial`
Gestiona el registro de partidas jugadas.
- **Métodos:** `cargarHistorial()`, `guardarHistorial()`, `actualizarHistorial(string, string)`, `mostrarHistorial()`

## Flujo del juego

1. El jugador introduce su nombre.
2. Se reparten dos cartas iniciales al jugador y al crupier (una de las del crupier queda oculta).
3. El jugador elige entre pedir carta (**hit**) o plantarse (**stand**).
4. Al plantarse el jugador, el crupier revela su carta oculta y sigue pidiendo cartas hasta alcanzar al menos 17 puntos.
5. Se determina el ganador según las reglas del Blackjack.
6. El resultado se guarda en el historial de partidas.

## Manejo de excepciones

El programa usa bloques `try-catch` para capturar entradas inválidas en el menú y errores inesperados, evitando que el juego se cierre bruscamente:

```cpp
} catch (const char* msg) { // atrapa la excepción lanzada de opción inválida de menú
    cout << msg << "\n" << endl;
} catch (...) { // atrapa cualquier excepción
    cout << "[!] Ha ocurrido un error!" << endl;
}
```

## Requisitos

- Compilador compatible con **C++11** o superior (probado con MinGW/GCC en Windows).
- **CMake** 3.9 o superior.
- Sistema operativo **Windows** (el proyecto usa `<windows.h>` y `<unistd.h>` para pausas y control de consola).

## Compilación y ejecución

### Con CMake (recomendado)

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Esto generará el ejecutable `BlackJack.exe`. Para lanzarlo:

```bash
./BlackJack.exe
```

### Con un IDE

El proyecto se desarrolló originalmente en **CLion**, por lo que también se puede abrir directamente como proyecto de CMake desde cualquier IDE compatible (CLion, Visual Studio, VS Code con extensión de CMake, etc.).

## Historial de partidas

Cada partida jugada queda registrada en un archivo de texto (`Historico-partidas.txt`), con el nombre del jugador y el resultado obtenido (ganada, perdida o empatada), permitiendo consultar el historial en partidas posteriores.

## Autor

**Mario De Juan Sánchez Flor**
Estudiante de Doble Grado en Ingeniería en Ciberseguridad e Ingeniería Informática — Universidad San Jorge
[LinkedIn](https://www.linkedin.com/in/mariodejuan)

## Licencia

Proyecto académico desarrollado con fines educativos para la asignatura de Programación Orientada a Objetos (POO).
