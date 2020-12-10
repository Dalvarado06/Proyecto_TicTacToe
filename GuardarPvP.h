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

#include "GuardarPartida.h"
#include "PlayerHumano.h"

class GuardarPvP : public GuardarPartida {
public:
    GuardarPvP();

    GuardarPvP(const GuardarPvP& orig);

    virtual void guardarPartidaActual(GameBoard*, Player*, Player*, int);

    virtual Juego* cargarPartida();
    
private:
    
};

#endif /* GUARDARPVP_H */

