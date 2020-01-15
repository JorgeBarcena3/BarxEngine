#pragma once
#include "BtypeDef.hpp"

// This is free code released into the public domain.
// Drafted by Ángel on March 2017.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

#pragma once

#include <cstdint>

class BTimer
{

    uint32_t start_ticks;

public:


    BTimer()
    {
        start();
    }

    void start();

    float elapsed_seconds() const
    {
        return float(elapsed_milliseconds()) / 1000.f;
    }

    uint32_t elapsed_milliseconds() const;
};

