#include <iostream>
#include "evaluator/evaluator.h"


extern variabile var[1000];
std::string s="tan(x)/log(x)";
struct Queue infixQ,postQ;
int main() {
    //std::cin>>x;
    //errorHandle("masini");
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
    x=1;
    makePostQueue(infixQ,postQ);
    putPostQueue(postQ);
    /*for(unsigned int i=0;i<lenPostQueue;++i)
    {
        std::cout<<postQueue[i]<<'\n';
    }*/

   std::cout<<valueQueue(postQ);
    return 0;
}
