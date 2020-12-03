/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dalva
 *
 * Created on December 2, 2020, 6:24 PM
 */

#include <cstdlib>
#include <iostream>
#include "GameBoard.h"
#include "Player.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    GameBoard* juego;
    
    juego = new GameBoard();
    
    juego->getTablero()->printMatrix();
    
    delete juego;
    
    return 0;
}

