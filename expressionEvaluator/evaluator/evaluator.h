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

bool isLeftOperator(const char &c);
bool isRightOperator(const char &c);
bool isLetterOperator(const char &c);
bool isOperatorString(const std::string &s);
bool isSeparator(const char &c);
bool isSeparator(const std::string &s);
bool isLeftParan(const char &c);
bool isLeftParan(const std::string &s);
bool isRightParan(const char &c);
bool isRightParan(const std::string &s);
bool isFunction(const std::string &s);


void putInfixQueue(std::string &expression,Queue &infixQ);

#endif //EXPRESSIONEVALUATOR_EVALUATOR_H
