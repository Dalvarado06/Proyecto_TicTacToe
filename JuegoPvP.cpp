/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JuegoPvP.cpp
 * Author: dalva
 * 
 * Created on December 6, 2020, 3:33 PM
 */

#include "JuegoPvP.h"
#include "PlayerHumano.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

JuegoPvP::JuegoPvP() : Juego() {
}

JuegoPvP::JuegoPvP(const JuegoPvP& orig) {
}

JuegoPvP::~JuegoPvP() {
}

void JuegoPvP::initGame(Player* &jugador1, Player* &jugador2) {

    randMark(jugador1, jugador2);

    if (jugador1->getMarca() == 'X') {
        cout << "El jugador " << jugador1->getNombre() << "juega primero"
                << endl << endl;
    } else {
        cout << "El jugador " << jugador2->getNombre() << "juega primero"
                << endl << endl;
    }

    bool flag = true;


    cout << "El juego ha comenzado: " << endl << endl;

    cout << "Este es el tablero inicial: " << endl << endl;
    tablero->getTablero()->printMatrix();

    int fila = 0;
    int columna = 0;

    while (flag) {

        if (numJugadas == 0 || numJugadas % 2 != 0 && jugador1->getMarca() == 'X') {

            cout << "El tablero esta asi: " << endl << endl;
            tablero->getTablero()->printMatrix();


            cout << "Jugador " << jugador1->getNombre() << " ingrese la fila: ";
            cin >> fila;
            cout << endl << endl;

            cout << "Jugador " << jugador1->getNombre() << " ingrese la columna: ";
            cin >> columna;
            cout << endl << endl;

            bool canDo = validarMovimiento(fila, columna);

            while (!canDo) {
                cout << "Jugador " << jugador1->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador1->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                canDo = validarMovimiento(fila, columna);
            }


            tablero->getTablero()->setPosValueMatrix(fila, columna, jugador1->getMarca());


            bool gano = validarGanador(jugador1->getMarca());

            if (gano) {
                 cout << "El jugador " << jugador1->getNombre() << "gano" << endl;
                flag = false;
                int score = jugador1->getPuntuacion() + 1;
                jugador1->setPuntuacion(score);
            }


        } else if (numJugadas == 0 || numJugadas % 2 != 0 && jugador2->getMarca() == 'X') {

            cout << "El tablero esta asi: " << endl << endl;
            tablero->getTablero()->printMatrix();


            cout << "Jugador " << jugador2->getNombre() << " ingrese la fila: ";
            cin >> fila;
            cout << endl << endl;

            cout << "Jugador " << jugador2->getNombre() << " ingrese la columna: ";
            cin >> columna;
            cout << endl << endl;

            bool canDo = validarMovimiento(fila, columna);

            while (!canDo) {
                cout << "Jugador " << jugador2->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador2->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                canDo = validarMovimiento(fila, columna);
            }


            tablero->getTablero()->setPosValueMatrix(fila, columna, jugador2->getMarca());


            bool gano = validarGanador(jugador2->getMarca());

            if (gano) {
                flag = false;
                cout << "El jugador " << jugador2->getNombre() << "gano" << endl;
                int score = jugador2->getPuntuacion() + 1;
                jugador2->setPuntuacion(score);
            }



        } else if (numJugadas != 0 || numJugadas % 2 == 0 && jugador1->getMarca() == '0') {

            cout << "Jugador " << jugador1->getNombre() << " ingrese la fila: ";
            cin >> fila;
            cout << endl << endl;

            cout << "Jugador " << jugador1->getNombre() << " ingrese la columna: ";
            cin >> columna;
            cout << endl << endl;

            bool canDo = validarMovimiento(fila, columna);

            while (!canDo) {
                cout << "Jugador " << jugador1->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador1->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                canDo = validarMovimiento(fila, columna);
            }

            tablero->getTablero()->setPosValueMatrix(fila, columna, jugador1->getMarca());

            bool gano = validarGanador(jugador1->getMarca());

            if (gano) {
                flag = false;
                cout << "El jugador " << jugador1->getNombre() << "gano" << endl;
                int score = jugador1->getPuntuacion() + 1;
                jugador1->setPuntuacion(score);
            }

        } else {

            cout << "El tablero esta asi: " << endl << endl;
            tablero->getTablero()->printMatrix();


            cout << "Jugador " << jugador2->getNombre() << " ingrese la fila: ";
            cin >> fila;
            cout << endl << endl;

            cout << "Jugador " << jugador2->getNombre() << " ingrese la columna: ";
            cin >> columna;
            cout << endl << endl;

            bool canDo = validarMovimiento(fila, columna);

            while (!canDo) {
                cout << "Jugador " << jugador2->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador2->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                canDo = validarMovimiento(fila, columna);
            }


            tablero->getTablero()->setPosValueMatrix(fila, columna, jugador2->getMarca());


            bool gano = validarGanador(jugador2->getMarca());

            if (gano) {
                flag = false;
                cout << "El jugador " << jugador2->getNombre() << "gano" << endl;
                int score = jugador2->getPuntuacion() + 1;
                jugador2->setPuntuacion(score);
            }

        }

    }

    delete tablero;
}

//void JuegoPvP::setPlayers(PlayerHumano* j1, PlayerHumano* j2) {
//
//    jugador1 = new PlayerHumano(j1);
//    jugador2 = new PlayerHumano(j2);
//
//}