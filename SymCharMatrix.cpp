/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SymCharMatrix.cpp
 * Author: dalva
 * 
 * Created on December 2, 2020, 6:34 PM
 */

#include "SymCharMatrix.h"

SymCharMatrix::SymCharMatrix() : CharMatrix() {
}

SymCharMatrix::SymCharMatrix(const SymCharMatrix& orig) {
}

SymCharMatrix::~SymCharMatrix() {
    freeMatrix();
}

SymCharMatrix::SymCharMatrix(int size) : CharMatrix(size, size){
    
}