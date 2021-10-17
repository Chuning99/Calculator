#ifndef VARIABLE_H
#define VARIABLE_H
#include<iostream>
#include"token.h"

class Variable: public Token
{
public:
    Variable();
    Variable(string var);
    virtual int type();
    virtual void print();
    virtual int number();
private:
    string _var;
};

#endif // VARIABLE_H
