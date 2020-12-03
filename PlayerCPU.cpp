/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerCPU.cpp
 * Author: dalva
 * 
 * Created on December 2, 2020, 8:43 PM
 */

#include "PlayerCPU.h"

PlayerCPU::PlayerCPU() {
    this->nombre = "JArchitect";
    this->marca = '.';
    this->puntuacion = 0;
}

PlayerCPU::PlayerCPU(const PlayerCPU& orig) {
}

PlayerCPU::~PlayerCPU() {
}

