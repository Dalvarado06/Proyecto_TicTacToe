/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerHumano.h
 * Author: dalva
 *
 * Created on December 2, 2020, 7:29 PM
 */

#ifndef PLAYERHUMANO_H
#define PLAYERHUMANO_H

#include "Player.h"

class PlayerHumano : public Player {
public:
    //Constructor
    PlayerHumano();
    //Copia
    PlayerHumano(const PlayerHumano& orig);
    //Destructor
    virtual ~PlayerHumano();
    //constructor SobreCargado
    PlayerHumano(string);
    
private:

};

#endif /* PLAYERHUMANO_H */

