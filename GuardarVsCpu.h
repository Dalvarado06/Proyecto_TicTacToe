/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GuardarVsCpu.h
 * Author: dalva
 *
 * Created on December 21, 2020, 9:23 PM
 */

#ifndef GUARDARVSCPU_H
#define GUARDARVSCPU_H

#include "JuegoCpu.h"
#include "PlayerCPU.h"
#include "PlayerHumano.h"
#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::endl;

class JuegoCpu;

class GuardarVsCpu {
public:
    
    GuardarVsCpu();
    
    GuardarVsCpu(const GuardarVsCpu& orig);
    
    virtual ~GuardarVsCpu();
    
    JuegoCpu* cargarPartida();
    
    void guardarPartidaActual(GameBoard*, Player*, PlayerCPU*, int);

private:
    ofstream salvarPartida;
    ifstream lecturaPartida;
};

#endif /* GUARDARVSCPU_H */

