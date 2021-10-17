#include "graph.h"

Graph::Graph(graph_info* info): _info(info),_plotter(info)
{

}
Graph::Graph(const Graph& g): _info(g._info), _plotter(_info){

}
Graph& Graph::operator =(Graph& g){ //= operator

    _info = g._info;
    return *this;
}
void Graph::set_info(graph_info *info){
    _info->_equation = info->_equation; //get equation
    _info->_domain = info->_domain; //get domain
    _info->_origin = info->_origin; //get center
    _info->_scale = info->_scale; //get scale
    _info->_window_dimensions = info->_window_dimensions; //get window length and weight
    _plotter.set_info(_info);//get point all information
}
void Graph::set(){

    _plotter = Plot(_info); //set plot
    _plotter.set();  //set plot

    set_xyLine(); //set x y line and size of ball
    set_points(); //set point


}
void Graph::set_infix(){  // set infix same like plot
    _plotter.set_infix();
}
void Graph::set_postfix(){ //set postfix same like postfix
    _plotter.set_postfix();
}
void Graph::set_xyLine(){ //draw x and y line and circle size
    //draw x_axis
    x_line = sf::RectangleShape();
    x_line.setSize(sf::Vector2f(1120,1));

    x_line.move(sf::Vector2f(0,_info->_origin.y));

    x_line.setFillColor(sf::Color::Green);

    //draw y_axis
    y_line = sf::RectangleShape();
    y_line.setSize(sf::Vector2f(1,800));
    y_line.move(sf::Vector2f(_info->_origin.x,0));
    y_line.setFillColor(sf::Color::Green);
    //set circle size = 1
    circle = sf::CircleShape(1);
}

void Graph::set_points(){

    _points = _plotter();
}
void Graph::update(graph_info * info){


//        set_info(info);
//        set();
    _points = _plotter();
}

void Graph::draw(sf::RenderWindow& window){
    //draw x line and y line
    window.draw(x_line);
    window.draw(y_line);

    //draw every x and y position in function we need calculars
    if(_points.empty()){

        return ;
    }
    for(size_t i = 0; i < _points.size(); i++){


        circle.setPosition(_points[i].x,_points[i].y);//draw every points position
        circle.setFillColor(sf::Color::Red);
        window.draw(circle);
    }

}
