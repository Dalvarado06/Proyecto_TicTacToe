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

class JuegoPvP : public Juego{
public:
    JuegoPvP();
    
    JuegoPVP();
    
    JuegoPvP(const JuegoPvP& orig);
    
    virtual ~JuegoPvP();
    
    virtual void initGame(Player*&, Player*&); 
    
    //void setPlayers(PlayerHumano*, PlayerHumano*);
    
private:
    
};

#endif /* JUEGOPVP_H */

