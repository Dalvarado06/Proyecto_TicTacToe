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
#include "HistorialJugadas.h"

using std::cout;
using std::endl;
using std::cin;

JuegoPvP::JuegoPvP() : Juego() {
    tablero = 0;
    tablero = new GameBoard();
    numJugadas = 0;
    //    jugador1 = new PlayerHumano();
    //    jugador2 = new PlayerHumano();
}

JuegoPvP::JuegoPvP(const JuegoPvP& orig) {
}

JuegoPvP::~JuegoPvP() {
}

void JuegoPvP::setPlayers(Player* jug1, Player* jug2) {

    this->jugador1 = jug1;
    this->jugador2 = jug2;
}

void JuegoPvP::initGame() {

    randMark(jugador1, jugador2);
    bool empate = false;

    if (jugador1->getMarca() == 'X') {
        cout << "'-----> El jugador " << jugador1->getNombre() << " juega primero"
                << endl << endl;

        bool flag = true;
        HistorialJugadas historial;

        cout << "-----> El juego ha comenzado: " << endl << endl;

        int fila = 0;
        int columna = 0;

        while (flag && numJugadas <= 9) {

            cout << "-----> El tablero esta asi: " << endl << endl;
            tablero->getTablero()->printMatrix();


            cout << "Jugador " << jugador1->getNombre() << " ingrese la fila: ";
            cin >> fila;
            cout << endl << endl;

            cout << "Jugador " << jugador1->getNombre() << " ingrese la columna: ";
            cin >> columna;
            cout << endl << endl;

            bool canDo = false;
            canDo = validarMovimiento(fila - 1, columna - 1);

            while (!canDo) {
                cout << "Jugador " << jugador1->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador1->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                canDo = validarMovimiento(fila - 1, columna - 1);
            }


            tablero->getTablero()->setPosValueMatrix(fila - 1, columna - 1, jugador1->getMarca());
            numJugadas = numJugadas + 1;
            historial.agregarJugada(tablero->getTablero());

            bool gano = validarGanador(jugador1->getMarca());

            if (gano) {
                cout << "El jugador " << jugador1->getNombre() << " gano" << endl;
                flag = false;
                int score = jugador1->getPuntuacion() + 1;
                jugador1->setPuntuacion(score);

            } else if (numJugadas == 9) {

                flag = false;
                empate = true;

            } else if (numJugadas < 9) {

                cout << "-----> El tablero esta asi: " << endl << endl;
                tablero->getTablero()->printMatrix();


                cout << "Jugador " << jugador2->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador2->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                bool canDo = false;
                canDo = validarMovimiento(fila - 1, columna - 1);

                while (!canDo) {
                    cout << "Jugador " << jugador2->getNombre() << " ingrese la fila: ";
                    cin >> fila;
                    cout << endl << endl;

                    cout << "Jugador " << jugador2->getNombre() << " ingrese la columna: ";
                    cin >> columna;
                    cout << endl << endl;

                    canDo = validarMovimiento(fila - 1, columna - 1);
                }


                tablero->getTablero()->setPosValueMatrix(fila - 1, columna - 1, jugador2->getMarca());
                numJugadas = numJugadas + 1;
                historial.agregarJugada(tablero->getTablero());

                bool gano = validarGanador(jugador2->getMarca());

                if (gano) {
                    flag = false;
                    cout << "El jugador " << jugador2->getNombre() << " gano" << endl;
                    int score = jugador2->getPuntuacion() + 1;
                    jugador2->setPuntuacion(score);

                } else if (numJugadas <= 7 || numJugadas > 1) {

                    int opcion = 0;
                    cout << "Desea salir de la partida y guardarla (1 = si): ";
                    cin >> opcion;

                    if (opcion == 1) {

                        GuardarPvP save;
                        save.guardarPartidaActual(tablero, jugador1, jugador2, numJugadas);
                        flag = false;
                    }
                }

            }

        }
        if (empate) {
            cout << "-----> El juego termino en empate" << endl << endl;
        }

        int confirm = 0;
        cout << "-----> Desea Mostrar el historial de jugadas? si : 1  :";
        cin >> confirm;
        cout << endl;

        if (confirm == 1) {
            historial.mostrarHistorial();
        }

    } else {
        cout << "-----> El jugador " << jugador2->getNombre() << " juega primero"
                << endl << endl;


        bool flag = true;
        HistorialJugadas historial;

        cout << "-----> El juego ha comenzado: " << endl << endl;

        int fila = 0;
        int columna = 0;


        while (flag && numJugadas <= 9) {

            cout << "-----> El tablero esta asi: " << endl << endl;
            tablero->getTablero()->printMatrix();


            cout << "Jugador " << jugador2->getNombre() << " ingrese la fila: ";
            cin >> fila;
            cout << endl << endl;

            cout << "Jugador " << jugador2->getNombre() << " ingrese la columna: ";
            cin >> columna;
            cout << endl << endl;

            bool canDo = false;
            canDo = validarMovimiento(fila - 1, columna - 1);

            while (!canDo) {
                cout << "Jugador " << jugador2->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador2->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                canDo = validarMovimiento(fila - 1, columna - 1);
            }


            tablero->getTablero()->setPosValueMatrix(fila - 1, columna - 1, jugador2->getMarca());
            numJugadas = numJugadas + 1;
            historial.agregarJugada(tablero->getTablero());

            bool gano = validarGanador(jugador2->getMarca());

            if (gano) {
                flag = false;
                cout << "El jugador " << jugador2->getNombre() << " gano" << endl;
                int score = jugador2->getPuntuacion() + 1;
                jugador2->setPuntuacion(score);

            } else if (numJugadas == 9) {

                flag = false;
                empate = true;

            } else if (numJugadas < 9) {

                cout << "-----> El tablero esta asi: " << endl << endl;
                tablero->getTablero()->printMatrix();

                cout << "Jugador " << jugador1->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador1->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                bool canDo = false;
                canDo = validarMovimiento(fila - 1, columna - 1);

                while (!canDo) {
                    cout << "Jugador " << jugador1->getNombre() << " ingrese la fila: ";
                    cin >> fila;
                    cout << endl << endl;

                    cout << "Jugador " << jugador1->getNombre() << " ingrese la columna: ";
                    cin >> columna;
                    cout << endl << endl;

                    canDo = validarMovimiento(fila - 1, columna - 1);
                }

                tablero->getTablero()->setPosValueMatrix(fila - 1, columna - 1, jugador1->getMarca());
                numJugadas = numJugadas + 1;
                historial.agregarJugada(tablero->getTablero());

                bool gano = validarGanador(jugador1->getMarca());

                if (gano) {
                    flag = false;
                    cout << "-----> El jugador " << jugador1->getNombre() << " gano" << endl;
                    int score = jugador1->getPuntuacion() + 1;
                    jugador1->setPuntuacion(score);
                } else if (numJugadas <= 7 || numJugadas > 1) {

                    int opcion = 0;
                    cout << "Desea salir de la partida y guardarla (1 = si): ";
                    cin >> opcion;

                    if (opcion == 1) {

                        GuardarPvP save;
                        save.guardarPartidaActual(tablero, jugador1, jugador2, numJugadas);
                        flag = false;
                    }
                }
            }
        }

        if (empate) {
            cout << "-----> El juego termino en empate" << endl << endl;
        }

        int confirm = 0;
        cout << "-----> Desea Mostrar el historial de jugadas? si : 1  :";
        cin >> confirm;
        cout << endl;

        if (confirm == 1) {
            historial.mostrarHistorial();
        }

    }

    delete tablero;
}

void JuegoPvP::reInitGame() {

    cout << "Bienvenidos de nuevo" << endl << endl;
    cout << "El tablero quedo asi: " << endl;
    tablero->getTablero()->printMatrix();


    bool empate = false;

    if (jugador1->getMarca() == 'X') {
        cout << "'-----> El jugador " << jugador1->getNombre() << " juega primero"
                << endl << endl;

        bool flag = true;
        HistorialJugadas historial;

        cout << "-----> El juego ha comenzado: " << endl << endl;

        int fila = 0;
        int columna = 0;

        while (flag && numJugadas <= 9) {

            cout << "-----> El tablero esta asi: " << endl << endl;
            tablero->getTablero()->printMatrix();


            cout << "Jugador " << jugador1->getNombre() << " ingrese la fila: ";
            cin >> fila;
            cout << endl << endl;

            cout << "Jugador " << jugador1->getNombre() << " ingrese la columna: ";
            cin >> columna;
            cout << endl << endl;

            bool canDo = false;
            canDo = validarMovimiento(fila - 1, columna - 1);

            while (!canDo) {
                cout << "Jugador " << jugador1->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador1->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                canDo = validarMovimiento(fila - 1, columna - 1);
            }


            tablero->getTablero()->setPosValueMatrix(fila - 1, columna - 1, jugador1->getMarca());
            numJugadas = numJugadas + 1;
            historial.agregarJugada(tablero->getTablero());

            bool gano = validarGanador(jugador1->getMarca());

            if (gano) {
                cout << "El jugador " << jugador1->getNombre() << " gano" << endl;
                flag = false;
                int score = jugador1->getPuntuacion() + 1;
                jugador1->setPuntuacion(score);

            } else if (numJugadas == 9) {

                flag = false;
                empate = true;

            } else if (numJugadas < 9) {

                cout << "-----> El tablero esta asi: " << endl << endl;
                tablero->getTablero()->printMatrix();


                cout << "Jugador " << jugador2->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador2->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                bool canDo = false;
                canDo = validarMovimiento(fila - 1, columna - 1);

                while (!canDo) {
                    cout << "Jugador " << jugador2->getNombre() << " ingrese la fila: ";
                    cin >> fila;
                    cout << endl << endl;

                    cout << "Jugador " << jugador2->getNombre() << " ingrese la columna: ";
                    cin >> columna;
                    cout << endl << endl;

                    canDo = validarMovimiento(fila - 1, columna - 1);
                }


                tablero->getTablero()->setPosValueMatrix(fila - 1, columna - 1, jugador2->getMarca());
                numJugadas = numJugadas + 1;
                historial.agregarJugada(tablero->getTablero());

                bool gano = validarGanador(jugador2->getMarca());

                if (gano) {
                    flag = false;
                    cout << "El jugador " << jugador2->getNombre() << " gano" << endl;
                    int score = jugador2->getPuntuacion() + 1;
                    jugador2->setPuntuacion(score);

                } else if (numJugadas <= 7 || numJugadas > 1) {

                    int opcion = 0;
                    cout << "Desea salir de la partida y guardarla (1 = si): ";
                    cin >> opcion;

                    if (opcion == 1) {

                        GuardarPvP save;
                        save.guardarPartidaActual(tablero, jugador1, jugador2, numJugadas);
                        flag = false;
                    }
                }

            }

        }
        if (empate) {
            cout << "-----> El juego termino en empate" << endl << endl;
        }

        int confirm = 0;
        cout << "-----> Desea Mostrar el historial de jugadas? si : 1  :";
        cin >> confirm;
        cout << endl;

        if (confirm == 1) {
            historial.mostrarHistorial();
        }

    } else {
        cout << "-----> El jugador " << jugador2->getNombre() << " juega primero"
                << endl << endl;


        bool flag = true;
        HistorialJugadas historial;

        cout << "-----> El juego ha comenzado: " << endl << endl;

        int fila = 0;
        int columna = 0;


        while (flag && numJugadas <= 9) {

            cout << "-----> El tablero esta asi: " << endl << endl;
            tablero->getTablero()->printMatrix();


            cout << "Jugador " << jugador2->getNombre() << " ingrese la fila: ";
            cin >> fila;
            cout << endl << endl;

            cout << "Jugador " << jugador2->getNombre() << " ingrese la columna: ";
            cin >> columna;
            cout << endl << endl;

            bool canDo = false;
            canDo = validarMovimiento(fila - 1, columna - 1);

            while (!canDo) {
                cout << "Jugador " << jugador2->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador2->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                canDo = validarMovimiento(fila - 1, columna - 1);
            }


            tablero->getTablero()->setPosValueMatrix(fila - 1, columna - 1, jugador2->getMarca());
            numJugadas = numJugadas + 1;
            historial.agregarJugada(tablero->getTablero());

            bool gano = validarGanador(jugador2->getMarca());

            if (gano) {
                flag = false;
                cout << "El jugador " << jugador2->getNombre() << " gano" << endl;
                int score = jugador2->getPuntuacion() + 1;
                jugador2->setPuntuacion(score);

            } else if (numJugadas == 9) {

                flag = false;
                empate = true;

            } else if (numJugadas < 9) {

                cout << "-----> El tablero esta asi: " << endl << endl;
                tablero->getTablero()->printMatrix();

                cout << "Jugador " << jugador1->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador1->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                bool canDo = false;
                canDo = validarMovimiento(fila - 1, columna - 1);

                while (!canDo) {
                    cout << "Jugador " << jugador1->getNombre() << " ingrese la fila: ";
                    cin >> fila;
                    cout << endl << endl;

                    cout << "Jugador " << jugador1->getNombre() << " ingrese la columna: ";
                    cin >> columna;
                    cout << endl << endl;

                    canDo = validarMovimiento(fila - 1, columna - 1);
                }

                tablero->getTablero()->setPosValueMatrix(fila - 1, columna - 1, jugador1->getMarca());
                numJugadas = numJugadas + 1;
                historial.agregarJugada(tablero->getTablero());

                bool gano = validarGanador(jugador1->getMarca());

                if (gano) {
                    flag = false;
                    cout << "-----> El jugador " << jugador1->getNombre() << " gano" << endl;
                    int score = jugador1->getPuntuacion() + 1;
                    jugador1->setPuntuacion(score);
                } else if (numJugadas <= 7 || numJugadas > 1) {

                    int opcion = 0;
                    cout << "Desea salir de la partida y guardarla (1 = si): ";
                    cin >> opcion;

                    if (opcion == 1) {

                        GuardarPvP save;
                        save.guardarPartidaActual(tablero, jugador1, jugador2, numJugadas);
                        flag = false;
                    }
                }
            }
        }

        if (empate) {
            cout << "-----> El juego termino en empate" << endl << endl;
        }

        int confirm = 0;
        cout << "-----> Desea Mostrar el historial de jugadas? si : 1  :";
        cin >> confirm;
        cout << endl;

        if (confirm == 1) {
            historial.mostrarHistorial();
        }

    }

    delete tablero;
}

void JuegoPvP::refreshPlayerStats(vector<PlayerHumano*> &lista) {

    int size = lista.size();

    for (int i = 0; i < size; i++) {

        PlayerHumano* p = lista[i];

        if (p->getNombre() == jugador1->getNombre()) {

            if (p->getPuntuacion() < jugador1->getPuntuacion()) {
                int punt = jugador1->getPuntuacion();
                p->setPuntuacion(punt);
            }
        } else if (p->getNombre() == jugador2->getNombre()) {

            if (p->getPuntuacion() < jugador2->getPuntuacion()) {
                int punt = jugador2->getPuntuacion();
                p->setPuntuacion(punt);
            }
        }
    }
}