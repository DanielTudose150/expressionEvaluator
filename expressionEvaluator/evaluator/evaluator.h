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
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iostream>

/// variables used throughout the program

extern std::ifstream fin;
extern unsigned lungimeVal;
extern bool userVariables;
extern unsigned int pozV;
extern double userVar;
extern double x;


/// counter of the number of binary logarithms
extern unsigned int binLogs;

/// a structure of user defined variables
struct variabile{

    std::string name;
    double value;
    bool isAssigned;

    variabile() : isAssigned(0) { }
};


/// an array to keep the tokens of the expression and its length
extern std::string postQueue[1000];
extern unsigned int lenPostQueue;

/// pushes a user defined variable into the array of user defined variables at the position i
void push(struct variabile a[],std::string nume,unsigned int &i);

/// checks if a variable has been introduced earlier
bool inStruct(struct variabile a[],unsigned int &len,std::string nume,unsigned int &poz);

/// method to get the lowercase version of the string s
void toLower(std::string &s);

/// methods to check if a character is a separator or operator
bool isSeparator(const char &c);
bool isLeftOperator(const char &c);
bool isRightOperator(const char &c);

/// methods to check if a  string is a separator or operator
bool isComma(const std::string &s);
bool isLeftParan(const std::string &s);
bool isRightParan(const std::string &s);
bool isOperator(const std::string &s);

/// methods for checking the type of the token
bool isCosntant(const std::string &s);
bool isLog(const std::string &s);
bool isFunction(const std::string &s);
bool isBinaryFunction(const std::string &s);

/// method for determining the priority of operations
unsigned short operatorPrio(const std::string &s);

/// a method which takes a string and construct the infix notation in tokens of the expressions
void putInfixQueue(std::string &expression,Queue &infixQ);

/** a method which constructs the post-fixed notation of the expression, using the infixed notation
 *
 * it uses the Shunting-yard algorithm with some modifications to fit the scope of the project
 */
void makePostQueue(Queue &infixQ, Queue &postQ);

/// methods for converting a token to its numerical value
double stringToDouble(std::string &s);
double stringToDoubleFull(std::string &s);

/// methods for getting the numerical value of the expression or a function(unary or binary)
double valueQueue(Queue postQ);
double valueFunction(const std::string &s,double t1,double t2=0);

/// method for getting the numerical value for token constants
double toConstant(std::string s);

/// method for checking the if a number is a multiple of pi/2
bool isMulfPiOn2(double t);

/// method which returns the type of the logarithm, unary of binary
std::string logType(std::string token,unsigned int &binLogs);

/// method which checks if the token s contains a logarithm function
bool hasLog(std::string s);

/// method for checking if the token contains binary functions or not
bool hasBinaryFunction(std::string token);

/// method which counts the number of binary functions
unsigned int noBinaryFunctions(std::string token);

/// method for finding where the first logarithm in the token is
unsigned int findLog(std::string token);

/// method which fills the array equivalent of the queue
void putPostQueue(Queue postQ);

#endif //EXPRESSIONEVALUATOR_EVALUATOR_H
