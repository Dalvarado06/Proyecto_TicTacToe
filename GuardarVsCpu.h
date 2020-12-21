/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GuardarVsCpu.h
 * Author: dalva
 *
 * Created on December 20, 2020, 8:51 PM
 */

#ifndef GUARDARVSCPU_H
#define GUARDARVSCPU_H

#include "GuardarPartida.h"
#include "PlayerCPU.h"
#include "JuegoCpu.h"
#include "PlayerHumano.h"

class GuardarVsCpu : public GuardarPartida{
public:
    
    GuardarVsCpu();
    
    GuardarVsCpu(const GuardarVsCpu& orig);
    
    virtual ~GuardarVsCpu();
    
    virtual void guardarPartidaActual(GameBoard*, Player*, Player*, int);
    
    virtual Juego* cargarPartida();
    
private:

};

#endif /* GUARDARVSCPU_H */

