/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.h
 * Author: dalva
 *
 * Created on December 2, 2020, 9:46 PM
 */

#ifndef JUEGO_H
#define JUEGO_H

#include "GameBoard.h"
#include "Player.h"

class Juego {
public:
    //Constructor
    Juego();
    //Copia
    Juego(const Juego& orig);
    //Destructor
    virtual ~Juego();
    
    //Con Random decide los turnos del juego
    void randMark(Player*&, Player*&);
    
    //Metodo abstracto puro
    virtual void initGame(Player*&, Player*&);
    
    bool validarGanador(char);
    
    bool validarMovimiento(int, int);
    
protected:
    GameBoard* tablero;
    int numJugadas;
};

#endif /* JUEGO_H */

