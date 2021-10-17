#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
#include<cstring>
#include"plot.h"
#include"graph_info.h"
#include <SFML/Graphics.hpp>
using namespace std;
class Graph
{
public:
    Graph(graph_info* info); //CTOR

    Graph(const Graph& g);

    Graph& operator =(Graph & g);


    void set();

    void set_info(graph_info* info);  //set all information
    void update(graph_info* info);   //update all information
    void draw(sf::RenderWindow& window); //draw all point and line
    void set_infix();
    void set_postfix();
    void set_xyLine();  //create xy line
    void set_points(); //set all points

private:
    graph_info* _info;
    vector<sf::Vector2f> _points; //points
    Plot _plotter; //call plot class

    sf::RectangleShape x_line; //for x line and y line
    sf::RectangleShape y_line;
    sf::CircleShape circle; //for circle

};

#endif // GRAPH_H
