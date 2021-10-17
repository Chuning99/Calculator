#include "plot.h"

Plot::Plot(graph_info* info):_info(info),_translate_co(_info){
 //blank
}
Plot::Plot( const Plot& plot): _info(plot._info),_translate_co(plot._info){

 }
Plot& Plot::operator =(const Plot& plot){
   //=operator
    _info = plot._info;
    _translate_co.get_trans();
    return *this;
}
void Plot::set(){ //set infix and postfix
     //simplely funciton
    set_infix();
    set_postfix();
}
void Plot::set_info(graph_info *info){

    _info->_domain = info->_domain;//get domain
    _info->_equation = info->_equation; //get equation
    _info->_origin = info->_origin; //get center
    _info->_scale = info->_scale; //get scale
    _info->_window_dimensions = info->_window_dimensions;//window length and weight

}
void Plot::set_infix(){ //set infix for only calculars once  normal queue
    if(_info->_equation == ""){
        return ;
    }
    Queue<Token*> infix = _tokenizer.getInfix(_info->_equation);
    if(_infix.Empty()){

    }
    else{

        _infix.ClearQueue();
        //_infix.PrintQueue();
    }
    while(!infix.Empty()){
        Token* it = infix.Pop_front();
        _infix.Push_back(it);
    }
}
void Plot::set_postfix(){ // reverse order queue like 3 5 +
    if(_info->_equation == ""){
        return ;
    }
    shunting_yard shuntyard(_infix);
    Queue<Token*> temp = shuntyard.postfix();
    _postfix.ClearQueue();
    //_postfix.PrintQueue();
    while(!temp.Empty()){
        Token* it = temp.Pop_front();
        _postfix.Push_back(it);
    }
}
vector<sf::Vector2f>Plot::operator()(){
    vector<sf::Vector2f> screen_coords;
    if(_info->_equation == ""){
        return screen_coords;
    }
       Rpn rpn(_postfix);

        //max and min x then pass they to Rpn function
        double xMin = _info->_domain.x;
        double xMax = _info->_domain.y;
        //it increment(big-small)/total points
        double increment = (xMax-xMin)/_info->points;
        double ypos;
        for(double x = xMin; x< xMax+1; x += increment){
            Rpn rpn(_postfix);

            ypos = rpn.Evalution(x);

            sf::Vector2f point(x,ypos);
            point = _translate_co.translate_coord(sf::Vector2f (point));

            screen_coords.push_back(point);
        }

        return screen_coords;
    }

