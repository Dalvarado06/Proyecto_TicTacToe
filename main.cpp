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
#include <vector>
#include "Player.h"
#include "PlayerHumano.h"
#include "PlayerCPU.h"
#include "Mark.h"
#include "Juego.h"

using namespace std;

int menu();

/*
 * 
 */
int main(int argc, char** argv) {
    
    vector<PlayerHumano*> jugadoresRegistrados;
    

//    Player* jugador1 = new PlayerHumano("Daniel");
//    Player* maquina = new PlayerCPU();
//    
//    Juego* ticTacToe = new Juego();
//    
//    cout << jugador1->getMarca() << " " << maquina->getMarca() << endl << endl;
//    
//    ticTacToe->randMark(jugador1, maquina);
//    
//    cout << jugador1->getMarca() << " " << maquina->getMarca() << endl << endl;
//    
//    delete jugador1;
//    delete maquina;
//    delete ticTacToe;
    
    
    int opcion = 0;
    
    while(opcion != 5){
        
        switch((opcion = menu())){
            
            case 1:{
                
                break;
            
            }case 2:{
                
                break;
            
            }case 3:{
                
                break;
            
            }case 4:{
                
                break;
            
            }case 5:{
                cout << "Ha salido del programa" << endl; 
                break;
            }
        }
    }
    
    
    return 0;
}

int menu(){
    
    int opcion = 0;
    
    do{
        
        cout << "------TIC TAC TOE------" << endl
             << "1. Registrar Jugadores" << endl
             << "2. Nuevo Juego PVP" << endl
             << "3. Nuevo Juego vs CPU" << endl
             << "4. Resumir ultima partida" << endl
             << "5. Salir y guardar" << endl
             << "Ingrese su opcion: ";
        
        cin >> opcion;
        cout << endl;
        
    }while(opcion > 3 || opcion < 1);
    
    
    return opcion;
}