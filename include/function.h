#ifndef FUNCTION_H
#define FUNCTION_H
#include<iostream>
#include"operator.h"
#include"string.h"
using namespace std;
class Function:public Operator
{
public:
    Function();  //CTOR
    Function(string oper); //string
    double Evalution(double number1 = 0, double number2 = 0);//put x or y value
    virtual string get_oper();   // virtual funciton
    virtual int type();
    virtual int number();

private:
    string _function;
    //Rpn rpn;
};
#endif // FUNCTION_H
