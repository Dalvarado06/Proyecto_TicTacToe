/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerCPU.h
 * Author: dalva
 *
 * Created on December 2, 2020, 8:43 PM
 */

#ifndef PLAYERCPU_H
#define PLAYERCPU_H

#include "Player.h"
#include "Mark.h"
#include "GameBoard.h"

class PlayerCPU : public Player{
public:
    //Constructor
    PlayerCPU();
    //Copia
    PlayerCPU(const PlayerCPU& orig);
    //Destructor
    virtual ~PlayerCPU();
    
    //metodos de validacion
    bool validarTablero(string, char); 
    
   
    
   //Toma de decisiones
    Mark defendiendo(string, char);
    Mark atacando(string, char);
    
    
private:

};

#endif /* PLAYERCPU_H */

