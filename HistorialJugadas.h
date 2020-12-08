/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HistorialJugadas.h
 * Author: dalva
 *
 * Created on December 7, 2020, 6:28 PM
 */

#ifndef HISTORIALJUGADAS_H
#define HISTORIALJUGADAS_H

#include "SymCharMatrix.h"
#include <vector>
using std::vector;


class HistorialJugadas {
public:
    HistorialJugadas();
    HistorialJugadas(const HistorialJugadas& orig);
    virtual ~HistorialJugadas();
    
    void agregarJugada(CharMatrix*);
    void mostrarHistorial();
    void borrarHistorial();
    
private:
    vector<CharMatrix*> historial;
};

#endif /* HISTORIALJUGADAS_H */

