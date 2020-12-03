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
#include "PlayerHumano.h"
#include "PlayerCPU.h"
#include "Mark.h"
#include "Juego.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Player* jugador1 = new PlayerHumano("Daniel");
    Player* maquina = new PlayerCPU();
    
    Juego* ticTacToe = new Juego();
    
    cout << jugador1->getMarca() << " " << maquina->getMarca() << endl << endl;
    
    ticTacToe->randMark(jugador1, maquina);
    
    cout << jugador1->getMarca() << " " << maquina->getMarca() << endl << endl;
    
    delete jugador1;
    delete maquina;
    delete ticTacToe;
    
    
    return 0;
}

