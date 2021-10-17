#ifndef NUMBER_H
#define NUMBER_H
#include<iostream>
#include"token.h"
using namespace std;
class Number:public Token  //inherit token
{
public:
    Number();      //CTOR
    Number(double number);
    Number(Number& aNumber); //Copy CTOR
    Number& operator =(const Number& num); //= Operator
    virtual int type(); //virtual function
    virtual void print();
    virtual double realnumber();
private:
    double _val;
};

#endif // NUMBER_H
