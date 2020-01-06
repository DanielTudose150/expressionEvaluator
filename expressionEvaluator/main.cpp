#include <iostream>
#include "tipuri/stivaDouble.h"

DStack stiv;
double x;
int main() {
    for(int i=0;i<3;i++)
    {
        std::cin>>x;
        stiv.push(x);
    }
    while(!stiv.isEmpty())
    {
        std::cout<<stiv.top()<<' ';
        stiv.pop();
    }
    return 0;
}
