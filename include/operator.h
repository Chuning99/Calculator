#ifndef OPERATOR_H
#define OPERATOR_H
#include<iostream>
#include"token.h"

class Operator :public Token
{
public:
    Operator();      //operator CTOR
    Operator(string opera);
    Operator(Operator& aOperator); // Copy CTOR
    Operator& operator =(Operator& oper); //= operator
    bool operators(const string& input);
    virtual string get_oper();   //virtual function
    virtual int type();
    virtual void print();
    virtual int number();
    //virtual double realnumber();
    virtual int precedence();
private:
    string _op;
    int _precedence;
};


#endif // OPERATOR_H
