// File: BKeyboard.hpp
// Author: Jorge Bárcena Lumbreras

// © Copyright (C) 2019  Jorge Bárcena Lumbreras

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef BARX_ENGINE_BKEYBOARD
#define BARX_ENGINE_BKEYBOARD

#include "BtypeDef.hpp"

/**
* Clase que representa la situacion actual del teclado
*/
class BKeyboard
{
public:

    /**
    * Todas las posibles acciones
    */
    struct KEYCODE
    {
        const string A = "A";
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

    /**
    * Se utiliza para acceder a la posicion que esta siendo presionada
    */
    KEYCODE keyMapper;

    /**
    * Lista de teclas presionadas
    */
    list<string> keyPresed;

    /**
    * Pregunta si una tecla está o no presionada
    */
    bool isKeyPresed(string letter);

    /**
    * Pone una tecla presionada
    */
    void setKeyDown(string letter);

    /**
    * Quita una tecla de estar presionada
    */
    void setKeyUp(string letter);

};
#endif