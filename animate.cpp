#include "animate.h"
#include "constants.h"
#include <iostream>
#include <fstream>
using namespace std;
#include "system.h"


animate::animate() : _info(new graph_info), system(_info), sidebar(WORK_PANEL,SIDE_BAR){
    cout<<"animate CTOR: TOP"<<endl;
    read_file();
   if(functions.empty()){
      functionInput = "";
   }
   else{
       functionInput = functions.top()->_item;
   }
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Calculator");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will

    window.setFramerateLimit(60);
    //functionInput = "";//for input function
    mouseIn = true;
    //        //help key
    help_key.setSize(sf::Vector2f(50,75));
    help_key.setFillColor(sf::Color(0,140,255)); //
    help_key.move(sf::Vector2f(1045,10));
    help_key.setOutlineColor(sf::Color(128,128,128));
    help_key.setOutlineThickness(1);

    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);
    cout<<"Geme CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //    font file must be in the "working directory:
    //          debug folder
    //    Make sure working directory is where it should be and not
    //      inside the app file:
    //      Project->RUN->Working Folder

    //    font must be a member of the class.
    //      Will not work with a local declaration
    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    myTextLabel = sf::Text("Initial String for myTextLabel", font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setColor(sf::Color::Green);
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));

    //     //input
    input.setSize(sf::Vector2f(1000,100));
    input.move(sf::Vector2f(10,10));
    input.setFillColor(sf::Color(223,255,204));
    input.setOutlineColor(sf::Color::Yellow);
    input.setOutlineThickness(1);
    //    //help box
    help_box.setSize(sf::Vector2f(500,460));
    help_box.move(sf::Vector2f(20,30));
    help_box.setFillColor(sf::Color::Blue);
    help_box.setOutlineColor(sf::Color::Yellow);
    help_box.setOutlineThickness(1);

    //    //for input function
    input_function.setFont(font);
    //    //help signal
    signal.setFont(font);
    signal.setString("help");
    signal.setCharacterSize(15);
    signal.setStyle(sf::Text::Bold);
    signal.setFillColor(sf::Color::Black);
    signal.setPosition(sf::Vector2f(1058,22));
    //show help box on screen
    help_siderbar();

    cout<<"animate instantiated successfully."<<endl;

}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}
void animate::set_info(){
    _info->_domain = sf::Vector2f(RESET_MIN_X,RESET_MAX_X);
    _info->_window_dimensions = sf::Vector2f(WORK_PANEL,SCREEN_HEIGHT);

    _info->_origin = sf::Vector2f(WORK_PANEL/2,SCREEN_HEIGHT/2);
    _info->_scale = sf::Vector2f(_info->_window_dimensions.x / ((_info->_domain.y) - (_info->_domain.x)),
                                 _info->_window_dimensions.y / ((_info->_domain.y) - (_info->_domain.x)));
    _info->points = POINTS_NUM;

    _info->_equation = functionInput;
    System s = System(_info);
    system = s;
    system.set_info(_info);
    system.set();

}
void animate::read_file(){
    ifstream rfile;
    rfile.open("Functions.txt");
    if(rfile.fail()){
        cout<<"Input functions opening failed.\n";
        exit(1);
    }

    string equation;
    getline(rfile,equation);

    while(!rfile.eof()){

        functions.push(equation);
        getline(rfile,equation);
    }

    _info->_equation = functions.top()->_item;


    rfile.close();
}
void animate::save_function(Stack<string> function){
    ofstream sfile;
    sfile.open("Functions.txt");
    if(sfile.fail()){
        cout<<"Output file opening failed.\n";
        exit(1);
    }
    //change order
    vector<string> functionVector;

    int counter = 1;
    string it;

    while(!function.empty() && counter< MAX_FUNC){

        counter++;
        it = function.top()->_item;
        function.pop();
        functionVector.push_back(it);
    }

    for(size_t i = 0; i < functionVector.size(); i++){

        sfile << functionVector[i] << endl;

    }
    sfile.close();
//    Stack<string> it = function;
//    int counter = 1;
//    string It = it.Pop();
//    while ( (!it.empty()) && (counter < MAX_FUNC) ) {
//        functionVector.push_back(It);
//        counter++;
//        It = it.Pop();
//    }
//    //make sure to drop the whitespace
//    functionVector.push_back(It);
//    while ( !functionInput.empty() ) {
//        sfile << functionVector.back()<<endl;
//        functionVector.pop_back();
//    }
//    sfile.close();

}

void animate::help_siderbar(){
    input_equation.setFont(font);
    input_equation.setString("Press [F] to Input Equations");
    input_equation.setCharacterSize(20);
    input_equation.setStyle(sf::Text::Bold);
    input_equation.setFillColor(sf::Color(255,0,0));
    input_equation.setPosition(sf::Vector2f(25,INPUT));

    zoom_in.setFont(font);
    zoom_in.setString("Press [Z] to Zoom in");
    zoom_in.setCharacterSize(20);
    zoom_in.setStyle(sf::Text::Bold);
    zoom_in.setFillColor(sf::Color(255,0,0));
    zoom_in.setPosition(sf::Vector2f(25,ZOOM_IN));

    zoom_out.setFont(font);
    zoom_out.setString("Press Right Shift to Zoom Out");
    zoom_out.setCharacterSize(20);
    zoom_out.setStyle(sf::Text::Bold);
    zoom_out.setFillColor(sf::Color(255,0,0));
    zoom_out.setPosition(sf::Vector2f(25,ZOOM_OUT));

    history.setFont(font);
    history.setString("Left Click the Equation on the Sidebar to Draw it");
    history.setCharacterSize(20);
    history.setStyle(sf::Text::Bold);
    history.setFillColor(sf::Color(255,0,0));
    history.setPosition(sf::Vector2f(25,READ));

    save_history.setFont(font);
    save_history.setString("Press [B] to Save the Equations on the Sidebar");
    save_history.setCharacterSize(20);
    save_history.setStyle(sf::Text::Bold);
    save_history.setFillColor(sf::Color(255,0,0));
    save_history.setPosition(sf::Vector2f(25,SAVE));

    reset_graph.setFont(font);
    reset_graph.setString("Press [R] to Reset the Graph");
    reset_graph.setCharacterSize(20);
    reset_graph.setStyle(sf::Text::Bold);
    reset_graph.setFillColor(sf::Color(255,0,0));
    reset_graph.setPosition(sf::Vector2f(25,RESET));

    pan.setFont(font);
    pan.setString("Press Arrow [Left][Right][Up][Down] to Pan");
    pan.setCharacterSize(20);
    pan.setStyle(sf::Text::Bold);
    pan.setFillColor(sf::Color(255,0,0));
    pan.setPosition(sf::Vector2f(25,PAN));

    draw.setFont(font);
    draw.setString("Press Enter to Draw function");
    draw.setCharacterSize(20);
    draw.setStyle(sf::Text::Bold);
    draw.setFillColor(sf::Color(255,0,0));
    draw.setPosition(sf::Vector2f(25,DRAW));

    close.setFont(font);
    close.setString("Press [E] to close help box");
    close.setCharacterSize(20);
    close.setStyle(sf::Text::Bold);
    close.setFillColor(sf::Color(255,0,0));
    close.setPosition(sf::Vector2f(25,CLOSE));

    Triangle.setFont(font);
    Triangle.setString("Triangle function input like sin ( X )");
    Triangle.setCharacterSize(20);
    Triangle.setStyle(sf::Text::Bold);
    Triangle.setFillColor(sf::Color(255,0,0));
    Triangle.setPosition(sf::Vector2f(25,TRIAN));

    Rule.setFont(font);
    Rule.setString("There must be a space between two characters");
    Rule.setCharacterSize(20);
    Rule.setStyle(sf::Text::Bold);
    Rule.setFillColor(sf::Color(255,0,0));
    Rule.setPosition(sf::Vector2f(25,SPACE));


    InputX.setFont(font);
    InputX.setString("Input X must be capitalized");
    InputX.setCharacterSize(20);
    InputX.setStyle(sf::Text::Bold);
    InputX.setFillColor(sf::Color(255,0,0));
    InputX.setPosition(sf::Vector2f(25,INPUTX));
}
void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);

    window.draw(help_key);
    window.draw(signal);
//    //for input draw
    if(check_input){
        window.draw(input);
        window.draw(input_function);
    }

//   // check help box signal

    if(help_open){
        window.draw(help_box);
        window.draw((zoom_in));
        window.draw(zoom_out);
        window.draw(pan);
        window.draw(draw);
        window.draw(close);
        window.draw(history);
        //window.draw(history_clear);
        window.draw(save_history);
        window.draw(input_equation);
        window.draw(reset_graph);

        //window.draw(Righ_click_delete);
        window.draw(Triangle);
        window.draw(Rule);
        window.draw(InputX);
    }
        if (mouseIn){
            //mousePoint red dot:
            mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                                   sf::Mouse::getPosition(window).y-5);

            //mouse location text for sidebar:
            sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);

            //draw mouse
            window.draw(mousePoint);
        }

    sidebar.draw(window);

//   // - - - - - - - - - - - - - - - - - - -
//   // getPosition() gives you screen coords, getPosition(window) gives you window coords
//    cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
//    //- - - - - - - - - - - - - - - - - - -

//   // drawing Test: . . . . . . . . . . . .
//    //This is how you draw text:)
    window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
}
void animate::sidebar_update(){

}
void animate::update(){
    //cause changes to the data for the next frame

    //input function
    input_function.setCharacterSize(30);
    input_function.setStyle(sf::Text::Bold);
    input_function.setFillColor(sf::Color::Black);
    input_function.setPosition(sf::Vector2f(40,37));

    //for sidebar stuff

   sidebar[SB_DOMAIN] = "Domain: ";
   sidebar[SB_DOMAIN_VALUE] = "("+to_string(_info->_domain.x)+","+to_string(_info->_domain.y)+")";

    sidebar[SB_HISTORY] = "The limit function are 10";


       //now are sidebar function of history
       int number = SB_SIDERBAR_FUNC;
       int counter = 0;

       if(!functions.empty()){
       //cout<<"check here for sidebar"<<endl;
//           if(resetSidebar){
//               int num = SB_SIDERBAR_FUNC;
//               int counter = 10;
//               while(counter >0){
//                   sidebar[num] = "";
//                   num++;
//                   counter--;
//               }
//           }

           //resetSidebar = false;
           Stack<string> temp = functions;

           if(temp.top()->_item != ""){ //for clearn
               while(!temp.empty() && counter <MAX_FUNC){
                   //cout<<"here it is++++++++++++++"<<endl;
                   sidebar[number] = temp.top()->_item;//print 10 function
                   temp.pop();
                   number++;
                   counter++;
               }
           }



       }


    system.Step(command, _info); //set zoom and pan
     command = 0;


}
void animate::render(){
    window.clear();
    Draw(); //draw graph
    window.display();
}



void animate::processEvents()
{
    sf::Event event;
    double mouseX, mouseY;
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::TextEntered: //for input translate unicode to charactor
            if(check_input){
                if(event.text.unicode < 128){ //0-127 ASCII
                    if(event.text.unicode == UNICODE_DE && functionInput.length() >0){
                        functionInput.pop_back(); // use BS
                    }
                    else{

                        functionInput += static_cast<char>(event.text.unicode);
                    }
                    input_function.setString((functionInput));

                }

            }
            break;
            // key pressed:
        case sf::Event::KeyPressed:
            switch(event.key.code){
            case sf::Keyboard::F:
                sidebar[SB_KEY_PRESSED] = "Plz press F to input function";
                functionInput = "";

                check_input = true;
                input_function.setString("f(x) = ");
                window.pollEvent(event);
                set_info();
            case sf::Keyboard::R:
                sidebar[SB_KEY_PRESSED] = "Plz press R to reset";
                //command = COMMD_RESET;
                command = COMMD_NEW_EQUATION;
                functionInput = functions.top()->_item;
                set_info();
                functionInput = "";
                control = true;
                break;
            case sf::Keyboard::Left:
                sidebar[SB_KEY_PRESSED] = "Plz press Left Arrow to pan left";
                control = false;
                command = COMMD_PANLEFT;
                control = true;
                break;
            case sf::Keyboard::Right:
                sidebar[SB_KEY_PRESSED] = "Plz press Right Arrow to pan right";
                command = COMMD_PANRIGHT;
                control = true;
                break;
            case sf::Keyboard::Up:
                sidebar[SB_KEY_PRESSED] = "Plz press Up Arrow to pan up";
                command = COMMD_PANUP;
                control = true;
                break;
            case sf::Keyboard::Down:
                sidebar[SB_KEY_PRESSED] = "Plz press Down Arrow to pan down";
                command = COMMD_PANDOWN;
                control = true;
                break;
            case sf::Keyboard::B:
                sidebar[SB_KEY_PRESSED] = "Plz press B to save history";
                save_function(functions);

                break;
            case sf::Keyboard::E:
                sidebar[SB_KEY_PRESSED] = "Plz press E to close help box";
                help_open = false;
                break;
            case sf::Keyboard::Z:

                sidebar[SB_KEY_PRESSED] = "Plz press Z to  zoom in";

                command = COMMD_ZOOM_IN;
                control = true;
                break;
            case sf::Keyboard::RShift:
                sidebar[SB_KEY_PRESSED] = "Plz press RShif to zoom out";
                command = COMMD_ZOOM_OUT;
                control = true;
                break;
            case sf::Keyboard::Enter:
                if(check_input){
                    sidebar[SB_KEY_PRESSED] = "Plz press Enter to end input";
                    check_input = false;

                    _info->_equation = functionInput;
                    if(check(functionInput)){
                       //for try and catch
                    }
                    else{
                        _info->_equation = "";
                        continue;
                    }

                    set_info();


                    functions.push(_info->_equation);
                    command = COMMD_NEW_EQUATION;
                    functionInput = "";

                }
                control = true;
                break;

            case sf::Keyboard::Escape:
                sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                window.close();
                break;
            }

            break;
        case sf::Event::MouseEntered:
            mouseIn = true;
            break;

        case sf::Event::MouseLeft:
            mouseIn = false;
            break;

        case sf::Event::MouseMoved:
            mouseX = event.mouseMove.x;
            mouseY = event.mouseMove.y;
            //Do something with it if you need to...
            break;
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left)
            {

                sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                        mouse_pos_string(window);
                int x = sf::Mouse::getPosition(window).x;
                int y = sf::Mouse::getPosition(window).y;
                if((x > WORK_PANEL && x < SCREEN_WIDTH )
                        &&( y >= HEAD && y <= BOTTOM)){
                    sidebar[SB_KEY_PRESSED] = "Left Click to read history";
                    int index = (y-HEAD) /25 ;//every char height is


                    Stack<string> fun(functions); //COTR
                    vector<string> stringVector;  //a vector
                    while(!fun.empty()){
                       stringVector.push_back(fun.top()->_item);
                       fun.pop(); //remove first
                    }
                  _info->_equation = stringVector[index];
                  command = COMMD_NEW_EQUATION;
                  system.set_info(_info);
                  system.set();
}

                else{
                    sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                            mouse_pos_string(window);
                    int x = sf::Mouse::getPosition(window).x;
                    int y = sf::Mouse::getPosition(window).y;
                    if((x >= 1045 && x< WORK_PANEL) && (y >0 && y <= 75)){
                        sidebar[SB_KEY_PRESSED] = "Left Click to open help";
                        help_open = true;

                    }
                }
                control = true;

            }
           break;
        default:
            break;
        }
    }
}

void animate::run()
{
   // cout << "Start run" << endl;
    set_info();


    while (window.isOpen())
    {
        processEvents(); //for events like zoom and pan and mouse stuff
        //cout << "while window is open _info _equation: " << _info->_equation << endl;
        if(show_first){ //chack first show then update
            control = true; //control or not
            update();
            control = false;
            show_first = false;
        }
        else{
            if(control){
                update();
                control = false;
            }
        }

        render(); //clear/draw/display

    }

    cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;

}
bool animate::check(string func){
try {
        int counterleft = 0;
        int counterright = 0;
        string save;
        int prec = 0;
        //first case check if it empty if then throw and give error messamge
        if(func.empty()){
            throw 1;
        }

        for(int i=0; func[i]!= NULL; i++){
            switch (func[i]) {
            //for +-*/^ operator
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                if(i == 0 && func[i] != '-'){
                    throw 2;
                }
                //check if input next is NUll then throw
                if(func[i+1] == NULL){
                    throw 3;
                }
                //?????
                if(!find_operator(func[i-2]) || !find_operator(func[i+2])){
                    throw 4;
                }
                break;
                //check triangle function
            case 's':
            case 'c':
            case 't':
            {
                int counter = 3;
                while (counter !=0) { //check if counter != 0
                    save = save + func[i];
                    counter--; //save sin cos tan
                    i++;   //move read s c t
                }
                i--;// move back
                //check if not those function
                if(save != "sin" && save != "cos" && save != "tan" && save != "sec" && save != "csc" && save != "cot"){
                    throw 5;
                }
                //for check space
                if(func[i+1] == ' '){
                    i++;
                }
                //check Lpren if do not have then throw
                if(func[i+1] != '('){  //for example like sin ( X ) must be this
                    throw 6;
                }
                save.clear(); //clearn input and reinput
            }
                break;
            //if ( ) then throw 7
            case '(':
            {
                if(func[i+1] == ')'){
                    throw  7;
                }
                counterleft++;
                prec ++;
            }
                break;
            case ')':
            {
                counterright++;
                prec --;
            }
                break;
            //check pi fuction

            case 'p':
            {    // save the experience start with p , check if the expression is pi
                save = save + func[i];
                i++;
                save = save + func[i];
                if(save != "pi"){
                    throw 8;
                }
                save.clear();
            }
                break;

            default:
            {  //check input function is not follow rule then throw
                if(!find_char(func[i])){
                    throw 9;
                }
            }
                break;


            }
        }
        if(prec  != 0){
            throw 10;
        }
    } catch (int error) {
        //chatch error message
        switch (error) {
        case 1:
            cout << "there is noting" << endl;
            return false;
        case 2:
            cout << "Do not input operator in the head" << endl;
            return false;
        case 3:
            cout << "Do not input operator in the rear" << endl;
            return false;
        case 4:
            cout << "Put wrong operator position" << endl;
            return  false;
        case 5:
            cout << "Triangle function incomplete" << endl;
            return false;
        case 6:
            cout << "No value after Triangle function" << endl;
            return false;
        case 7:
            cout << "Do not input operator in the rear" << endl;
            return false;
        case 8:
            cout << "Error input for pi" << endl;
            return false;
        case 9:
            cout << "invalid input" << endl;
            return false;
        case 10:
              cout<<" Prec not match "<<endl;
              return false;
        }
    }

    return true;

}

bool animate::find_char(char func){
    string Charactor = " 1234567890+-*/^piX"; //for all charactor input
    int count = 0;
    for(int i=0; Charactor[i]!= NULL; i++){
        //check if this char is that we want then check next
        if(func == Charactor[i]){
            count++;
        }
    }
    if(count != 0){
        return true;
    }
    else
        return false;
}
bool animate::find_operator(char function){
    string Charactor = " 1234567890sctnpiX"; //for all charactor input
    int count = 0;
    for(int i=0; Charactor[i]!= NULL; i++){
        //check if this char is that we want then check next
        if(function == Charactor[i]){
            count++;
        }
    }
    if(count != 0){
        return true;
    }
    else
        return false;
}
