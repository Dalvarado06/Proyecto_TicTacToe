/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GuardarPvP.h
 * Author: dalva
 *
 * Created on December 9, 2020, 8:26 PM
 */

#ifndef GUARDARPVP_H
#define GUARDARPVP_H

#include "PlayerHumano.h"
#include "JuegoPvP.h"
#include <fstream>
#include <iostream>
using std::endl;
using std::ifstream;
using std::ofstream;

class JuegoPvP;

class GuardarPvP {
public:
    GuardarPvP();

    GuardarPvP(const GuardarPvP& orig);

    void guardarPartidaActual(GameBoard*, Player*, Player*, int);

    JuegoPvP* cargarPartida();
    
private:
    ifstream lecturaPartida;
    ofstream salvarPartida;
};

#endif /* GUARDARPVP_H */

