//
// Created by legen on 06-Jan-20.
//

#include "evaluator.h"

void toLower(std::string &s)
{
    const unsigned int len=s.size();
    for(unsigned int i=0;i<len;++i)
        if(isalpha(s[i]))
            if(s[i]<97)
                s[i]+=32;
}

bool isSeparator(const char &c)
{
    return (c=='(' || c==')' || c==',');
}

bool isComma(const std::string &s)
{
    return s==",";
}

bool isLeftParan(const std::stirng &s)
{
    return s=="(";
}

bool isRightParan(const std::string &s)
{
    return s==")";
}

bool isOperator(const std::string &s)
{
    std::string b=s;
    toLower(b);
    return (b=="+" ||
            b=="-" ||
            b=="*" ||
            b=="/" ||
            b=="\\" ||
            b=="=" ||
            b=="<" ||
            b=="<=" ||
            b==">" ||
            b==">=" ||
            b=="<>" ||
            b=="or" ||
            b=="and" ||
            b=="mod" ||
            b=="not" ||
            b=="xor");
}

bool isFunction(const std::string &s)
{
    std::string b=s;
    toLower(b);
    return (b=="abs" ||
            b=="acos" ||
            b=="asin" ||
            b=="atan" ||
            b=="atan2" ||
            b=="bigmul" ||
            b=="ceiling" ||
            b=="cos" ||
            b=="cosh" ||
            b=="divrem" ||
            b=="exp" ||
            b=="floor" ||
            b=="ieeeremainder" ||
            b=="log" ||
            b=="log10" ||
            b=="max" ||
            b=="min" ||
            b=="pow" ||
            b=="round" ||
            b=="sign" ||
            b=="sin" ||
            b=="sinh" ||
            b=="sqrt" ||
            b=="tan" ||
            b=="tanh" ||
            b=="truncate");
}

void putInfixQueue(std::string &expression,Queue &infixQ)
{
    const unsigned int len=expression.size();
    std::string token;
    unsigned int i=0;
    for(;i<len;)
    {
        if(isSeparator(expression[i]))
        {
            token=expression.substr(i,1);
            infixQ.push(token);
            ++i;
            continue;
        }

        if(isspace(expression[i]))
        {
            ++i;
            continue;
        }

        unsigned int j=i+1;
        while(j<len && isalnum(expression[j]))
            ++j;

        token=expression.substr(i,j-i);

        infixQ.push(token);
        i=j;
    }
}

void makePostQueue(Queue &infixQ, Queue &postQ)
{
    SStack operatorStack;
    bool lastNumber=false;
    while(!infixQ.isEmpty())
    {
        std::string token=infixQ.front();

        if(isComma(token))
        {
            infixQ.pop();
            lastNumber=true;
            continue;
        }

        if(isLeftParan(token))
        {
            operatorStack.push(token);
            infixQ.pop();
            lastNumber=false;
            continue;
        }

        if(isRightParan(token))
        {
            while(operatorStack.top()!="(")
            {
                postQ.push(operatorStack.top());
                operatorStack.pop();
            }

            operatorStack.pop();
            infixQ.pop();
            if(!operatorStack.isEmpty())
                if(isFunction(operatorStack.top()))
                {
                    postQ.push(operatorStack.top());
                    operatorStack.pop();
                }
            lastNumber=true;
            continue;
        }

        if(isFunction(token))
        {
            operatorStack.push(token);
            lastNumber=false;
            infixQ.pop();
            continue;
        }

        if(!isOperator(token))
        {
            postQ.push(token);
            infixQ.pop();
            lastNumber=true;
            continue;
        }

        if(token[0]=='-' && !lastNumber)
        {
            operatorStack.push("neg");
            infixQ.pop();
            lastNumber=false;
            continue;
        }

        if(token[0]=='+' && !lastNumber)
        {
            lastNumber= false;
            continue;
        }
    }
}