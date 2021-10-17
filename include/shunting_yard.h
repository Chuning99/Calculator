#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include"stack.h"
#include"Queue2.h"
#include"token.h"
#include"number.h"
#include"const.h"
class shunting_yard
{
public:
    shunting_yard();
    shunting_yard(Queue<Token*> infix);
    Queue<Token*> postfix();
private:
    Queue<Token*> _infix;
    Queue<Token*> _postfix;
    Stack<Token*> _oper;
};

#endif // SHUNTING_YARD_H
