//
// Created by legen on 06-Jan-20.
//

#ifndef EXPRESSIONEVALUATOR_LISTESTRING_H
#define EXPRESSIONEVALUATOR_LISTESTRING_H

#include <string>

struct nodeS{

    std::string inf;
    nodeS *next;

    nodeS() : next(nullptr) { }

};

#endif //EXPRESSIONEVALUATOR_LISTESTRING_H
