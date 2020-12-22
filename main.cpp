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
#include <valarray>
#include "Player.h"
#include "PlayerHumano.h"
#include "PlayerCPU.h"
#include "Mark.h"
#include "Juego.h"
#include "AdminJugadores.h"
#include "JuegoPvP.h"
#include "GuardarPvP.h"
#include "GuardarVsCpu.h"
#include "JuegoCpu.h"

using namespace std;

int menu();
void listarJugadores(vector<PlayerHumano*>&);
void freeVector(vector<PlayerHumano*>&);


/*
 * 
 */
int main(int argc, char** argv) {

    vector<PlayerHumano*> jugadoresRegistrados;
    PlayerCPU* maquina = new PlayerCPU();

    AdminJugadores adminJugadores;
    jugadoresRegistrados = adminJugadores.leerJugadores();

    int opcion = 0;

    while (opcion != 5) {

        switch ((opcion = menu())) {

            case 1:
            {

                cout << "Registrar un nuevo jugador" << endl << endl;

                string nombre = "";

                cout << "Ingrese su nombre: ";
                cin >> nombre;
                cout << endl << endl;

                PlayerHumano* p = new PlayerHumano(nombre);

                jugadoresRegistrados = adminJugadores.leerJugadores();

                jugadoresRegistrados.push_back(p);

                adminJugadores.guardarJugadores(jugadoresRegistrados);

                cout << "El ingreso ha sido completado" << endl << endl;

                break;

            }
            case 2:
            {

                cout << "Nuevo juego PVP" << endl << endl;
                jugadoresRegistrados = adminJugadores.leerJugadores();

                if (jugadoresRegistrados.empty() || jugadoresRegistrados.size() < 1) {
                    cout << "No hay jugadores registrados en la lista: "
                            << endl << endl;
                } else {

                    cout << "Estos son los jugadores disponibles, elija dos: "
                            << endl;
                    listarJugadores(jugadoresRegistrados);

                    int indice = -1;
                    int indice2 = -1;

                    cout << "Elija al primero: ";
                    cin >> indice;
                    cout << endl;

                    while (indice <= 0) {
                        cout << "Elija al primero: ";
                        cin >> indice;
                        cout << endl;
                    }

                    cout << "Elija al segundo: ";
                    cin >> indice2;
                    cout << endl;

                    while (indice2 <= 0) {
                        cout << "Elija al segundo: ";
                        cin >> indice2;
                        cout << endl;
                    }

                    PlayerHumano* p1 = jugadoresRegistrados[indice - 1];
                    PlayerHumano* p2 = jugadoresRegistrados[indice2 - 1];

                    JuegoPvP* ticTacToe = new JuegoPvP();

                    ticTacToe->setPlayers(p1, p2);

                    ticTacToe->initGame();



                    cout << "El juego a finalizado" << endl << endl;
                    delete ticTacToe;

                }


                break;

            }
            case 3:
            {
                cout << "Nuevo juego contra CPU" << endl << endl;
                jugadoresRegistrados = adminJugadores.leerJugadores();

                if (jugadoresRegistrados.empty()) {
                    cout << "No hay jugadores en la lista!" << endl << endl;

                } else {

                    cout << "Estos son los jugadores disponibles, elija uno: "
                            << endl;
                    listarJugadores(jugadoresRegistrados);

                    int indice = -1;

                    cout << "Ingrese el indice del jugador a escoger: ";
                    cin >> indice;
                    cout << endl << endl;

                    while (indice < 0) {
                        cout << "Ingrese el indice del jugador a escoger: ";
                        cin >> indice;
                        cout << endl << endl;
                    }

                    JuegoCpu* game = new JuegoCpu();

                    game->setPlayers(jugadoresRegistrados[indice - 1], maquina);

                    game->initGame();


                    cout << "El juego a finalizado" << endl << endl;
                    delete game;
                }




                break;

            }
            case 4:
            {
                cout << "Resumir Ultima partida" << endl << endl;

                int opcion = 0;

                while (opcion != 3) {

                    cout << "------MENU PARTIDAS------" << endl
                            << "1. Resumir ultimo PvP" << endl
                            << "2. Resumir ultimo Player vs CPU" << endl
                            << "3. Salir" << endl
                            << "Elija su opcion: ";

                    cin >> opcion;
                    cout << endl;

                    switch (opcion) {

                        case 1:
                        {
                            cout << "Resumir ultimo PVP" << endl << endl;

                            JuegoPvP* game;
                            GuardarPvP leerPartida;

                            game = leerPartida.cargarPartida();



                            if (game != NULL) {

                                game->reInitGame();
                                game->refreshPlayerStats(jugadoresRegistrados);


                                delete game;

                            } else {
                                cout << "Hubo un error al cargar la partida"
                                        << endl << endl;
                            }


                            break;
                        }

                        case 2:
                        {
                            cout << "Resumir ultimo vs CPU " << endl << endl;
                            
                            JuegoCpu* game;
                            GuardarVsCpu load;
                            
                            game = load.cargarPartida();
                            
                            game->reInitGame();
                            
                            game->actualizarPuntJugador(jugadoresRegistrados);
                            game->actualizarPuntMaquina(maquina);
                            
                            
                            delete game;
                            break;

                        }

                        case 3:
                        {
                            cout << "Saliendo al menu Principal..." << endl << endl;
                            break;
                        }

                        default:
                            cout << "Su opcion es incorrecta..." << endl << endl;
                    }
                }

                break;

            }
            case 5:
            {
                adminJugadores.guardarJugadores(jugadoresRegistrados);
                freeVector(jugadoresRegistrados);
                delete maquina;
                cout << "Ha salido del programa" << endl;
                break;
            }
        }
    }



    return 0;
}

int menu() {

    int opcion = 0;

    do {

        cout << "------TIC TAC TOE------" << endl
                << "1. Registrar Jugadores" << endl
                << "2. Nuevo Juego PVP" << endl
                << "3. Nuevo Juego vs CPU" << endl
                << "4. Resumir ultima partida" << endl
                << "5. Salir y guardar" << endl
                << "Ingrese su opcion: ";

        cin >> opcion;
        cout << endl;

    } while (opcion > 5 || opcion < 1);


    return opcion;
}

void listarJugadores(vector<PlayerHumano*> &lista) {

    for (int i = 0; i < lista.size(); i++) {

        cout << i + 1 << " " << lista[i]->getNombre() << " "
                << lista[i]->getPuntuacion() << endl;
    }

    cout << endl << endl;
}

void freeVector(vector<PlayerHumano*> &lista) {

    for (int i = 0; i < lista.size(); i++) {

        delete lista[i];

    }

    lista.clear();
}