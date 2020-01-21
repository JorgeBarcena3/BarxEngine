// File: BKeyboard.cpp
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

#include "..\headers\BtypeDef.hpp"
#include "..\headers\BKeyboard.hpp"
#include <SDL.h>

bool BKeyboard::isKeyPresed(string letter)
{
    return std::find(keyPresed.begin(), keyPresed.end(), letter) != keyPresed.end();
}

void BKeyboard::setKeyDown(string letter)
{
    if (std::find(keyPresed.begin(), keyPresed.end(), letter) == keyPresed.end())
        keyPresed.push_back(letter);
}

void BKeyboard::setKeyUp(string letter)
{
    if (std::find(keyPresed.begin(), keyPresed.end(), letter) != keyPresed.end())
        keyPresed.remove(letter);
}
