/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mark.cpp
 * Author: dalva
 * 
 * Created on December 2, 2020, 8:58 PM
 */

#include "Mark.h"

Mark::Mark() {
    this->fila = 0;
    this->columna = 0;
    this->marca = '.';
}

Mark::Mark(int fila, int columna, char marca){
    this->fila = fila;
    this->columna = columna;
    this->marca = marca;
}

Mark::Mark(const Mark& orig) {
}

Mark::~Mark() {
}

void Mark::setFila(int fila){
    this->fila = fila;
}

int Mark::getFila(){
    return fila;
}

void Mark::setColumna(int columna){
    this->columna = columna;
}

int Mark::getColumna(){
    return columna;
}

void Mark::setMarca(char marca){
    this->marca = marca;
}

char Mark::getMarca(){
    return marca;
}

