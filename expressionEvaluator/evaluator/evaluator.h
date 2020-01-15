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

extern std::ifstream fin;
extern unsigned lungimeVal;
extern bool userVariables;
extern unsigned int pozV;
extern double userVar;
extern double x;



extern unsigned int binLogs;

struct variabile{

    std::string name;
    double value;
    bool isAssigned;

    variabile() : isAssigned(0) { }
};



extern std::string postQueue[1000];
extern unsigned int lenPostQueue;


void push(struct variabile a[],std::string nume,unsigned int &i);
bool inStruct(struct variabile a[],unsigned int &len,std::string nume,unsigned int &poz);

void toLower(std::string &s);

bool isSeparator(const char &c);
bool isLeftOperator(const char &c);
bool isRightOperator(const char &c);


bool isComma(const std::string &s);
bool isLeftParan(const std::string &s);
bool isRightParan(const std::string &s);
bool isOperator(const std::string &s);


bool isCosntant(const std::string &s);
bool isLog(const std::string &s);
bool isFunction(const std::string &s);
bool isBinaryFunction(const std::string &s);

unsigned short operatorPrio(const std::string &s);

void putInfixQueue(std::string &expression,Queue &infixQ);
void makePostQueue(Queue &infixQ, Queue &postQ);

double stringToDouble(std::string &s);
double stringToDoubleFull(std::string &s);

double valueQueue(Queue postQ);
double valueFunction(const std::string &s,double t1,double t2=0);

double toConstant(std::string s);
bool isMulfPiOn2(double t);

std::string logType(std::string token,unsigned int &binLogs);
bool hasLog(std::string s);
bool hasBinaryFunction(std::string token);
unsigned int noBinaryFunctions(std::string token);
unsigned int findLog(std::string token);


void putPostQueue(Queue postQ);

#endif //EXPRESSIONEVALUATOR_EVALUATOR_H
