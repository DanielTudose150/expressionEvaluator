#include <iostream>
#include "evaluator/evaluator.h"


extern variabile var[1000];
std::string s="log(e)";
struct Queue infixQ,postQ;
int main() {
    //std::cin>>x;

    putInfixQueue(s,infixQ);
    if(userVariables)

    {
        for(unsigned int i=0;i<lungimeVal;++i)
        {
            std::cout<<var[i].name<<"= ";
            std::cin>>userVar;
            var[i].value=userVar;
            std::cout<<'\n';
        }
    }
    std::cout<<"\n\n\n\n";
    std::cout<<'\n';
    makePostQueue(infixQ,postQ);
    std::cout<<valueQueue(postQ);
    return 0;
}
