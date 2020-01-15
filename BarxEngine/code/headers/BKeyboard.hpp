#pragma once
#include "BtypeDef.hpp"

class BKeyboard
{
public:


    struct KEYCODE 
    {
       const string A  = "A";
       const string B = "B";
       const string C = "C";
       const string D = "D";
       const string E = "E";
       const string F = "F";
       const string G = "G";
       const string H = "H";
       const string I = "I";
       const string J = "J";
       const string K = "K";
       const string L = "L";
       const string M = "M";
       const string N = "N";
       const string O = "O";
       const string P = "P";
       const string Q = "Q";
       const string R = "R";
       const string S = "S";
       const string T = "T";
       const string U = "U";
       const string V = "V";
       const string W = "W";
       const string X = "X";
       const string Y = "Y";
       const string Z = "Z";
       const string N1 = "1";
       const string N2 = "2";
       const string N3 = "3";
       const string N4 = "4";
       const string N5 = "5";
       const string N6 = "6";
       const string N7 = "7";
       const string N8 = "8";
       const string N9 = "9";
       const string N0 = "0";

    };

    static KEYCODE keyMapper;

    static bool getKeyDown(string KEY);

    static bool setKeyUp(string key);
};