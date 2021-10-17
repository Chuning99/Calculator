#include "lparen.h"
#include "const.h"
Lparen::Lparen()
{

}
Lparen::Lparen(string lparen): _lparen(lparen){

}
int Lparen::type(){ //get type
    return LPAREN;
}

void Lparen::print(){
    cout<<_lparen<<" ";
}
