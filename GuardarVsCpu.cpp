/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GuardarVsCpu.cpp
 * Author: dalva
 * 
 * Created on December 21, 2020, 9:23 PM
 */

#include "GuardarVsCpu.h"

GuardarVsCpu::GuardarVsCpu() {
}

GuardarVsCpu::GuardarVsCpu(const GuardarVsCpu& orig) {
}

GuardarVsCpu::~GuardarVsCpu() {
}

void GuardarVsCpu::guardarPartidaActual(GameBoard* tablero, Player* jugador, PlayerCPU* maquina, int jugadas) {

    salvarPartida.open("JuegoCPU.txt", ofstream::out | ofstream::trunc);

    if (salvarPartida.is_open()) {

        salvarPartida << jugador->getNombre() << endl;
        salvarPartida << maquina->getNombre() << endl;
        salvarPartida << jugador->getMarca() << endl;
        salvarPartida << maquina->getMarca() << endl;
        salvarPartida << jugador->getPuntuacion() << endl;
        salvarPartida << maquina->getPuntuacion() << endl;
        salvarPartida << jugadas << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char marc = tablero->getTablero()->getPosValueMatrix(i, j);

                salvarPartida << marc;
            }

            salvarPartida << endl;
        }

    }

    salvarPartida.close();
}

JuegoCpu* GuardarVsCpu::cargarPartida() {

    lecturaPartida.open("JuegoCPU.txt");
    JuegoCpu* game;

    if (lecturaPartida.is_open()) {

        PlayerHumano* p1;
        PlayerCPU* p2;

        string nombre = "";
        char marca1, marca2;
        int punt1 = 0;
        int punt2 = 0;
        int numJugadas = 0;

        //lee primer nombre
        lecturaPartida >> nombre;
        p1 = new PlayerHumano(nombre);
        //lee segundo nombre
        lecturaPartida >> nombre;
        p2 = new PlayerCPU();

        //lee las marcas de los jugadores
        lecturaPartida >> marca1;
        lecturaPartida >> marca2;

        p1->setMarca(marca1);
        p2->setMarca(marca2);

        //lee las puntuaciones de los jugadores
        lecturaPartida >> punt1;
        lecturaPartida >> punt2;

        p1->setPuntuacion(punt1);
        p2->setPuntuacion(punt2);

        //instancia el juego y estableces jugadores y num jugadas
        game = new JuegoCpu();
        game->setPlayers(p1, p2);

        lecturaPartida >> numJugadas;
        game->setNumJugadas(numJugadas);

        //lee la matriz desde el archivo
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char marc;
                lecturaPartida >> marc;

                game->tablero->getTablero()->setPosValueMatrix(i, j, marc);
            }
        }

    }

    lecturaPartida.close();

    return game;
}