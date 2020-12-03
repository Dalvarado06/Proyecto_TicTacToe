/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SymCharMatrix.h
 * Author: dalva
 *
 * Created on December 2, 2020, 6:34 PM
 */

#ifndef SYMCHARMATRIX_H
#define SYMCHARMATRIX_H

#include "CharMatrix.h"


class SymCharMatrix : public CharMatrix {
public:
    SymCharMatrix();
    SymCharMatrix(const SymCharMatrix& orig);
    virtual ~SymCharMatrix();
    //constructor sobrecargado
    SymCharMatrix(int);
private:

};

#endif /* SYMCHARMATRIX_H */

