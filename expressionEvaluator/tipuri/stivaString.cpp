//
// Created by legen on 06-Jan-20.
//
#include "stivaString.h"

bool SStack::isEmpty() {
    return first==nullptr;
}

void SStack::push(std::string val){
    if(first==nullptr)
    {
        first=new nodeS;
        first->inf=val;
        first->next= nullptr;
    }
    else
    {
        nodeS *p=new nodeS;
        p->inf=val;
        p->next=first;
        first=p;
    }
}

void SStack::pop() {
    if(first->next== nullptr)
    {
        delete first;
        first= nullptr;
    }
    else
    {
        nodeS *p=first;
        first=first->next;
        p->next= nullptr;
        delete p;
    }
}

std::string SStack::top(){
    return first->inf;
}