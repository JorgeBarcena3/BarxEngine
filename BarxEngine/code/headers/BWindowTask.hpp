// This is free code released into the public domain.
// Drafted by Ángel on March 2017.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

// File: BWindowTask.hpp
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
//
#pragma once
#include "BtypeDef.hpp"
#include "BTask.hpp"

/*
* Clase que maneja la ventana
*/
class BWindowTask : public BTask
{

public:

    static shared_ptr< BWindowTask > instance;   

private:

    SDL_Window   * window;
    SDL_GLContext  gl_context;

    int width;
    int heigth;

public:


    BWindowTask(const std::string& title, int _width, int _height, bool fullscreen = false);

    ~BWindowTask();   

    void set_fullscreen(uint32_t type = 0);

    void set_windowed();

    unsigned get_width() const;

    unsigned get_height() const;

    void set_windowTitle(const char* title);

    void set_position(int new_left_x, int new_top_y);

    void set_size(int new_width, int new_height);   

    void swap_buffers() const;

    void clear() const;

    virtual bool initialize();

    virtual bool finalize();

    virtual bool execute(float time);

};

