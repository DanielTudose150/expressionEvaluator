//
// Created by legen on 06-Jan-20.
//

#ifndef EXPRESSIONEVALUATOR_EVALUATOR_H
#define EXPRESSIONEVALUATOR_EVALUATOR_H

#include "../tipuri/stivaDouble.h"
#include "../tipuri/stivaString.h"
#include "../tipuri/coada.h"

#include <cctype>
#include <cmath>
#include <algorithm>

void toLower(std::string &s);

bool isSeparator(const char &c);
bool isComma(const std::string &s);
bool isLeftParan(const std::stirng &s);
bool isRightParan(const std::string &s);
bool isOperator(const std::string &s);

bool isFunction(const std::string &s);

void putInfixQueue(std::string &expression,Queue &infixQ);
void makePostQueue(Queue &infixQ, Queue &postQ);

#endif //EXPRESSIONEVALUATOR_EVALUATOR_H
