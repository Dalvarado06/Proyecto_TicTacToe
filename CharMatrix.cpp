/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CharMatrix.cpp
 * Author: dalva
 * 
 * Created on December 2, 2020, 6:28 PM
 */

#include "CharMatrix.h"
#include <iostream>

using std::cout;
using std::endl;


CharMatrix::CharMatrix() {
    filas = columnas = 0;
    matrix = 0;
}

CharMatrix::CharMatrix(int pFilas, int pColumnas){
    matrix = NULL;
    createMatrix(pFilas, pColumnas);
}

CharMatrix::CharMatrix(const CharMatrix& orig) {
    this->filas = orig.filas;
    this->columnas = orig.columnas;
    
    for(int i = 0; i < this->filas; i++){
        for(int j = 0; j < this->columnas; j++){
            this->matrix[i][j] = orig.matrix[i][j];
        }
    }
}

CharMatrix::~CharMatrix() {
    freeMatrix();
}

//Esta funcion instancia una matriz de size fila por columnas
void CharMatrix::createMatrix(int pFilas, int pColumnas){
    
    if(matrix != NULL){
        freeMatrix();
    }
    
    //instanciar el this
    matrix = new char* [pFilas];
    
    for(int i = 0; i < pFilas; i++){
        
        matrix[i] = new char [pColumnas];
    }
    
    filas = pFilas;
    columnas = pColumnas;
}

//libera la matriz de la memoria
void CharMatrix::freeMatrix(){
    
    if(matrix != NULL){
        
        for(int i = 0; i < filas; i++){
            delete[] matrix[i]; 
        }
        
        delete[] matrix;
        
        matrix = NULL;
        
        filas = 0;
        columnas = 0;
    }
}

//inicializa la matriz con valores
void CharMatrix::initMatrix(){
    
   for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
            matrix[i][j]='.';

}

//retorna el valor de la casilla
char CharMatrix::getPosValueMatrix(int cFila, int cColumna){
    
    if(cFila < 0 || cFila >= filas)
        return '?';
    
    else if(cColumna < 0 || cColumna >= columnas)
        return '?';
    
    else{
        return matrix[cFila][cColumna];
    }
}

//setea el valor de una casilla 
void CharMatrix::setPosValueMatrix(int fila, int columna, char value){
    
    if(fila < 0 || fila >= this->filas || columna < 0 || columna >= columnas){
        
    }else{
        matrix[fila][columna] = value;
    }
}

//imprime la matriz en consola
void CharMatrix::printMatrix(){
    
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << "[ " << matrix[i][j] << " ] \t";
        }
        
        cout << endl;
    }
    
    cout << endl << endl;
}
