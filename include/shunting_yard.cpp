#include "shunting_yard.h"

shunting_yard::shunting_yard()  //CTOR
{

}

shunting_yard::shunting_yard(Queue<Token*> infix):_infix(infix){

}

Queue<Token*> shunting_yard::postfix(){
    _postfix.ClearQueue();
    //check if stack is empty
    while(!_infix.Empty()){
        Token* i =_infix.Pop_front();
        //number
        if(i->type() ==NUMBER){
            //insert
            _postfix.Push_back(i);
        }
        //Variable
        else if(i->type() == VARIABLE){
            _postfix.Push_back(i);
        }
        //Operator
        else if(i->type() ==OPERATOR){
            //check if it empty
            if(_oper.empty()){
                _oper.push(i);
            }
            else{

                //check if the _operator type and precedence
                if(i->type() == _oper.top()->_item->type()){

                    if(_oper.top()->_item->precedence() > i->precedence()){
                        Stack<Token*>::Iterator j = _oper.top();
                        _oper.pop();
                        _postfix.Push_back(j->_item);
                        //check the precedence is power precdence and division precdence
                        if(!_oper.empty() &&(j->_item->precedence() == POWER && _oper.top()->_item->precedence() == DIV)){

                            _postfix.Push_back(_oper.top()->_item);

                        }
                    }

                    //check if not Power precdence;
                    else if(_oper.top()->_item->precedence() ==i->precedence() && i->precedence() != POWER){
                        Stack<Token*>::Iterator j= _oper.top();
                        _oper.pop();
                        _postfix.Push_back(j->_item);
                        // cout<<"j->item : "<<(char)j->_item->number()<<endl;
                    }

                }
                _oper.push(i);
            }
        }
        //check if it (
        else if(i->type() == LPAREN){
            _oper.push(i);
        }
        //check if it )
        else if(i->type() == RPAREN){
            Stack<Token*>::Iterator k = _oper.top();
            _oper.pop();
            //check if k is (
            while (k->_item->type() != LPAREN){
                _postfix.Push_back(k->_item);
                k = _oper.top();
                _oper.pop();
            }

        }
    }
    if(_infix.Empty()){
        while (!_oper.empty())
        {
            _postfix.Push_back(_oper.top()->_item);

            _oper.pop();

        }
    }
    return _postfix;
}
