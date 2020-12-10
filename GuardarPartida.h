/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GuardarPartida.h
 * Author: dalva
 *
 * Created on December 8, 2020, 8:19 PM
 */

#ifndef GUARDARPARTIDA_H
#define GUARDARPARTIDA_H

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cout;
using std::endl;

#include "Juego.h"
#include "Player.h"


class GuardarPartida {
public:
    GuardarPartida();

    GuardarPartida(const GuardarPartida& orig);

    virtual ~GuardarPartida();

    virtual void guardarPartidaActual(GameBoard*, Player*, Player*, int)=0;
    
    virtual Juego* cargarPartida()=0;


protected:
    ifstream lecturaPartida;
    ofstream salvarPartida;
};

#endif /* GUARDARPARTIDA_H */

