#include "tokenizer.h"
#include<cstring>
#include<cstdio>
Tokenizer::Tokenizer()
{

}
Queue<Token*> Tokenizer::getInfix(string input){
    char temp[input.length()+1];   // char array
    strcpy(temp, input.c_str());
    char * token;
    token = strtok(temp, " ");
    int counter = 0;

    infix.ClearQueue(); // changed
    //check token is not null
    while(token != NULL){
        counter++;
        infix_token.Push_back(token);
        token = strtok(NULL," ");

    }

    while(!infix_token.Empty()){
        string j = infix_token.Pop_front();

        if(j >= "0" && j <= "9" ){ //0-9
            int number = 0;
            for(int i = 0; i < j.length(); i++){
                                          // 48     57     48
                number = number * 10 + j[i] - '0';  //get real number 0-9
            }
            infix.Push_back(new Number(number));
        }

        else if ((j[0] >='a' && j[0] <='z') ||(j[0] == 'M')){  //check if char is s/ c/t
            if(j == "sin"){
                infix.Push_back(new Function("sin"));

            }
            else if(j == "cos"){
                infix.Push_back(new Function("cos"));
            }
            else if(j == "tan"){
                infix.Push_back(new Function("tan"));

            }
            else if(j == "pi"){
                infix.Push_back(new Function("pi"));


            }
            else if(j == "csc"){
                infix.Push_back(new Function("csc"));
            }
            else if(j == "sec"){
                infix.Push_back(new Function("sec"));
            }
            else if(j == "cot"){
                infix.Push_back(new Function("cot"));
            }
            else if(j == "Max"){
                infix.Push_back(new Function("Max"));
            }
            else if(j == "Min"){
                infix.Push_back(new Function("Min"));
            }


        }
        else if(j[0] == 'X'){
            infix.Push_back(new Variable("X"));

        }

          else{   //check if they are +-*/() or ^

                if(j == "+"){
                    infix.Push_back(new Operator("+"));

                }
                else if(j == "-"){
                    infix.Push_back(new Operator("-"));

                }
                else if(j == "*"){
                    infix.Push_back(new Operator("*"));

                }
                else if(j == "/"){
                    infix.Push_back(new Operator("/"));
                }
                else if(j == "^"){
                    infix.Push_back(new Operator("^"));
                }
                else if(j == "("){
                    infix.Push_back(new Lparen("("));
                }
                else if(j == ")"){
                    infix.Push_back(new Rparen(")"));
                }
            }
        }

    return infix;
    }

