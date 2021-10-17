#ifndef RPAREN_H
#define RPAREN_H
#include<iostream>
#include"const.h"
#include"token.h"
using namespace std;
class Rparen :public Token
{
public:
    Rparen();
    Rparen(string rparen);
    virtual int type();
    virtual void print();
    virtual int number(){
        return _rparen[0];
    }
private:
    string _rparen;
};

#endif // RPAREN_H
