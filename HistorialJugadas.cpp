/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HistorialJugadas.cpp
 * Author: dalva
 * 
 * Created on December 7, 2020, 6:28 PM
 */

#include "HistorialJugadas.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

HistorialJugadas::HistorialJugadas() {
}

HistorialJugadas::HistorialJugadas(const HistorialJugadas& orig) {
}

HistorialJugadas::~HistorialJugadas() {
}

void HistorialJugadas::mostrarHistorial() {

    int size = historial.size();

    for (int i = 0; i < size; i++) {

        int continuar = 0;
        while (continuar == 0) {

            CharMatrix* board = historial[i];

            cout << i + 1 << "# jugada en tablero" << endl;
            board->printMatrix();

            cout << "Presione 1 para continuar: ";
            cin >> continuar;
            cout << endl;

            while (continuar != 1) {
                cout << "Presione 1 para continuar: ";
                cin >> continuar;
                cout << endl;
            }

        }
    }
    cout << "Afuera for historial" << endl << endl;

}

void HistorialJugadas::agregarJugada(CharMatrix* board) {
    CharMatrix* tablero = board;

    historial.push_back(tablero);
}