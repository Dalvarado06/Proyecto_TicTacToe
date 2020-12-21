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
#include <vector>
using std::vector;

class GuardarPvP;

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
    
    //Metodo abstracto
    virtual void initGame();
    
    bool validarGanador(char);
    
    bool validarMovimiento(int, int);
    
    void setNumJugadas(int);
    
    virtual void reInitGame();
    
protected:
    GameBoard* tablero;
    int numJugadas;
    Player* jugador1;
    Player* jugador2;
    friend class GuardarPvP;
};

#endif /* JUEGO_H */

