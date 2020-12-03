/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: dalva
 * 
 * Created on December 2, 2020, 7:19 PM
 */

#include "Player.h"

Player::Player() {
    nombre = "";
    puntuacion = 0;
    marca = '.';
}

Player::Player(string nombre){
    this->nombre = nombre;
    puntuacion = 0;
    marca = '.';
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

void Player::setNombre(string nombre){
    this->nombre = nombre;
}

string Player::getNombre(){
    return nombre;
}

void Player::setPuntuacion(int puntos){
    puntuacion = puntos;
}

int Player::getPuntuacion(){
    return puntuacion;
}

void Player::setMarca(char marca){
    this->marca = marca;
}

char Player::getMarca(){
    return marca;
}
