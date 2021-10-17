#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
#include"string.h"
#include"include/stack.h"
#include"graph.h"
#include"graph_info.h"
#include<fstream>
#include<vector>
class animate{
public:
    animate();
    animate(graph_info* info);

    bool check(string func);
    bool find_char(char func);
    bool find_operator(char function);

    void set();//set system
    void run(); //run animate
    void processEvents(); //process events like zoom and pan and stuff
    void update(); //update system graph polt
    void render();// include draw and update
    void Draw(); //draw graph
    void set_info(); //set all information
    void read_file(); //read file functions.txt
    void save_function(Stack<string> function); //save fucntion on txt
    void help_siderbar(); //help sign to help user to use this graph calculator
    void sidebar_update();//for domain and function history


private:
    graph_info* _info;    //graph info
    sf::RectangleShape input;  //input stuff
    sf::RectangleShape help_key;  //for help stuff
    sf::RectangleShape help_box;
    sf::RectangleShape Backcolor;  //change color(background)

    sf::RenderWindow window;
    sf::CircleShape mousePoint;         //The little red dot
    System system;                      //container for all the animated objects
    int command;                        //command to send to system
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    bool mouseIn;                       //mouse is in the screen
    Sidebar sidebar;                    //rectangular message sidebar
    //for new private
    bool check_input = false;    //uesr input;
    bool help_open = false;   //user input help
    bool control = false;    //for keyboard press control
    bool resetSidebar = false; // reset sidebar
    bool show_first = true;  //first show
    //help box information
    string functionInput;   //input function
    sf::Text input_function;
    sf::Text showDomain;  //show domain in sidebar
    sf::Text signal;       //help
    sf::Text zoom_in;    //zoom in sign
    sf::Text zoom_out;  //zoom out sign
    sf::Text history;    //for history
    sf::Text pan;       //pan
    sf::Text draw;     //draw
    sf::Text close;     //close
    sf::Text save_history; //save history
    sf::Text input_equation; //for input equation
    sf::Text reset_graph; //resrt graph
    sf::Text Triangle;
    sf::Text Rule;
    sf::Text InputX;


    //stack
    Stack<string> functions; //for sidebar

};

string mouse_pos_string(sf::RenderWindow& window);

#endif // GAME_H
