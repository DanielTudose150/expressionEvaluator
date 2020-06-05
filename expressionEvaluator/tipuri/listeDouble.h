//
// Created by legen on 06-Jan-20.
//

#ifndef EXPRESSIONEVALUATOR_LISTEDOUBLE_H
#define EXPRESSIONEVALUATOR_LISTEDOUBLE_H

/// a list of doubles to be able to calculate the value of the expression

struct nodeD{

    double val;
    nodeD *next;

    nodeD () : next(nullptr) { }
};

#endif //EXPRESSIONEVALUATOR_LISTEDOUBLE_H
