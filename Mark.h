/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mark.h
 * Author: dalva
 *
 * Created on December 2, 2020, 8:58 PM
 */

#ifndef MARK_H
#define MARK_H

class Mark {
public:
    //Constructor
    Mark();
    //Copia
    Mark(const Mark& orig);
    //Destructor
    virtual ~Mark();
    //Sobre cargado
    Mark(int, int, char);
    
    //Getters y Setters
    void setFila(int);
    
    int getFila();
    
    void setColumna(int);
    
    int getColumna();
    
    void setMarca(char);
    
    char getMarca();
    
    
private:
    int fila;
    int columna;
    int marca;
};

#endif /* MARK_H */

