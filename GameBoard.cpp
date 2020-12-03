/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameBoard.cpp
 * Author: dalva
 * 
 * Created on December 2, 2020, 6:55 PM
 */

#include "GameBoard.h"

GameBoard::GameBoard() {
    tablero = 0;
    tablero = new SymCharMatrix(3);
    tablero->initMatrix();
}

GameBoard::GameBoard(const GameBoard& orig) {
}

GameBoard::~GameBoard() {
}

 //regresa el tablero del juego
SymCharMatrix* GameBoard::getTablero(){
    return tablero;
}
