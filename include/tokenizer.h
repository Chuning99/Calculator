#ifndef TOKENIZER_H
#define TOKENIZER_H
#include<iostream>
#include"token.h"
#include"string.h"
#include"operator.h"
#include"function.h"
#include"Queue2.h"
#include"stdio.h"
#include"number.h"
#include"lparen.h"
#include"rparen.h"
#include"variable.h"
class Tokenizer
{
public:
    Tokenizer();
     Queue<Token*> getInfix(string input);
private:
     Queue<char*> infix_token;
     Queue<Token*> infix;
};

#endif // TOKENIZER_H
