//
// Created by legen on 06-Jan-20.
//

#include "coada.h"

bool Queue::isEmpty() {
    return first== nullptr;
}

void Queue::push(std::string val){
    if(first==nullptr)
    {
        first=new nodeS;
        first->inf=val;
        first->next= nullptr;
        last=first;
    }
    else
    {
        nodeS *p=new nodeS;
        p->inf=val;
        p->next= nullptr;
        last->next=p;
        last=p;
    }
}

void Queue::pop() {
    if(first==last)
    {
        delete first;
        first= nullptr;
        last= nullptr;
    }
    else
    {
        nodeS *p=first;
        first=first->next;
        p->next= nullptr;
        delete p;
    }
}

std::string Queue::front() {
    return first->inf;
}