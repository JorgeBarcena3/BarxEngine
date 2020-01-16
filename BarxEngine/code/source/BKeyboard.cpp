#include "..\headers\BKeyboard.hpp"
#include <SDL.h>


bool BKeyboard::isKeyPresed(string letter)
{
    return std::find(keyPresed.begin(), keyPresed.end(), letter) != keyPresed.end();
}
