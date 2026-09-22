cmake_minimum_required(VERSION 3.9)
project(BlackJack)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(BlackJack main.cpp
        Jugador.cpp
        Jugador.h
        Crupier.cpp
        Crupier.h
        Historial.cpp
        Historial.h
        Carta.cpp
        Carta.h
        Baraja.cpp
        Baraja.h)
