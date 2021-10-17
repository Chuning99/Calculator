#include "translate_coords.h"

Translate_coords::Translate_coords(graph_info* info): _info(info)
{

}
sf::Vector2f Translate_coords::translate_coord(sf::Vector2f points){
    //origin x
    double xpos = _info->_origin.x;
    //origin y
    double ypos = _info->_origin.y;
   //tranlate ,using origin point to convex point
    return sf::Vector2f((_info->_scale.x)*(points.x) + xpos,
                       ypos - (_info->_scale.y)*(points.y) );
}
