//
// Created by legen on 06-Jan-20.
//

#ifndef EXPRESSIONEVALUATOR_LISTEDOUBLE_H
#define EXPRESSIONEVALUATOR_LISTEDOUBLE_H

struct nodeD{

    double val;
    nodeD *next;

/*    nodeD(nodeD *pD) {

    }
*/
    nodeD () : next(nullptr) { }
};

#endif //EXPRESSIONEVALUATOR_LISTEDOUBLE_H
