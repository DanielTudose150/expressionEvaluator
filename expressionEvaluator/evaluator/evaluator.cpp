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

bool isLeftOperator(const char &c)
{
    switch(c)
    {
        case '-':
        case '+':
        case '/':
        case '*':
        case '\\':
        case '<':
        case '>':
        case '=':
        case 'a':
        case 'o':
        case 'x':
        case 'm':
        case 'n':
            return 1;
        default:
            return 0;
    }
}

bool isRightOperator(const char &c)
{
    switch(c)
    {
        case '>':
        case '=':
        case 'r':
        case 'n':
        case 'o':
            return 1;
        default:
            return 0;
    }
}

bool isLetterOperator(const char &c)
{
    return (c=='a' || c=='m' || c=='n' || c=='o' || c=='x');
}

bool isOperatorString(const std::string &s)
{
    return (s=="+"   ||
            s=="-"   ||
            s=="*"   ||
            s=="/"   ||
            s=="\\"  ||
            s=="="   ||
            s=="<"   ||
            s==">"   ||
            s=="<>"  ||
            s=="<="  ||
            s==">="  ||
            s=="or"  ||
            s=="and" ||
            s=="xor" ||
            s=="not" ||
            s=="mod");
}

bool isSeparator(const char &c)
{
    switch(c)
    {
        case '(':
        case ')':
        case ',':
            return 1;
        default:
            return 0;
    }
}

bool isSeparator(const std::string &s)
{
    return (s=="(" ||
            s==")" ||
            s==",");
}

bool isLeftParan(const char &c)
{
    return c=='(';
}

bool isLeftParan(const std::string &s)
{
    return s=="(";
}

bool isRightParan(const char &c)
{
    return c==')';
}

bool isRightParan(const std::string &s)
{
    return s==")";
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
    unsigned i=0;
    std::string aux;
    for(;i<len;)
    {
        if(isspace(expression[i]))
        {
            ++i;
            continue;
        }

        if(isSeparator(expression[i]))
        {
            aux=expression.substr(i,1);
            infixQ.push(aux);
            ++i;
            continue;
        }

        if(isLeftOperator(expression[i]))
        {
            if(!isLetterOperator(expression[i]))
            {
                if(!isRightOperator(expression[i+1]))
                {
                    aux=expression.substr(i,1);
                    infixQ.push(aux);
                    ++i;
                    continue;
                }
                else
                {
                    aux=expression.substr(i,2);
                    infixQ.push(aux);
                    i+=2;
                    continue;
                }
            }
            else
            {
                if(expression[i]=='o')
                {
                    if(i+1<len)
                        if(expression[i+1]=='r')
                            if(i+2<len)
                                if(isspace(expression[i+2]))
                                {
                                    aux=expression.substr(i,2);
                                    infixQ.push(aux);
                                    i+=2;
                                    continue;
                                }
                }
                else
                    if(expression[i]=='a')
                    {
                        if(i+1<len)
                            if(expression[i+1]=='n')
                                if(i+2<len)
                                    if(expression[i+2]=='d')
                                        if(i+3<len)
                                            if(isspace(expression[i+3]))
                                            {
                                                aux=expression.substr(i,3);
                                                infixQ.push(aux);
                                                i+=3;
                                                continue;
                                            }
                    }
                    else
                        if(expression[i]=='m')
                        {
                            if(i+1<len)
                                if(expression[i+1]=='o')
                                    if(i+2<len)
                                        if(expression[i+2]=='d')
                                            if(i+3<len)
                                                if(isspace(expression[i+3]))
                                                {
                                                    aux=expression.substr(i,3);
                                                    infixQ.push(aux);
                                                    i+=3;
                                                    continue;
                                                }
                        }
                        else
                            if(expression[i]=='n')
                            {
                                if(i+1<len)
                                    if(expression[i+1]=='o')
                                        if(i+2<len)
                                            if(expression[i+2]=='t')
                                                if(i+3<len)
                                                    if(isspace(expression[i+3]))
                                                    {
                                                        aux=expression.substr(i,3);
                                                        infixQ.push(aux);
                                                        i+=3;
                                                        continue;
                                                    }
                            } else
                                if(expression[i]=='x')
                                {
                                    if(i+1<len)
                                        if(expression[i+1]=='o')
                                            if(i+2<len)
                                                if(expression[i+2]=='r')
                                                    if(i+3<len)
                                                        if(isspace(expression[i+3]))
                                                        {
                                                            aux=expression.substr(i,3);
                                                            infixQ.push(aux);
                                                            i+=3;
                                                            continue;
                                                        }
                                }
            }
        }

        //TODO !operator, !separator, alteceva;
        unsigned j=i+1;
        while(j<len)
        {
            if(isSeparator(expression[j]))
                break;
        }
    }
}