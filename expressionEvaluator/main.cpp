#include <iostream>
#include "evaluator/evaluator.h"

std::string s="a+ b - sin(c) and10";
struct Queue coada;
int main() {
    putInfixQueue(s,coada);
    while(!coada.isEmpty())
    {
        std::cout<<coada.front()<<'\n';
        coada.pop();
    }
    return 0;
}
