#include "rparen.h"

Rparen::Rparen() //CTOR
{

}
Rparen::Rparen(string rparen):_rparen(rparen){

}
int Rparen::type(){   //(
    return RPAREN;
}

void Rparen::print(){   //print
    cout<<_rparen<<" ";
}
