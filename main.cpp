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
#include "AdminJugadores.h"
#include "JuegoPvP.h"
#include "GuardarPvP.h"

using namespace std;

int menu();
void listarJugadores(vector<PlayerHumano*>&);
void freeVector(vector<PlayerHumano*>&);
//void resumirJugadorvsJugador();
//void resumirJugadorvsCpu();

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

    AdminJugadores adminJugadores;

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

                Player* p = new PlayerHumano(nombre);

//                jugadoresRegistrados = adminJugadores.leerJugadores();
//
//                jugadoresRegistrados.push_back(p);
//
//                adminJugadores.guardarJugadores(jugadoresRegistrados);

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
                    
                    PlayerHumano* p1 = jugadoresRegistrados[indice-1];
                    PlayerHumano* p2 = jugadoresRegistrados[indice2-1];
                    
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

                break;

            }
            case 4:
            {
                cout << "Resumir Ultima partida" << endl << endl;
                
                int opcion = 0;
                
                while(opcion != 3){
                    
                    cout << "------MENU PARTIDAS------" << endl
                         << "1. Resumir ultimo PvP" << endl
                         << "2. Resumir ultimo Player vs CPU" << endl
                         << "3. Salir" << endl
                         << "Elija su opcion: ";
                    
                    cin >> opcion;
                    cout << endl;
                    
                    switch(opcion){
                        
                        case 1:{
                            cout << "Resumir ultimo PVP" << endl << endl; 
                            
                            Juego* game;
                            GuardarPvP leerPartida;
                            
                            game = leerPartida.cargarPartida();
                            
                            if(game != NULL){
                                
                            }else{
                                cout << "Hubo un error al cargar la partida"
                                        << endl << endl;
                            }
                        }
                        
                        case 2:{
                            
                        }
                        
                        case 3:{
                            cout << "Saliendo al menu Principal..." << endl;
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

void freeVector(vector<PlayerHumano*> &lista){
    
    for(int i = 0; i < lista.size(); i++){
        
        delete lista[i];
        
    }
    
    lista.clear();
}