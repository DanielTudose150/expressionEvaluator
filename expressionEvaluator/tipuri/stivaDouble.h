//
// Created by legen on 06-Jan-20.
//

#ifndef EXPRESSIONEVALUATOR_STIVADOUBLE_H
#define EXPRESSIONEVALUATOR_STIVADOUBLE_H

#include "listeDouble.h"

/// a stack with double values in which the value of the expression will be calculated

struct DStack{

    nodeD *first;

    ///ctor
    DStack() : first(nullptr) { }

    ///checks if the stack is empty
    bool isEmpty();

    ///pushes an element to the stack
    void push(double val);

    ///pops the top of the stack
    void pop();

    ///returns the value of the top element of the stack
    double top();

};
#endif //EXPRESSIONEVALUATOR_STIVADOUBLE_H
