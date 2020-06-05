//
// Created by legen on 06-Jan-20.
//

#ifndef EXPRESSIONEVALUATOR_STIVASTRING_H
#define EXPRESSIONEVALUATOR_STIVASTRING_H

#include "listeString.h"

/// a stack with strings values in which the token of the expression will be kept

struct SStack{

    nodeS *first;

    ///ctor
    SStack() : first(nullptr) { }

    ///checks if the stack is empty
    bool isEmpty();

    ///pushes an element to the stack
    void push(std::string inf);

    ///pops the top element of the stack
    void pop();

    ///returns the value of the top of the stack
    std::string top();

};

#endif //EXPRESSIONEVALUATOR_STIVASTRING_H
