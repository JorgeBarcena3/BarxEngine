#include "..\headers\BTimer.hpp"
#include <SDL.h>

void BTimer::start()
{
    start_ticks = SDL_GetTicks();
    last_ticks = SDL_GetTicks();
}

uint32_t BTimer::elapsed_milliseconds() const
{
    return SDL_GetTicks() - start_ticks;
}

float BTimer::timeDeltatime()
{
    float time = (SDL_GetTicks() - last_ticks) / 1000.f;
    last_ticks = SDL_GetTicks();

    return time;
}


