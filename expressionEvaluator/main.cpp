#include <iostream>
#include "evaluator/evaluator.h"


extern variabile var[1000];
std::string s="log(0)";
struct Queue infixQ,postQ;
int main() {
    //std::cin>>x;
    //errorHandle("masini");
    readTexts(1);
    putInfixQueue(s,infixQ);
    if(hasError)
    {
        std::cout<<"are erori";
        return 0;
    }
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

    makePostQueue(infixQ,postQ);

    std::cout<<"\n\n";
    std::cout<<valueQueue(postQ);
    return 0;
}
