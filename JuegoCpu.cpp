/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JuegoCpu.cpp
 * Author: dalva
 * 
 * Created on December 20, 2020, 4:15 PM
 */

#include "JuegoCpu.h"

JuegoCpu::JuegoCpu() {
    tablero = new GameBoard();
    numJugadas = 0;
}

JuegoCpu::JuegoCpu(const JuegoCpu& orig) {
}

JuegoCpu::~JuegoCpu() {
}

void JuegoCpu::setPlayers(PlayerHumano* jug, PlayerCPU* machine) {
    jugador = jug;
    maquina = machine;
}

void JuegoCpu::initGame() {

    srand(time(0));

    int numero1 = 0;
    int numero2 = 0;

    while (numero1 == numero2) {
        numero1 = 1 + (rand() % 14);
        numero2 = 1 + (rand() % 14);
    }

    if (numero1 > numero2) {
        jugador->setMarca('X');
        maquina->setMarca('0');

    } else {
        jugador->setMarca('0');
        maquina->setMarca('X');
    }

    //inicio de la partida
    if (jugador->getMarca() == 'X') {

        cout << "------> El jugador " << jugador->getNombre() << " juega primero"
                << endl << endl;

        bool flag = true;
        HistorialJugadas historial;

        cout << "-----> El juego ha comenzado: " << endl << endl;

        int fila = 0;
        int columna = 0;

        while (flag && numJugadas <= 9) {

            cout << "-----> El tablero esta asi: " << endl << endl;
            tablero->getTablero()->printMatrix();


            cout << "Jugador " << jugador->getNombre() << " ingrese la fila: ";
            cin >> fila;
            cout << endl << endl;

            cout << "Jugador " << jugador->getNombre() << " ingrese la columna: ";
            cin >> columna;
            cout << endl << endl;

            bool canDo = false;
            canDo = validarMovimiento(fila - 1, columna - 1);

            while (!canDo) {
                cout << "Jugador " << jugador->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                canDo = validarMovimiento(fila - 1, columna - 1);
            }

            tablero->getTablero()->setPosValueMatrix(fila - 1, columna - 1, jugador->getMarca());
            numJugadas = numJugadas + 1;
            historial.agregarJugada(tablero->getTablero());

            bool gano = validarGanador(jugador->getMarca());

            if (gano) {
                cout << "El jugador " << jugador->getNombre() << " gano" << endl;
                flag = false;
                int score = jugador->getPuntuacion() + 1;
                jugador->setPuntuacion(score);


            } else if (numJugadas < 9) {


                cout << "-----> El tablero esta asi: " << endl << endl;
                tablero->getTablero()->printMatrix();

                cout << "La maquina esta jugando! " << endl << endl;


                string board = matrixToString(tablero->getTablero());


                bool validacionDefensa = maquina->validarTablero(board, jugador->getMarca());

                Mark marca;

                if (validacionDefensa) {
                    marca = maquina->defendiendo(board, jugador->getMarca());
                    tablero->getTablero()->setPosValueMatrix(marca.getFila()
                            , marca.getColumna(), maquina->getMarca());
                    historial.agregarJugada(tablero->getTablero());

                } else {
                    marca = maquina->atacando(board, maquina->getMarca());
                    tablero->getTablero()->setPosValueMatrix(marca.getFila(),
                            marca.getColumna(), maquina->getMarca());
                    historial.agregarJugada(tablero->getTablero());
                }

                bool gano = validarGanador(maquina->getMarca());

                if (gano) {
                    flag = false;
                    cout << "El jugador " << maquina->getNombre() << " gano" << endl;
                    int score = maquina->getPuntuacion() + 1;
                    maquina->setPuntuacion(score);

                } else if (numJugadas <= 7 || numJugadas > 1) {

                    int opcion = 0;
                    cout << "Desea salir de la partida y guardarla (1 = si): ";
                    cin >> opcion;

                    if (opcion == 1) {

                        GuardarVsCpu save;
                        save.guardarPartidaActual(tablero, jugador, maquina, numJugadas);
                        flag = false;
                    }
                }

            }
        }

        cout << "Historial de jugadas " << endl << endl;
        historial.mostrarHistorial();


    } else {


        cout << "------> El jugador " << maquina->getNombre() << " juega primero"
                << endl << endl;

        bool flag = true;
        HistorialJugadas historial;

        cout << "-----> El juego ha comenzado: " << endl << endl;

        int fila = 0;
        int columna = 0;


        while (flag && numJugadas <= 9) {

            cout << "-----> El tablero esta asi: " << endl << endl;
            tablero->getTablero()->printMatrix();

            cout << "La maquina esta jugando! " << endl << endl;


            string board = matrixToString(tablero->getTablero());


            bool validacionDefensa = maquina->validarTablero(board, jugador->getMarca());

            Mark marca;

            if (validacionDefensa) {
                marca = maquina->defendiendo(board, jugador->getMarca());
                tablero->getTablero()->setPosValueMatrix(marca.getFila()
                        , marca.getColumna(), maquina->getMarca());
                historial.agregarJugada(tablero->getTablero());

            } else {
                marca = maquina->atacando(board, maquina->getMarca());
                tablero->getTablero()->setPosValueMatrix(marca.getFila(),
                        marca.getColumna(), maquina->getMarca());
                historial.agregarJugada(tablero->getTablero());
            }

            bool gano = validarGanador(maquina->getMarca());

            if (gano) {
                flag = false;
                cout << "El jugador " << maquina->getNombre() << " gano" << endl;
                int score = maquina->getPuntuacion() + 1;
                maquina->setPuntuacion(score);

            } else if (numJugadas < 9) {


                cout << "-----> El tablero esta asi: " << endl << endl;
                tablero->getTablero()->printMatrix();


                cout << "Jugador " << jugador->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                bool canDo = false;
                canDo = validarMovimiento(fila - 1, columna - 1);

                while (!canDo) {
                    cout << "Jugador " << jugador->getNombre() << " ingrese la fila: ";
                    cin >> fila;
                    cout << endl << endl;

                    cout << "Jugador " << jugador->getNombre() << " ingrese la columna: ";
                    cin >> columna;
                    cout << endl << endl;

                    canDo = validarMovimiento(fila - 1, columna - 1);
                }

                tablero->getTablero()->setPosValueMatrix(fila - 1, columna - 1, jugador->getMarca());
                numJugadas = numJugadas + 1;
                historial.agregarJugada(tablero->getTablero());

                bool gano = validarGanador(jugador->getMarca());

                if (gano) {
                    cout << "El jugador " << jugador->getNombre() << " gano" << endl;
                    flag = false;
                    int score = jugador->getPuntuacion() + 1;
                    jugador->setPuntuacion(score);


                } else if (numJugadas <= 7 || numJugadas > 1) {

                    int opcion = 0;
                    cout << "Desea salir de la partida y guardarla (1 = si): ";
                    cin >> opcion;
                    cout << endl << endl;

                    if (opcion == 1) {

                        GuardarVsCpu save;
                        save.guardarPartidaActual(tablero, jugador, maquina, numJugadas);
                        flag = false;
                    }
                }

            }
        }

        cout << "Historial de jugadas " << endl << endl;
        historial.mostrarHistorial();
    }
}

string JuegoCpu::matrixToString(SymCharMatrix* tablero) {

    string board = "";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char marc = tablero->getPosValueMatrix(i, j);
            board += marc;
        }
    }


    return board;
}

void JuegoCpu::reInitGame() {
    //inicio de la partida
    if (jugador->getMarca() == 'X') {

        cout << "------> El jugador " << jugador->getNombre() << " juega primero"
                << endl << endl;

        bool flag = true;
        HistorialJugadas historial;

        cout << "-----> El juego ha comenzado: " << endl << endl;

        int fila = 0;
        int columna = 0;

        while (flag && numJugadas <= 9) {

            cout << "-----> El tablero esta asi: " << endl << endl;
            tablero->getTablero()->printMatrix();


            cout << "Jugador " << jugador->getNombre() << " ingrese la fila: ";
            cin >> fila;
            cout << endl << endl;

            cout << "Jugador " << jugador->getNombre() << " ingrese la columna: ";
            cin >> columna;
            cout << endl << endl;

            bool canDo = false;
            canDo = validarMovimiento(fila - 1, columna - 1);

            while (!canDo) {
                cout << "Jugador " << jugador->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                canDo = validarMovimiento(fila - 1, columna - 1);
            }

            tablero->getTablero()->setPosValueMatrix(fila - 1, columna - 1, jugador->getMarca());
            numJugadas = numJugadas + 1;
            historial.agregarJugada(tablero->getTablero());

            bool gano = validarGanador(jugador->getMarca());

            if (gano) {
                cout << "El jugador " << jugador->getNombre() << " gano" << endl;
                flag = false;
                int score = jugador->getPuntuacion() + 1;
                jugador->setPuntuacion(score);


            } else if (numJugadas < 9) {


                cout << "-----> El tablero esta asi: " << endl << endl;
                tablero->getTablero()->printMatrix();

                cout << "La maquina esta jugando! " << endl << endl;


                string board = matrixToString(tablero->getTablero());


                bool validacionDefensa = maquina->validarTablero(board, jugador->getMarca());

                Mark marca;

                if (validacionDefensa) {
                    marca = maquina->defendiendo(board, jugador->getMarca());
                    tablero->getTablero()->setPosValueMatrix(marca.getFila()
                            , marca.getColumna(), maquina->getMarca());
                    historial.agregarJugada(tablero->getTablero());

                } else {
                    marca = maquina->atacando(board, maquina->getMarca());
                    tablero->getTablero()->setPosValueMatrix(marca.getFila(),
                            marca.getColumna(), maquina->getMarca());
                    historial.agregarJugada(tablero->getTablero());
                }

                bool gano = validarGanador(maquina->getMarca());

                if (gano) {
                    flag = false;
                    cout << "El jugador " << maquina->getNombre() << " gano" << endl;
                    int score = maquina->getPuntuacion() + 1;
                    maquina->setPuntuacion(score);

                } else if (numJugadas <= 7 || numJugadas > 1) {

                    int opcion = 0;
                    cout << "Desea salir de la partida y guardarla (1 = si): ";
                    cin >> opcion;
                    cout << endl << endl;

                    if (opcion == 1) {

                        GuardarVsCpu save;
                        save.guardarPartidaActual(tablero, jugador, maquina, numJugadas);
                        flag = false;
                    }
                }

            }
        }

        cout << "Historial de jugadas " << endl << endl;
        historial.mostrarHistorial();


    } else {


        cout << "------> El jugador " << maquina->getNombre() << " juega primero"
                << endl << endl;

        bool flag = true;
        HistorialJugadas historial;

        cout << "-----> El juego ha comenzado: " << endl << endl;

        int fila = 0;
        int columna = 0;


        while (flag && numJugadas <= 9) {

            cout << "-----> El tablero esta asi: " << endl << endl;
            tablero->getTablero()->printMatrix();

            cout << "La maquina esta jugando! " << endl << endl;


            string board = matrixToString(tablero->getTablero());


            bool validacionDefensa = maquina->validarTablero(board, jugador->getMarca());

            Mark marca;

            if (validacionDefensa) {
                marca = maquina->defendiendo(board, jugador->getMarca());
                tablero->getTablero()->setPosValueMatrix(marca.getFila()
                        , marca.getColumna(), maquina->getMarca());
                historial.agregarJugada(tablero->getTablero());

            } else {
                marca = maquina->atacando(board, maquina->getMarca());
                tablero->getTablero()->setPosValueMatrix(marca.getFila(),
                        marca.getColumna(), maquina->getMarca());
                historial.agregarJugada(tablero->getTablero());
            }

            bool gano = validarGanador(maquina->getMarca());

            if (gano) {
                flag = false;
                cout << "El jugador " << maquina->getNombre() << " gano" << endl;
                int score = maquina->getPuntuacion() + 1;
                maquina->setPuntuacion(score);

            } else if (numJugadas < 9) {


                cout << "-----> El tablero esta asi: " << endl << endl;
                tablero->getTablero()->printMatrix();


                cout << "Jugador " << jugador->getNombre() << " ingrese la fila: ";
                cin >> fila;
                cout << endl << endl;

                cout << "Jugador " << jugador->getNombre() << " ingrese la columna: ";
                cin >> columna;
                cout << endl << endl;

                bool canDo = false;
                canDo = validarMovimiento(fila - 1, columna - 1);

                while (!canDo) {
                    cout << "Jugador " << jugador->getNombre() << " ingrese la fila: ";
                    cin >> fila;
                    cout << endl << endl;

                    cout << "Jugador " << jugador->getNombre() << " ingrese la columna: ";
                    cin >> columna;
                    cout << endl << endl;

                    canDo = validarMovimiento(fila - 1, columna - 1);
                }

                tablero->getTablero()->setPosValueMatrix(fila - 1, columna - 1, jugador->getMarca());
                numJugadas = numJugadas + 1;
                historial.agregarJugada(tablero->getTablero());

                bool gano = validarGanador(jugador->getMarca());

                if (gano) {
                    cout << "El jugador " << jugador->getNombre() << " gano" << endl;
                    flag = false;
                    int score = jugador->getPuntuacion() + 1;
                    jugador->setPuntuacion(score);


                } else if (numJugadas <= 7 || numJugadas > 1) {

                    int opcion = 0;
                    cout << "Desea salir de la partida y guardarla (1 = si): ";
                    cin >> opcion;
                    cout << endl << endl;

                    if (opcion == 1) {

                        GuardarVsCpu save;
                        save.guardarPartidaActual(tablero, jugador, maquina, numJugadas);
                        flag = false;
                    }
                }

            }
        }

        cout << "Historial de jugadas " << endl << endl;
        historial.mostrarHistorial();
        cout << endl << endl;
    }
}

void JuegoCpu::actualizarPuntJugador(vector<PlayerHumano*> &lista){
    
    int size = lista.size();
    
    for(int i = 0; i < size; i++){
        
        PlayerHumano* p = lista[i];
        
        if(p->getNombre() == jugador->getNombre()){
            
            if(p->getPuntuacion() < jugador->getPuntuacion()){
                int punt = jugador->getPuntuacion();
                p->setPuntuacion(punt);
                
            }
        }
    }
}

void JuegoCpu::actualizarPuntMaquina(PlayerCPU* &machine){
    
    if(maquina->getPuntuacion() > machine->getPuntuacion()){
        int punt = maquina->getPuntuacion();
        machine->setPuntuacion(punt);
    }
}