/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AdminJugadores.h
 * Author: dalva
 *
 * Created on December 6, 2020, 6:22 PM
 */

#ifndef ADMINJUGADORES_H
#define ADMINJUGADORES_H

#include <vector>
#include "PlayerHumano.h"
#include <fstream>
#include "Player.h"

using std::ofstream;
using std::ifstream;
using std::vector;

class AdminJugadores {
public:
    
    AdminJugadores();
    
    AdminJugadores(const AdminJugadores& orig);
    
    virtual ~AdminJugadores();
    
    vector<PlayerHumano*> leerJugadores();
    
    void guardarJugadores(vector<PlayerHumano*>);
    
    
private:

};

#endif /* ADMINJUGADORES_H */

