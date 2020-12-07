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

void Juego::initGame(Player*&jugador1, Player* &jugador2) {

}

bool Juego::validarGanador(char marcaJugador) {

    if (tablero->getTablero()->getPosValueMatrix(0, 0) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(0, 1) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(0, 2) == marcaJugador) {

        return true;

    } else if (tablero->getTablero()->getPosValueMatrix(1, 0) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(1, 1) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(1, 2) == marcaJugador){
        
        return true;
    
    } else if(tablero->getTablero()->getPosValueMatrix(2,0) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(2,1) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(2,2) == marcaJugador){
        
        return true;
    
    }else if(tablero->getTablero()->getPosValueMatrix(0,0) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(1,0) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(2,0) == marcaJugador){
        
        return true;
    
    }else if(tablero->getTablero()->getPosValueMatrix(0,1) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(1,1) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(2,1) == marcaJugador){
        
        return true;
    
    }else if(tablero->getTablero()->getPosValueMatrix(0,2) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(1,2) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(2,2) == marcaJugador){
        
        return true;
    
    }else if(tablero->getTablero()->getPosValueMatrix(0,0) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(1,1) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(2,2) == marcaJugador){
        
        return true;
    
    }else if(tablero->getTablero()->getPosValueMatrix(2,0) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(1,1) == marcaJugador &&
            tablero->getTablero()->getPosValueMatrix(0,2) == marcaJugador){
        
        return true;
    
    }else{
        return false;
    }
}

bool Juego::validarMovimiento(int fila, int columna){
    
    if(fila < 1 || fila > 3 || columna < 1 || columna > 3){
        return false;
    
    }else{
        
        char pos = tablero->getTablero()->getPosValueMatrix(fila, columna);
        
        if(pos == 'X' || pos == '0' || pos == '?'){
            return false;
        }else{
            return true;
        }
    }
}