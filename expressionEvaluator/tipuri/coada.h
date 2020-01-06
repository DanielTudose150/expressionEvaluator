//
// Created by legen on 06-Jan-20.
//

#ifndef EXPRESSIONEVALUATOR_COADA_H
#define EXPRESSIONEVALUATOR_COADA_H

#include <string>
#include "listeString.h"

struct Queue{
    nodeS *first,*last;

    Queue() : first(nullptr), last(nullptr) { }

    bool isEmpty();
    void push(std::string val);
    void pop();
    std::string front();
};

#endif //EXPRESSIONEVALUATOR_COADA_H
