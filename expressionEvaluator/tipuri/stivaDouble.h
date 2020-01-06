//
// Created by legen on 06-Jan-20.
//

#ifndef EXPRESSIONEVALUATOR_STIVADOUBLE_H
#define EXPRESSIONEVALUATOR_STIVADOUBLE_H

#include "listeDouble.h"

/*typedef struct{

    nodeD *first;

    bool isEmpty();
    void push(double val);
    void pop();
    double top();

}DStack;
*/

struct DStack{

    nodeD *first;

    DStack() : first(nullptr) { }

    bool isEmpty();
    void push(double val);
    void pop();
    double top();

};
#endif //EXPRESSIONEVALUATOR_STIVADOUBLE_H
