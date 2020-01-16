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
