/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AdminJugadores.cpp
 * Author: dalva
 * 
 * Created on December 6, 2020, 6:22 PM
 */

#include "AdminJugadores.h"
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

AdminJugadores::AdminJugadores() {
}

AdminJugadores::AdminJugadores(const AdminJugadores& orig) {
}

AdminJugadores::~AdminJugadores() {
}

void AdminJugadores::guardarJugadores(vector<PlayerHumano*> lista){
    
    ofstream outPut;
    
    outPut.open("jugadoresTicTacToe.txt", ofstream::out | ofstream::trunc);
    
    if(outPut.is_open()){
        
        for(int i = 0; i < lista.size(); i++){
            
            Player* p = lista[i];
            
            outPut << p->getNombre() << endl;
            
        }
        
    }
    
    outPut.close();
}

vector<PlayerHumano*> AdminJugadores::leerJugadores(){
    
    ifstream input;
    vector<PlayerHumano*> listaJugadores;
    
    input.open("jugadoresTicTacToe.txt");
    
    
    if(input.is_open()){
        
        string buffer = "";
        
        while(getline(input, buffer)){          
            
            PlayerHumano* p = new PlayerHumano(buffer);
            
            listaJugadores.push_back(p);
            
        }
    }
    
    input.close();
    
    
    return listaJugadores;
}