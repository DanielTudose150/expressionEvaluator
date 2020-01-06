//
// Created by legen on 06-Jan-20.
//

#ifndef EXPRESSIONEVALUATOR_STIVASTRING_H
#define EXPRESSIONEVALUATOR_STIVASTRING_H

#include "listeString.h"

struct SStack{

    nodeS *first;

    SStack() : first(nullptr) { }

    bool isEmpty();
    void push(std::string inf);
    void pop();
    std::string top();

};

#endif //EXPRESSIONEVALUATOR_STIVASTRING_H
