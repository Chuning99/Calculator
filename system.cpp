#include "system.h"
#include "random.h"
#include <iostream>

#include <constants.h>
System::System(graph_info* info):_info(info),_g(info)
{

}

void System::set_info(graph_info* info){

    _info->_domain = info->_domain;
    _info->_equation = info->_equation;

    _info->_origin = info->_origin;
    _info->_scale = info->_scale;
    _info->_window_dimensions = info->_window_dimensions;
    _g.set_info(_info);

}

System::System(const System& system): _info(system._info),_g(_info){   //Copy CTOR

}

//------------------------------------------------------------------
//------------------------------------------------------------------
void System::set(){  //set graph

    _g.set();
}
System& System::operator =(System& system){
   //= operator
    _info = system._info;
    return *this;
}
void System::Step(int command,graph_info* info){
    //set all infomation
   double zoom_number = 1.2; //zoom number
    double pan_number = 0.2;  //pan number

//    //when zoom in
    if(command == COMMD_ZOOM_IN){
        set_info(_info);
        set();
        // *domain and range that make it smaller to get we want
        _info->_domain.x =  _info->_domain.x * zoom_number;
        _info->_domain.y =  _info->_domain.y * zoom_number;
        _info->_scale.x = _info->_window_dimensions.x/((_info->_domain.y)-(_info->_domain.x));
        _info->_scale.y = _info->_window_dimensions.y/((_info->_domain.y)-(_info->_domain.x));

    }
    else if(command == COMMD_ZOOM_OUT){
        //  /domain and range that make it bigger to get we want zoom out
        _info->_domain.x /= zoom_number;
        _info->_domain.y /= zoom_number;
        _info->_scale.x = _info->_window_dimensions.x /((_info->_domain.y)-(_info->_domain.x));
        _info->_scale.y = _info->_window_dimensions.y/((_info->_domain.y)-(_info->_domain.x));

    }
    else if(command == COMMD_PANLEFT){
        double temp1, temp2;
        //in order to pan left, we need to change y-x and window we need
        //release the window
        temp1 = _info->_domain.y - _info->_domain.x;   //range
        temp2 = _info->_window_dimensions.x * pan_number;
        //then for pan left we also need to change the center of axis which is origin
        //graoh pan left, then domain will move right
        _info->_origin.x -= temp2;
        //how far to move domain
        _info->_domain.x += temp2 / (_info->_window_dimensions.x / temp1);//winfow and temp ratio
        _info->_domain.y += temp2 / (_info->_window_dimensions.x / temp1);
        _g.set_xyLine();
    }
    else if(command == COMMD_PANRIGHT){
        //same like pan left but is +=
        double temp1, temp2;
        //in order to pan left, we need to change y-x and window we need
        //release the window
        temp1 = _info->_domain.y - _info->_domain.x;
        temp2 = _info->_window_dimensions.x * pan_number;
        //then for pan left we also need to change the center of axis which is origin
        _info->_origin.x += temp2;

        _info->_domain.x -= temp2 / (_info->_window_dimensions.x / temp1);
        _info->_domain.y -= temp2 / (_info->_window_dimensions.x / temp1);
         _g.set_xyLine();

    }
    else if(command == COMMD_PANUP){
        //move the cent up
        double temp = _info->_window_dimensions.y* pan_number;
        _info->_origin.y -= temp;
         _g.set_xyLine();
    }
    else if(command == COMMD_PANDOWN){
        //move the center down
        double temp = _info->_window_dimensions.y * pan_number;
        _info->_origin.y += temp;
         _g.set_xyLine();
    }
    else if(command == COMMD_NEW_EQUATION){
        //set new equation
        _info->_equation = info->_equation;
    }
    else if(command == COMMD_RESET){
        //reset everything

        _info->_domain = sf::Vector2f(RESET_MIN_X,RESET_MAX_X);
        _info->_window_dimensions = sf::Vector2f(WORK_PANEL,SCREEN_HEIGHT);
        _info->_origin = sf::Vector2f((double)WORK_PANEL/2,(double)SCREEN_HEIGHT/2);
        _info->_scale = sf::Vector2f(_info->_window_dimensions.x/(_info->_domain.y)-(_info->_domain.x),0);
        _info->points = POINTS_NUM;

//        _info->_equation = info->_equation;
//        cout<<_info->_equation<<endl;
//        _g.set_xyLine();
//        _g.set_points();
//        _g.set_info(_info);
//        _g.set();
    }
    _g.update(_info);

}


void System::Draw(sf::RenderWindow& window){
   //draw graph
   _g.draw(window);

}
