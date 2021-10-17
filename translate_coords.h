#ifndef TRANSLATE_COORDS_H
#define TRANSLATE_COORDS_H
#include"graph_info.h"
#include<vector>
#include<SFML/Graphics.hpp>
#include<iostream>
class Translate_coords
{
public:
    Translate_coords(graph_info* info);
    sf::Vector2f translate_coord(sf::Vector2f points);
    Translate_coords(){    //default CTOR
        _info = nullptr;
    }
    sf::Vector2f get_trans(){   //get translate co
        return _translate_co;
    }
    Translate_coords( const Translate_coords& tra){  //CTOR
        _info = tra._info;
        _translate_co = tra._translate_co;

    }
private:
    graph_info* _info;
    sf::Vector2f _translate_co;
};

#endif // TRANSLATE_COORDS_H
