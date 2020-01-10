#pragma once
#include "BtypeDef.hpp"

class BTimerPerformance
{

    uint64_t start_ticks;

public:

    BTimerPerformance()
    {
        start();
    }

    void start()
    {
        start_ticks = SDL_GetPerformanceCounter();
    }

    double elapsed_seconds()
    {
        double elapsed_ticks = double(SDL_GetPerformanceCounter() - start_ticks);

        return elapsed_ticks / SDL_GetPerformanceFrequency();
    }

};