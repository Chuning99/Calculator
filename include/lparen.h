#ifndef LPAREN_H
#define LPAREN_H
#include<iostream>
#include"token.h"

class Lparen:public Token
{
public:
    Lparen(); //CTOR
    Lparen(string lparen);
    virtual int type(); //virtual function
    virtual void print();
    virtual int number(){
        return _lparen[0];
    }
private:
    string _lparen;
};

#endif // LPAREN_H
