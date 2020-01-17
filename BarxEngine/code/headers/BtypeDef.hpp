// File: BTypeDef.hpp
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
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <thread> 
#include <functional>
#include <list> 
#include <string>
#include <sstream>
#include <cstdlib>
#include <assert.h>
#include <vector>
#include <iterator>  
#include <iostream>

using namespace std;

typedef int_fast16_t Id;

typedef short byte;

//////// SDL y OPENGL ////////

typedef struct SDL_Window   SDL_Window;
typedef void* SDL_GLContext;
class Render_Node;

namespace glt
{

    class Render_Node;
    class Model;

}


template <class T>
struct vec3 {

    T x;
    T y;
    T z;

    void setValues(T _x, T _y, T _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    void normalize() {

        float inv_magnitude = inv_length();
        x = x * inv_magnitude;
        y = y * inv_magnitude;
        z = z * inv_magnitude;
    }

    T inv_length() {
        return 1 / sqrt((x * x) + (y * y) + (z * z));
    }

};

enum TASKPRIORITY {
    WINDOW = 0,
    INPUTSYSTEM = 1,
    COLLISIONS = 2,
    TRANSFORM = 4,
    ENTITYUPDATES = 5,
    RENDEROBJECT = 6,
    RENDERGENERAL = 7
};


