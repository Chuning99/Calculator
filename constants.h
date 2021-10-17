#ifndef CONSTANTS_H
#define CONSTANTS_H
const float SCREEN_WIDTH = 1400;
const float SCREEN_HEIGHT = 800;
const float WORK_PANEL = SCREEN_WIDTH*4/5; //1120
const float SIDE_BAR = SCREEN_WIDTH*1/5;


const int SB_MOUSE_POSITION = 0;
const int SB_MOUSE_CLICKED = SB_MOUSE_POSITION + 1;
const int SB_KEY_PRESSED = 30;
const int SB_DOMAIN = 2;
const int SB_DOMAIN_VALUE = 3;
const int SB_HISTORY = 4;
const int SB_SIDERBAR_FUNC = 5;



const int COMMD_NEW_EQUATION = 0;
const int COMMD_ZOOM_IN = 1;
const int COMMD_ZOOM_OUT = 2;
const int COMMD_PANLEFT = 3;
const int COMMD_PANRIGHT = 4;
const int COMMD_PANUP = 5;
const int COMMD_PANDOWN = 6;
const int COMMD_RESET = 7;

const int POINTS_NUM = 10000;
const int RESET_MIN_X = -5;
const int RESET_MAX_X = 5;


const int MAX_FUNC = 10;
const int UNICODE_DE = 8;

const int INPUT = 50;
const int ZOOM_IN = 80;
const int ZOOM_OUT = 110;
const int RESET = 200;
const int READ = 140;
const int SAVE = 170;
const int PAN = 230;
const int DRAW = 260;
const int CLOSE = 290;
const int TRIAN = 320;
const int SPACE = 350;
const int INPUTX = 390;


const int HEAD = 140;
const int BOTTOM = 528;
const int SACLE = (BOTTOM-HEAD)/MAX_FUNC;
#endif // CONSTANTS_H
