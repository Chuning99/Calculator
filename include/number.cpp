#include "number.h"
#include"const.h"
Number::Number()
{

}
Number::Number(double number):_val(number){

}

int Number::type(){  //return 1 for number
    return NUMBER;
}

void Number::print(){  //print number
    cout<<_val<<" ";
}

double Number::realnumber(){    //for rpn to get real number
    return _val;
}
Number::Number(Number& aNumber){ // copy CTOR
    _val = aNumber._val;
}
Number& Number::operator =(const Number& num){ // =operator
    _val = num._val;
    return *this;
}
