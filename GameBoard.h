/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameBoard.h
 * Author: dalva
 *
 * Created on December 2, 2020, 6:55 PM
 */

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "SymCharMatrix.h"

class GameBoard {
public:
    //constructor
    GameBoard();
    //copia
    GameBoard(const GameBoard& orig);
    //destructor
    virtual ~GameBoard();
    
    //regresa el tablero del juego
    SymCharMatrix* getTablero();
    
private:
    
    SymCharMatrix* tablero;
};

#endif /* GAMEBOARD_H */

