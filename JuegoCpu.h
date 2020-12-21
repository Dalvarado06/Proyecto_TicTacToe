/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JuegoCpu.h
 * Author: dalva
 *
 * Created on December 20, 2020, 4:15 PM
 */

#ifndef JUEGOCPU_H
#define JUEGOCPU_H

#include "Juego.h"
#include "PlayerHumano.h"
#include "PlayerCPU.h"
#include "SymCharMatrix.h"
#include "Player.h"
#include "HistorialJugadas.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class GuardarVsCpu;

class JuegoCpu : public Juego {
public:

    JuegoCpu();

    JuegoCpu(const JuegoCpu& orig);

    virtual ~JuegoCpu();

    virtual void initGame();

    virtual void reInitGame();
    
    void setPlayers(PlayerHumano*, PlayerCPU*);
    
    string matrixToString(SymCharMatrix*);

private:
    PlayerHumano* jugador;
    PlayerCPU* maquina;
    friend class GuardarVsCpu;
};

#endif /* JUEGOCPU_H */

