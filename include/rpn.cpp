#include "rpn.h"
#include"const.h"
Rpn::Rpn(Queue<Token *> input_q)  //CTOR
{

  _q = input_q;

}

double Rpn::Evalution(double number){

    Stack<Token*> temp;


    while(!_q.Empty()){

        Token* q_it = _q.Front();

        if(q_it->type() == NUMBER){  //get type number
            temp.push(q_it);

        }
        else if(q_it->type() == VARIABLE){
            temp.push(new Number(number));

        }
        else if(q_it->type() ==OPERATOR){    //operator

            if(q_it->number() =='+'){       // addition
                Stack<Token*>::Iterator s_it = temp.top(); //get two element
                temp.pop();
               Stack<Token*>::Iterator  k_it = temp.top();
                temp.pop();
                double result = s_it->_item->realnumber()+k_it->_item->realnumber();

                temp.push(new Number(result));

            }
            else if(q_it->number() == '-'){     //subtraction
                Stack<Token*>::Iterator  s_it = temp.top();//get two element
                temp.pop();
               Stack<Token*>::Iterator  k_it = temp.top();
                temp.pop();
              double result = k_it->_item->realnumber()-s_it->_item->realnumber();
                temp.push(new Number(result));
            }
            else if(q_it->number() == '*'){     //multiplication
                Stack<Token*>::Iterator  s_it = temp.top();//get two element
                temp.pop();

                Stack<Token*>::Iterator   k_it = temp.top();
                temp.pop();

               double result = s_it->_item->realnumber()*k_it->_item->realnumber();

                temp.push(new Number(result));

            }
            else if(q_it->number() == '/'){      //division
                Stack<Token*>::Iterator  s_it = temp.top();//get two element
                temp.pop();
                Stack<Token*>::Iterator  k_it = temp.top();
                temp.pop();
                double result = k_it->_item->realnumber()/s_it->_item->realnumber();
                temp.push(new Number(result));
            }
            else if(q_it->number() == '^' ||q_it->number() == 's'||q_it->number() == 'c'
                    ||q_it->number() == 't'||q_it->number() == 'p'||q_it->number() == 'M'){
                if(q_it->number() == 's'||q_it->number() == 'c' ||q_it->number() == 't'){//check if funciton is tri
                    Stack<Token*>::Iterator  s_it = temp.top();
                    temp.pop();
                    number = s_it->_item->realnumber();
                    Function f(q_it->get_oper());
                    double result = f.Evalution(number);
                    temp.push(new Number(result));
                }
                else if(q_it->number() == 'p'){ //if pi functon 3.1415
                     Function f(q_it->get_oper());
                    double result = f.Evalution();
                    temp.push(new Number(result));
                }
                else if(q_it->number() == 'M'||q_it->number() == '^'){
                    Stack<Token*>::Iterator  s_it = temp.top();//get two element
                    temp.pop();
                    double number1 = s_it->_item->realnumber();
                    Stack<Token*>::Iterator  k_it = temp.top();
                    temp.pop();
                    double number2 = k_it->_item->realnumber();

                    Function f(q_it->get_oper());
                    double result = f.Evalution(number2,number1);
                    temp.push(new Number(result));
                }

            }


        }
        _q.Pop_front();
    }
    double final_result = temp.top()->_item->realnumber();

    return final_result;
}
