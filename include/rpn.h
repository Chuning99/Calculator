#ifndef RPN_H
#define RPN_H
#include<iostream>
//#include<stack>
#include"stack.h"
//#include"queue.h"
//#include"stack2.h"
#include "Queue2.h"
#include"token.h"
#include"number.h"
#include"function.h"
class Rpn
{
public:
    Rpn(Queue<Token*> input_q);

    double Evalution(double number);
private:
    Queue<Token*> _q;
};

#endif // RPN_H
