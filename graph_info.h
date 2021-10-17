#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
#include"constants.h"

struct graph_info{

    string _equation; //set equation
    sf::Vector2f _window_dimensions; //set window_dimension
    sf::Vector2f _origin; //set origin
    sf::Vector2f _scale;  //set scale
    sf::Vector2f _domain; //set domain
    int points;       //set points

};

#endif // GRAPH_INFO_H
