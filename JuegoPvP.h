/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JuegoPvP.h
 * Author: dalva
 *
 * Created on December 6, 2020, 3:33 PM
 */

#ifndef JUEGOPVP_H
#define JUEGOPVP_H

#include "Juego.h"
#include "PlayerHumano.h"
#include "GuardarPvP.h"

class JuegoPvP : public Juego{
public:
    JuegoPvP();
    
    JuegoPVP(Player*, Player*);
    
    JuegoPvP(const JuegoPvP& orig);
    
    virtual ~JuegoPvP();
    
    virtual void initGame();
    
    void setPlayers(Player*, Player*);
    
    virtual void reInitGame();
    
private:
   
};

#endif /* JUEGOPVP_H */

