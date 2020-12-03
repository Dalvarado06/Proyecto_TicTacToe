/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: dalva
 * 
 * Created on December 2, 2020, 9:46 PM
 */

#include "Juego.h"
#include <cstdlib>
#include <ctime>

Juego::Juego() {
    tablero = 0;
    tablero = new GameBoard();
    numJugadas = 0;
}

Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {
    delete tablero;
}

void Juego::randMark(Player*& jugador1, Player*& jugador2) {

    srand(time(0));

    int numero1 = 0;
    int numero2 = 0;

    while (numero1 == numero2) {
        numero1 = 1 + (rand() % 14);
        numero2 = 1 + (rand() % 14);
    }

    if (numero1 > numero2) {
        jugador1->setMarca('X'); 
        jugador2->setMarca('0');

    } else {
        jugador1->setMarca('0');
        jugador2->setMarca('x');
    }
}
