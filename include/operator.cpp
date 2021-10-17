#include "operator.h"
#include"const.h"
Operator::Operator()   //CTOR
{

}
int Operator::type(){    //2 for operator
    return OPERATOR;
}
void Operator::print(){   //Print op
    cout<<_op<<" ";
}
Operator::Operator(string opera){  // operator
    _op = opera;
    if( opera == "+"){  //  * / first, +- last
        _precedence = ADD;
    }
    else if(opera == "-" ){
        _precedence = SUB;
    }
    else if(opera == "*"){
        _precedence = MUL;

    }
    else if(opera == "/"){
        _precedence = DIV;
    }
    else if(opera == "^"){
        _precedence = POWER;
    }
    else {
        _precedence = TRIGANGLE;
    }
}

int Operator::number(){   //number
    char n = _op[0];
    int num = int(n);
    return num;
}
Operator::Operator(Operator& aOperator){  //copy CTOR
    _op = aOperator._op;
}
Operator& Operator::operator =(Operator &oper){  // = operator
    _op = oper._op;
    return *this;
}
int Operator::precedence(){ //get precedence

    return _precedence;
}
string Operator::get_oper(){
    return _op;
}
