/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerHumano.cpp
 * Author: dalva
 * 
 * Created on December 2, 2020, 7:29 PM
 */

#include "PlayerHumano.h"
#include "Player.h"

PlayerHumano::PlayerHumano() {
    this->nombre = "";
    this->marca = '.';
    this->puntuacion = 0;
}

PlayerHumano::PlayerHumano(const PlayerHumano& orig) {
}

PlayerHumano::~PlayerHumano() {
}

PlayerHumano::PlayerHumano(string nombre) : Player(nombre){
    
}
