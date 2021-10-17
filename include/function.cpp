#include "function.h"
#include"const.h"
#include <math.h>
Function::Function()  //CTOR
{

}

int Function::type(){  //type
    return OPERATOR;
}
int Function::number(){     //get number
   char number = _function[0];
   int num = int(number);
   return num;
}
Function::Function(string oper):Operator(oper),_function(oper){

}
double Function::Evalution(double number1, double number2){
    double result;
    //for sin function
    if(_function == "sin"){
        result = sin(number1);

    }
    //for cos function
    else if(_function == "cos"){
        result = cos(number1);

    }  //for tan function
    else if(_function == "tan"){
         result = tan(number1);

    }
    //for power function
   else if(_function == "^"){
        result = pow(number1,number2);

    }
    //for find Max between 2 number
    else if(_function == "Max"){
        result = max(number1,number2);
        //cout<<"result of Max = "<<result<<endl;
    }
    //for find Min between 2 number
    else if(_function == "Min"){
         result = min(number1,number2);

    }
    //for pan function result  = 3.1415
    else if(_function == "pi"){
        result = 2*asin(1.0);
    }//other tri function csc
    else if(_function == "csc"){
        result = 1/sin(number1);
    }//other tri function sec
    else if(_function == "sec"){
        result = 1/cos(number1);
    }//other tri funciton cot function
    else if(_function == "cot"){
        result = 1/tan(number1);
    }
  return result;

}
string Function::get_oper(){ //fet function
    return _function;
}
