/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CharMatrix.h
 * Author: dalva
 *
 * Created on December 2, 2020, 6:28 PM
 */

#ifndef CHARMATRIX_H
#define CHARMATRIX_H

class CharMatrix {
public:
    CharMatrix();
    CharMatrix(const CharMatrix& orig);
    virtual ~CharMatrix();
    
    //constructor sobrecargado que recibe filas y columnas
    CharMatrix(int, int);
    
    //Esta funcion instancia una matriz de size fila por columnas
    void createMatrix(int, int);
    
    //libera la matriz de la memoria
    void freeMatrix();
    
    //inicializa la matriz con valores
    virtual void initMatrix();
    
    //retorna el valor de la casilla
    char getPosValueMatrix(int, int);
    
    //setea el valor de una casilla 
    void setPosValueMatrix(int, int, char);
    
    //imprime la matriz en consola
    void printMatrix();
    

private:
    char** matrix;
    int filas;
    int columnas;
};

#endif /* CHARMATRIX_H */

