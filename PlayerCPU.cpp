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
#include "AdminJugadores.h"

PlayerCPU::PlayerCPU() {
    this->nombre = "JArchitect";
    this->marca = '.';
    this->puntuacion = 0;
}

PlayerCPU::PlayerCPU(const PlayerCPU& orig) {
}

PlayerCPU::~PlayerCPU() {
}

bool PlayerCPU::validarTablero(string tablero, char enemyMark) {

    if (tablero[0] == enemyMark && tablero[1] == enemyMark && tablero[2] == '.') {
        return true;
    } else if (tablero[1] == enemyMark && tablero[2] == enemyMark && tablero[0] == '.') {
        return true;
    } else if (tablero[0] == enemyMark && tablero[2] == enemyMark && tablero[1] == '.') {
        return true;
    } else if (tablero[3] == enemyMark && tablero[4] == enemyMark && tablero[5] == '.') {
        return true;
    } else if (tablero[4] == enemyMark && tablero[5] == enemyMark && tablero[3] == '.') {
        return true;
    } else if (tablero[3] == enemyMark && tablero[5] == enemyMark && tablero[4] == '.') {
        return true;
    } else if (tablero[6] == enemyMark && tablero[7] == enemyMark && tablero[8] == '.') {
        return true;
    } else if (tablero[7] == enemyMark && tablero[8] == enemyMark && tablero[6] == '.') {
        return true;
    } else if (tablero[6] == enemyMark && tablero[8] == enemyMark && tablero[7] == '.') {
        return true;
    } else if (tablero[0] == enemyMark && tablero[3] == enemyMark && tablero[6] == '.') {
        return true;
    } else if (tablero[3] == enemyMark && tablero[6] == enemyMark && tablero[0] == '.') {
        return true;
    } else if (tablero[0] == enemyMark && tablero[6] == enemyMark && tablero[3] == '.') {
        return true;
    } else if (tablero[1] == enemyMark && tablero[4] == enemyMark && tablero[7] == '.') {
        return true;
    } else if (tablero[4] == enemyMark && tablero[7] == enemyMark && tablero[1] == '.') {
        return true;
    } else if (tablero[1] == enemyMark && tablero[7] == enemyMark && tablero[4] == '.') {
        return true;
    } else if (tablero[2] == enemyMark && tablero[5] == enemyMark && tablero[8] == '.') {
        return true;
    } else if (tablero[5] == enemyMark && tablero[8] == enemyMark && tablero[2] == '.') {
        return true;
    } else if (tablero[2] == enemyMark && tablero[8] == enemyMark && tablero[5] == '.') {
        return true;
    } else if (tablero[0] == enemyMark && tablero[4] == enemyMark && tablero[8] == '.') {
        return true;
    } else if (tablero[4] == enemyMark && tablero[8] == enemyMark && tablero[0] == '.') {
        return true;
    } else if (tablero[0] == enemyMark && tablero[8] == enemyMark && tablero[4] == '.') {
        return true;
    } else if (tablero[6] == enemyMark && tablero[4] == enemyMark && tablero[2] == '.') {
        return true;
    } else if (tablero[4] == enemyMark && tablero[2] == enemyMark && tablero[6] == '.') {
        return true;
    } else if (tablero[6] == enemyMark && tablero[2] == enemyMark && tablero[4] == '.') {
        return true;
    } else {
        return false;
    }

}

Mark PlayerCPU::defendiendo(string tablero, char enemyMark) {

    Mark marca;

    if (tablero[0] == enemyMark && tablero[1] == enemyMark && tablero[2] == '.') {
        marca.setFila(0);
        marca.setColumna(2);
        return marca;
    } else if (tablero[1] == enemyMark && tablero[2] == enemyMark && tablero[0] == '.') {
        marca.setFila(0);
        marca.setColumna(0);
        return marca;
    } else if (tablero[0] == enemyMark && tablero[2] == enemyMark && tablero[1] == '.') {
        marca.setFila(0);
        marca.setColumna(1);
        return marca;
    } else if (tablero[3] == enemyMark && tablero[4] == enemyMark && tablero[5] == '.') {
        marca.setFila(1);
        marca.setColumna(2);
        return marca;
    } else if (tablero[4] == enemyMark && tablero[5] == enemyMark && tablero[3] == '.') {
        marca.setFila(1);
        marca.setColumna(0);
        return marca;
    } else if (tablero[3] == enemyMark && tablero[5] == enemyMark && tablero[4] == '.') {
        marca.setFila(1);
        marca.setColumna(1);
        return marca;
    } else if (tablero[6] == enemyMark && tablero[7] == enemyMark && tablero[8] == '.') {
        marca.setFila(2);
        marca.setColumna(2);
        return marca;
    } else if (tablero[7] == enemyMark && tablero[8] == enemyMark && tablero[6] == '.') {
        marca.setFila(2);
        marca.setColumna(0);
        return marca;
    } else if (tablero[6] == enemyMark && tablero[8] == enemyMark && tablero[7] == '.') {
        marca.setFila(2);
        marca.setColumna(1);
        return marca;
    } else if (tablero[0] == enemyMark && tablero[3] == enemyMark && tablero[6] == '.') {
        marca.setFila(2);
        marca.setColumna(0);
        return marca;
    } else if (tablero[3] == enemyMark && tablero[6] == enemyMark && tablero[0] == '.') {
        marca.setFila(0);
        marca.setColumna(0);
        return marca;
    } else if (tablero[0] == enemyMark && tablero[6] == enemyMark && tablero[3] == '.') {
        marca.setFila(1);
        marca.setColumna(0);
        return marca;
    } else if (tablero[1] == enemyMark && tablero[4] == enemyMark && tablero[7] == '.') {
        marca.setFila(2);
        marca.setColumna(1);
        return marca;
    } else if (tablero[4] == enemyMark && tablero[7] == enemyMark && tablero[1] == '.') {
        marca.setFila(0);
        marca.setColumna(1);
        return marca;
    } else if (tablero[1] == enemyMark && tablero[7] == enemyMark && tablero[4] == '.') {
        marca.setFila(2);
        marca.setColumna(1);
        return marca;
    } else if (tablero[2] == enemyMark && tablero[5] == enemyMark && tablero[8] == '.') {
        marca.setFila(2);
        marca.setColumna(2);
        return marca;
    } else if (tablero[5] == enemyMark && tablero[8] == enemyMark && tablero[2] == '.') {
        marca.setFila(0);
        marca.setColumna(2);
        return marca;
    } else if (tablero[2] == enemyMark && tablero[8] == enemyMark && tablero[5] == '.') {
        marca.setFila(1);
        marca.setColumna(2);
        return marca;
    } else if (tablero[0] == enemyMark && tablero[4] == enemyMark && tablero[8] == '.') {
        marca.setFila(2);
        marca.setColumna(2);
        return marca;
    } else if (tablero[4] == enemyMark && tablero[8] == enemyMark && tablero[0] == '.') {
        marca.setFila(0);
        marca.setColumna(0);
        return marca;
    } else if (tablero[0] == enemyMark && tablero[8] == enemyMark && tablero[4] == '.') {
        marca.setFila(2);
        marca.setColumna(1);
        return marca;
    } else if (tablero[6] == enemyMark && tablero[4] == enemyMark && tablero[2] == '.') {
        marca.setFila(0);
        marca.setColumna(2);
        return marca;
    } else if (tablero[4] == enemyMark && tablero[2] == enemyMark && tablero[6] == '.') {
        marca.setFila(2);
        marca.setColumna(0);
        return marca;
    } else if (tablero[6] == enemyMark && tablero[2] == enemyMark && tablero[4] == '.') {
        marca.setFila(1);
        marca.setColumna(1);
        return marca;
    }
}

Mark PlayerCPU::atacando(string tablero, char myMark) {

    Mark marca;

    if (tablero[0] == myMark && tablero[1] == myMark && tablero[2] == '.') {
        marca.setFila(0);
        marca.setColumna(2);
        return marca;
    } else if (tablero[1] == myMark && tablero[2] == myMark && tablero[0] == '.') {
        marca.setFila(0);
        marca.setColumna(0);
        return marca;
    } else if (tablero[0] == myMark && tablero[2] == myMark && tablero[1] == '.') {
        marca.setFila(0);
        marca.setColumna(1);
        return marca;
    } else if (tablero[3] == myMark && tablero[4] == myMark && tablero[5] == '.') {
        marca.setFila(1);
        marca.setColumna(2);
        return marca;
    } else if (tablero[4] == myMark && tablero[5] == myMark && tablero[3] == '.') {
        marca.setFila(1);
        marca.setColumna(0);
        return marca;
    } else if (tablero[3] == myMark && tablero[5] == myMark && tablero[4] == '.') {
        marca.setFila(1);
        marca.setColumna(1);
        return marca;
    } else if (tablero[6] == myMark && tablero[7] == myMark && tablero[8] == '.') {
        marca.setFila(2);
        marca.setColumna(2);
        return marca;
    } else if (tablero[7] == myMark && tablero[8] == myMark && tablero[6] == '.') {
        marca.setFila(2);
        marca.setColumna(0);
        return marca;
    } else if (tablero[6] == myMark && tablero[8] == myMark && tablero[7] == '.') {
        marca.setFila(2);
        marca.setColumna(1);
        return marca;
    } else if (tablero[0] == myMark && tablero[3] == myMark && tablero[6] == '.') {
        marca.setFila(2);
        marca.setColumna(0);
        return marca;
    } else if (tablero[3] == myMark && tablero[6] == myMark && tablero[0] == '.') {
        marca.setFila(0);
        marca.setColumna(0);
        return marca;
    } else if (tablero[0] == myMark && tablero[6] == myMark && tablero[3] == '.') {
        marca.setFila(1);
        marca.setColumna(0);
        return marca;
    } else if (tablero[1] == myMark && tablero[4] == myMark && tablero[7] == '.') {
        marca.setFila(2);
        marca.setColumna(1);
        return marca;
    } else if (tablero[4] == myMark && tablero[7] == myMark && tablero[1] == '.') {
        marca.setFila(0);
        marca.setColumna(1);
        return marca;
    } else if (tablero[1] == myMark && tablero[7] == myMark && tablero[4] == '.') {
        marca.setFila(2);
        marca.setColumna(1);
        return marca;
    } else if (tablero[2] == myMark && tablero[5] == myMark && tablero[8] == '.') {
        marca.setFila(2);
        marca.setColumna(2);
        return marca;
    } else if (tablero[5] == myMark && tablero[8] == myMark && tablero[2] == '.') {
        marca.setFila(0);
        marca.setColumna(2);
        return marca;
    } else if (tablero[2] == myMark && tablero[8] == myMark && tablero[5] == '.') {
        marca.setFila(1);
        marca.setColumna(2);
        return marca;
    } else if (tablero[0] == myMark && tablero[4] == myMark && tablero[8] == '.') {
        marca.setFila(2);
        marca.setColumna(2);
        return marca;
    } else if (tablero[4] == myMark && tablero[8] == myMark && tablero[0] == '.') {
        marca.setFila(0);
        marca.setColumna(0);
        return marca;
    } else if (tablero[0] == myMark && tablero[8] == myMark && tablero[4] == '.') {
        marca.setFila(2);
        marca.setColumna(1);
        return marca;
    } else if (tablero[6] == myMark && tablero[4] == myMark && tablero[2] == '.') {
        marca.setFila(0);
        marca.setColumna(2);
        return marca;
    } else if (tablero[4] == myMark && tablero[2] == myMark && tablero[6] == '.') {
        marca.setFila(2);
        marca.setColumna(0);
        return marca;
    } else if (tablero[6] == myMark && tablero[2] == myMark && tablero[4] == '.') {
        marca.setFila(1);
        marca.setColumna(1);
        return marca;

    } else {

        if (tablero[4] == '.') {
            marca.setFila(1);
            marca.setColumna(1);
            return marca;

        } else if (tablero[0] == '.') {
            marca.setFila(0);
            marca.setColumna(0);
            return marca;

        } else if (tablero[2] == '.') {
            marca.setFila(0);
            marca.setColumna(2);
            return marca;

        } else if (tablero[6] == '.') {
            marca.setFila(2);
            marca.setColumna(0);
            return marca;
        
        } else if (tablero[8] == '.'){
            marca.setFila(2);
            marca.setColumna(2);
            return marca;
        
        }else{
            
            int num = 1 + (rand() % 9);
            
            while(tablero[num-1] != '.'){
                num = 1 + (rand() % 9);
            }
            
            switch(num){
                
                case 1:{
                    marca.setFila(0);
                    marca.setColumna(0);
                    break;
                
                }case 2:{
                    marca.setFila(0);
                    marca.setColumna(1);
                    break;
                
                }case 3:{
                    marca.setFila(0);
                    marca.setColumna(2);
                    break;
                
                }case 4:{
                    marca.setFila(1);
                    marca.setFila(0);
                    break;
                
                }case 5:{
                    marca.setFila(1);
                    marca.setColumna(1);
                    break;
                
                }case 6:{
                    marca.setFila(1);
                    marca.setColumna(2);
                    break;
                
                }case 7:{
                    marca.setFila(2);
                    marca.setColumna(0);
                    break;
                
                }case 8:{
                    marca.setFila(2);
                    marca.setColumna(1);
                    break;
                
                }case 9:{
                    marca.setFila(2);
                    marca.setColumna(2);
                }
            }
            
            
            return marca;
        }
    }
}