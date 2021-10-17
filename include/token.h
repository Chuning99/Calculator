#ifndef TOKEN_H
#define TOKEN_H
#include<iostream>
#include"stack.h"
#include"Queue2.h"

class Token
{
public:
    Token();
    Queue<Token*> getInfix(string input);
    virtual int type();
    virtual void print();
    virtual int precedence();  //
    virtual int number();
    virtual double realnumber();
    virtual string get_oper();
};


#endif // TOKEN_H
