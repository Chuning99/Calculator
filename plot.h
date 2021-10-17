#ifndef PLOT_H
#define PLOT_H
#include <vector>
#include <SFML/Graphics.hpp>
#include"include/function.h"
#include"include/number.h"
#include"include/operator.h"
#include"include/rpn.h"
#include"include/tokenizer.h"
#include"include/lparen.h"
#include"include/rparen.h"
#include"include/variable.h"
#include"graph_info.h"
#include"translate_coords.h"
#include"include/shunting_yard.h"
class Plot
{
public:
    Plot(graph_info* info); //CTOR
    void set_info(graph_info* info);  //set all information
    vector<sf::Vector2f> operator()(); //() for calculars function and get result
    void set_infix(); //set infix
    void set_postfix(); //set postfix

    Plot( const Plot& plot); //copy CTOR


    Plot& operator =(const Plot& plot); //= Operator

    void set(); //set function

private:
    graph_info* _info;
    Queue<Token*> _infix;
    Queue<Token*> _postfix;
    Tokenizer _tokenizer;
    Translate_coords _translate_co;

};

#endif // PLOT_H
