#include "..\headers\BKeyboard.hpp"
#include <SDL.h>

BKeyboard::KEYCODE BKeyboard::keyMapper;// = BKeyboard::KEYCODE();

bool BKeyboard::getKeyDown(string KEY)
{
    SDL_Event event;
    event.type = SDL_KEYDOWN;

    while (SDL_PollEvent(&event) > 0)
    {
        if (KEY == SDL_GetKeyName(event.key.keysym.sym))
        {
            return true;
        }                  
        
    }

    return false;
}

bool BKeyboard::setKeyUp(string key)
{
    SDL_Event event;
    event.type = SDL_KEYUP;

    while (SDL_PollEvent(&event) > 0)
    {
        /*if (event.key.keysym.sym == key)
        {
            return true;
        }*/

    }
    return false;
}
