#include "..\headers\BTimer.hpp"
#include <SDL.h>

void BTimer::start()
{
    start_ticks = SDL_GetTicks();
}

uint32_t BTimer::elapsed_milliseconds() const
{
    return SDL_GetTicks() - start_ticks;
}


