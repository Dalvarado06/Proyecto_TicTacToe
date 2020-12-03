/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: dalva
 *
 * Created on December 2, 2020, 7:19 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using std::string;

class Player {
public:
    //Constructor
    Player();
    //Copia
    Player(const Player& orig);
    //Destructor
    virtual ~Player();
    
    //constructor sobre cargado
    Player(string);
    
    //Getter y setters
    void setNombre(string);
    
    string getNombre();
    
    void setPuntuacion(int);
    
    int getPuntuacion();
    
    void setMarca(char);
    
    char getMarca();
    
protected:
    string nombre;
    int puntuacion;
    char marca;
};

#endif /* PLAYER_H */

