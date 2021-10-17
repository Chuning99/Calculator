#include "variable.h"
#include"const.h"
Variable::Variable():_var("")  //CTOR
{

}
Variable::Variable(string var):_var(var){

}

int Variable::type(){ //get type
    return VARIABLE;
}

void Variable::print(){ //print
    cout<<_var<<" ";
}

int Variable::number(){  //get number
    char v = _var[0];
    int num = int(v);
    return num;
}
