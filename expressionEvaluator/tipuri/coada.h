//
// Created by legen on 06-Jan-20.
//

#ifndef EXPRESSIONEVALUATOR_COADA_H
#define EXPRESSIONEVALUATOR_COADA_H

#include <string>
#include "listeString.h"

struct Queue{

    /// pointers to the beginning and the end of the queue for easy insertion and deletion
    nodeS *first,*last;

    ///ctor
    Queue() : first(nullptr), last(nullptr) { }

    /// checks if queue is empty
    bool isEmpty();

    /// adds an element into the queue
    void push(std::string val);

    /// pops the first element of the queue
    void pop();

    /// returns the first element in the queue
    std::string front();
};

#endif //EXPRESSIONEVALUATOR_COADA_H
