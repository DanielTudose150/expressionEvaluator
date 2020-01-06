#include "stivaDouble.h"

bool DStack::isEmpty() {
    return first== nullptr;
}

void DStack::push(double val) {
    if(first== nullptr)
    {
        first=new nodeD;
        first->val=val;
        first->next= nullptr;
    }
    else
    {
        nodeD *p=new nodeD;
        p->val=val;
        p->next=first;
        first=p;
    }
}

void DStack::pop() {
    if(first->next== nullptr)
    {
        delete first;
        first= nullptr;
    }
    else{
        nodeD *p=first;
        first=first->next;
        p->next= nullptr;
        delete p;
        }
}

double DStack::top() {
    return first->val;
}