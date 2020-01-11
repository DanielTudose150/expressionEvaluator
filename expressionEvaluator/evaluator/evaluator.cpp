//
// Created by legen on 06-Jan-20.
//

#include "evaluator.h"

struct variabile var[1000];

unsigned int lungimeVal=0;
bool userVariables=false;
unsigned int pozV;
double userVar;
double x;
bool hasError;
std::string errorType;


void push(struct variabile a[],std::string nume,unsigned int &i)
{
    a[i].name=nume;
    a[i++].isAssigned=1;
}

bool inStruct(struct variabile a[],unsigned int &len,std::string nume,unsigned int &poz)
{
    if(len==0)
        return 0;
    for(unsigned int i=0;i<len;++i)
        if(a[i].name==nume)
        {
            poz=i;
            return 1;
        }
    return 0;
}

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


bool isLeftOperator(const char &c)
{
    return (c=='<' || c=='>');
}

bool isRightOperator(const char &c)
{
    return (c=='<' || c=='>');
}

bool isComma(const std::string &s)
{
    return s==",";
}

bool isLeftParan(const std::string &s)
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

bool isCosntant(const std::string &s)
{
    std::string b=s;
    toLower(b);
    return (b=="e" ||
            b=="c" ||
            b=="pi" ||
            b=="tau" ||
            b=="true" ||
            b=="false");
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
            b=="truncate" ||
            b=="log_u" ||
            b=="log_b");
}

bool isLog(const std::string &s)
{
    std::string b=s;
    toLower(b);
    return (b=="log");
}

bool isBinaryFunction(const std::string &s)
{
    std::string b=s;
    toLower(b);
    return (b=="atan2" ||
            b=="bigmul" ||
            b=="divrem" ||
            b=="ieeeremainder" ||
            b=="max" ||
            b=="min" ||
            b=="pow" ||
            b=="log_b");
}

unsigned short operatorPrio(const std::string &s)
{
    std::string b=s;
    toLower(b);
    if(b=="neg")
        return 1;
    if(b=="*" || b=="/")
        return 2;
    if(isFunction(b))
        return 2;
    if(b=="\\")
        return 3;
    if(b=="mod")
        return 4;
    if(b=="+" || b=="-")
        return 5;
    if(b=="=" || b=="<" || b=="<=" || b==">" || b==">=" || b=="<>")
        return 6;
    if(b=="not" || b=="and" || b=="or" || b=="xor")
        return 7;
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

        if(!isalnum(expression[i]))
        {
            if(isLeftOperator(expression[i])) {
                if (isRightOperator(expression[i + 1])) {
                    token = expression.substr(i, 2);
                    infixQ.push(token);
                    i += 2;
                    continue;
                }
            } else{

                token=expression.substr(i,1);
                if(token=="#")
                    token="<>";
                infixQ.push(token);
                ++i;
                continue;
            }
        }

        unsigned int j=i+1;
        while(j<len)
        {
            if(expression[j]=='.')
            {
                ++j;
                continue;
            }

            if(!isalnum(expression[j]))
            {
                break;
            }

            ++j;
        }

        token=expression.substr(i,j-i);

        if(isCosntant(token))
        {
            if(token!="E")
                token=toConstant(token);
        }
        if(!isFunction(token)) {
            if (!isdigit(token[0])) {
                if (token != "x") {
                    if (!inStruct(var, lungimeVal, token, pozV)) {
                        push(var, token, lungimeVal);
                        userVariables = 1;
                    }
                }
            }
        } else {
            if (isLog(token)) {
                if (expression[i+3] == '(') {
                    std::string aux = expression.substr(i, expression.size() - i + 1);
                    token = logType(aux);
                }
            }
        }
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

        if(operatorStack.isEmpty())
        {
            operatorStack.push(token);
            infixQ.pop();
            lastNumber=false;
            continue;
        }

        if(isLeftParan(operatorStack.top()))
        {
            operatorStack.push(token);
            lastNumber=false;
            infixQ.pop();
            continue;
        }

        unsigned short prioOp1=operatorPrio(operatorStack.top());
        unsigned short prioOp2=operatorPrio(token);
        if(prioOp2<prioOp1)
        {
            operatorStack.push(token);
            infixQ.pop();
            lastNumber=true;
            continue;
        } else
            if(prioOp1==prioOp2)
            {
                postQ.push(operatorStack.top());
                operatorStack.pop();
                lastNumber=true;
                continue;
            }
            else
            {
                postQ.push(operatorStack.top());
                operatorStack.pop();
                lastNumber=true;
                continue;
            }
    }
    while(!operatorStack.isEmpty())
    {
        postQ.push(operatorStack.top());
        operatorStack.pop();
    }
}

double stringToDouble(std::string &s)
{
    double x=0;
    const unsigned int len=s.size();
    for(unsigned int i=0;i<len;++i)
    {
        x=x*10+(double)(s[i]-48);
    }
    return (double)(int)x;
}

double stringToDoubleFull(std::string &s)
{
    if(s.find(".")==s.npos)
    {
        double x=stringToDouble(s);
        return x;
    }

    unsigned int poz=s.find(".");

    std::string integer=s.substr(0,poz);
    std::string fractionary=s.substr(poz+1,s.size()-poz);
    double dInteger=stringToDouble(integer);
    double dFractionary=stringToDouble(fractionary);

    poz=fractionary.size();

    for(unsigned int i=0;i<poz;++i)
    {
        dFractionary/=10;
    }

    dInteger+=dFractionary;
    return dInteger;
}

double valueQueue(Queue postQ)
{
    DStack valueStack;
    double rez;

    while(!postQ.isEmpty())
    {
        std::string token=postQ.front();

        if(token=="x")
        {
            valueStack.push(x);
            postQ.pop();
            continue;
        }

        if(inStruct(var,lungimeVal,token,pozV))
        {
            valueStack.push(var[pozV].value);
            postQ.pop();
            continue;
        }

        if(isFunction(token))
        {
            if(isBinaryFunction(token))
            {
                double t2=valueStack.top();
                valueStack.pop();
                double t1=valueStack.top();
                valueStack.pop();
                rez=valueFunction(token,t1,t2);
                valueStack.push(rez);
                postQ.pop();
                continue;
            }

            double t1=valueStack.top();
            valueStack.pop();
            rez=valueFunction(token,t1);
            valueStack.push(rez);
            postQ.pop();
            continue;
        }

        if(isOperator(token))
        {
            if(token=="neg")
            {
                double t1=valueStack.top();
                valueStack.pop();
                rez=-t1;
                valueStack.push(rez);
                postQ.pop();
                continue;
            }

            if(token=="not")
            {
                double t1=valueStack.top();
                valueStack.pop();
                rez=valueFunction(token,t1);
                valueStack.push(rez);
                postQ.pop();
                continue;
            }

            double t2=valueStack.top();
            valueStack.pop();
            double t1=valueStack.top();
            valueStack.pop();
            rez=valueFunction(token,t1,t2);
            valueStack.push(rez);
            postQ.pop();
            continue;
        }

        valueStack.push(stringToDoubleFull(token));
        postQ.pop();
        continue;
    }

    return valueStack.top();
}

double valueFunction(const std::string &s,double t1,double t2)
{
    double rez=0;
    std::string b=s;
    toLower(b);
    if(b=="abs")
    {
        rez=abs(t1);
    }

    if(b=="acos")
    {
        if(!(t1>=-1.0 && t1<=1.0))
        {
            hasError=1;
            errorType="Invalid argument for acos";
            exit(0);
        }
        rez=acos(t1);
    }

    if(b=="asin")
    {
        if(!(t1>=-1.0 && t1<=1.0))
        {
            hasError=1;
            errorType="Invalid argument for asin";
            exit(0);
        }
        rez=asin(t1);
    }

    if(b=="atan")
    {
        rez=atan(t1);
    }

    if(b=="atan2")
    {
        if(t2==0)
        {
            hasError=1;
            errorType="Invalid argument. Division by 0 in atan2";
            exit(0);
        }
        rez=atan2(t1,t2);
    }

    if(b=="bigmul")
    {
        rez=t1*t2;
    }

    if(b=="ceiling")
    {
        rez=ceil(t1);
    }

    if(b=="cos")
    {
        rez=cos(t1);
    }

    if(b=="cosh")
    {
        rez=cosh(t1);
    }

    if(b=="divrem")
    {
        if(t2==0)
        {
            hasError=1;
            errorType="Division by 0 in divrem";
            exit(0);
        }
        rez=t1/t2;
    }

    if(b=="exp")
    {
        rez=exp(t1);
    }

    if(b=="floor")
    {
        rez=floor(t1);
    }

    if(b=="ieeeremainder")
    {
        rez=t1-t2*round(t1/t2);
    }

    if(b=="log_u")
    {
        if(t1<=0)
        {
            hasError=1;
            errorType="Negative argument for log";
            exit(0);
        }
        rez=log(t1);
    }

    if(b=="log10")
    {
        if(t1<=0)
        {
            hasError=1;
            errorType="Negative argument for log";
            exit(0);
        }
        rez=log10(t1);
    }

    if(b=="max")
    {
        rez=(t1>t2 ? t1 : t2);
    }

    if(b=="min")
    {
        rez=(t1<t2 ? t1 : t2);
    }

    if(b=="pow")
    {
        if(t1==t2 && t1==0)
        {
            hasError=1;
            errorType="pow(0,0) not defined";
            exit(0);
        }
        rez=pow(t1,t2);
    }

    if(b=="round")
    {
        rez=round(t1);
    }

    if(b=="sign")
    {
        rez=((t1==0) ? 0 : (t1>0 ? 1 : -1));
    }

    if(b=="sin")
    {
        rez=sin(t1);
    }

    if(b=="sinh")
    {
        rez=sinh(t1);
    }

    if(b=="sqrt")
    {
        if(t1<0)
        {
            hasError=1;
            errorType="Negative square root";
            exit(0);
        }
        rez=sqrt(t1);
    }

    if(b=="tan")
    {

        rez=tan(t1);
    }

    if(b=="tanh")
    {
        rez=tanh(t1);
    }

    if(b=="truncate")
    {
        rez=trunc(t1);
    }

    if(b=="+")
    {
        rez=t1+t2;
    }

    if(b=="-")
    {
        rez=t1-t2;
    }

    if(b=="*")
    {
        rez=t1*t2;
    }

    if(b=="/")
    {
        rez=t1/t2;
    }

    if(b=="\\")
    {
        rez=(int)(t1/t2);
    }

    if(b=="<")
    {
        rez=(t1<t2);
    }

    if(b=="<=")
    {
        rez=(t1<=t2);
    }

    if(b=="=")
    {
        rez=(t1==t2);
    }

    if(b==">")
    {
        rez=(t1>t2);
    }

    if(b==">=")
    {
        rez=(t1>=t2);
    }

    if(b=="<>")
    {
        rez=(t1!=t2);
    }

    if(b=="or")
    {
        rez=(t1 || t2);
    }

    if(b=="and")
    {
        rez=(t1 && t2);
    }

    if(b=="mod")
    {
        rez=t1-t2*(t1/t2);
    }

    if(b=="not")
    {
        rez=!t1;
    }

    if(b=="xor")
    {
        rez=(int)t1^(int)t2;
    }

    if(b=="log_b")
    {
        rez=log(t1)/log(t2);
    }

    return rez;
}

bool isX(const std::string &s)
{
    std::string b=s;
    toLower(b);
    return (b=="x");
}

std::string toConstant(std::string s)
{
    std::string b=s;
    toLower(b);
    if(b=="e")
        b="2.7182818";
    if(b=="c")
        b="0.5772156";
    if(b=="pi")
        b="3.1415926";
    if(b=="tau")
        b="6.2831853";
    if(b=="true")
        b="1";
    if(b=="false")
        b="0";
    return b;
}

bool isMulfPiOn2(double t)
{
    std::string aux="pi";
    aux=toConstant(aux);
    double piF=stringToDoubleFull(aux);
    piF/=2;
    return (piF==t);
}

std::string logType(std::string token)
{
    unsigned int paranthesis=1;
    unsigned int commas=0;
    unsigned int paranSets=1;
    const unsigned int len=token.size();

    for(unsigned int i=4;i<len;++i)
    {
        if(paranthesis==0)
            break;
        if(token[i]=='(')
        {
            ++paranthesis;
            ++paranSets;
        }
        if(token[i]==')')
        {
            --paranthesis;
        }
        if(token[i]==',')
            commas++;
    }

    if(commas==paranSets)
        return "log_b";
    if(commas==0)
        return "log_u";
    std::string aux=token.substr(4,token.size()-3);
    if(!hasLog(aux)) {
        if (!hasBinaryFunction(aux))
            return "log_b";
        unsigned int nr = noBinaryFunctions(aux);
        if (nr < commas)
            return "log_b";
        else
            return "log_u";
    }else{

        unsigned int poz=findLog(aux);
        std::string aux2=aux.substr(poz,aux.size()-poz+1);
        std::string logType2=logType(aux2);
        if(logType2=="log_u")
            return "log_b";
        return "log_u";

    }
}

bool hasLog(std::string s)
{
    toLower(s);
    unsigned int poz=s.find("log");
    if(poz==s.npos)
        return 0;
    if(s[poz+3]=='(')
        return 1;
}


bool hasBinaryFunction(std::string token)
{
    toLower(token);
    std::string binF[]={"atan2","bigmul","divrem","ieeeremainder","max","min","pow"};
    for(unsigned int i=0;i<7;++i)
    {
        if(token.find(binF[i])!=token.npos)
            return 1;
    }
    return 0;
}


unsigned int noBinaryFunctions(std::string token)
{
    toLower(token);
    unsigned int nr=0;
    std::string binF[]={"atan2","bigmul","divrem","ieeeremainder","max","min","pow"};
    for(unsigned int i=0;i<7;++i)
    {
        unsigned int poz=token.find(binF[i]);
        while(poz!=token.npos)
        {
            ++nr;
            poz=token.find(binF[i],poz+binF[i].size());
        }
    }

    return nr;
}

unsigned int findLog(std::string token)
{
    toLower(token);
    unsigned int poz=token.find("log");
    while(poz!=token.npos)
    {
        if(token[3]=='(')
            return poz;
        poz=token.find("log",3);
    }
}