#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>
#include"graph.h"
#include <iostream>
#include"include/operator.h"
#include"include/rpn.h"
#include<cstdio>
#include<cstring>
#include"include/lparen.h"
#include"include/rparen.h"
#include"include/variable.h"
#include"include/function.h"
#include"include/shunting_yard.h"
#include"include/tokenizer.h"
#include"plot.h"
#include"graph_info.h"
using namespace std;
class System
{
public:
    System(graph_info *info); //CTOR
    void Step(int command,graph_info* info); //setp function for function like zoom pan
    //int Size();
    void Draw(sf::RenderWindow& widnow);  //for draw
    //string get_domain();
    void set_info(graph_info* info);  //set all informatino
    System(const System& system);
    System& operator =(System& system);

    void set();


private:
 graph_info* _info;
 Graph _g;

};

#endif // SYSTEM_H
