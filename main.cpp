#include <iostream>
#include "animate.h"

using namespace std;

/*
 * Author:chuning Liu
 * Project:Final project
 * Purpose: use SFML to Graph function and show on window
 * use Queue and stack to do this
 * user can zoom pan read save stuff
 *
* Notes:
 *I have test many function it works
 *
 */


int main()
{
    cout<<"--------MAIN BEGIN---------------------------"<<endl;

    animate game;
    game.run();
    cout<<endl<<endl<<"------ MAIN EXITING --------------------------"<<endl;
    return 0;



}
