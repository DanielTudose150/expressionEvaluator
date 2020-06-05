//
// Created by legen on 06-Jan-20.
//

#ifndef EXPRESSIONEVALUATOR_LISTESTRING_H
#define EXPRESSIONEVALUATOR_LISTESTRING_H

#include <string>


/// a list of strings to keep the tokens

struct nodeS{

    std::string inf;
    nodeS *next;

    nodeS() : next(nullptr) { }

};

#endif //EXPRESSIONEVALUATOR_LISTESTRING_H
