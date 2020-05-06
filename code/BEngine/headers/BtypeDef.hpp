// File: BtypeDef.hpp
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

#ifndef BARX_ENGINE_BTYPEDEF
#define BARX_ENGINE_BTYPEDEF

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
#include "BMath.hpp"

using namespace std;

//////// TYPEDEF NECESARIOS ////////

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
    class Camera;
    class Light;

}

enum TASKPRIORITY {
    WINDOW = 0,
    INPUTSYSTEM = 1,
    COLLISIONS = 2,
    TRANSFORM = 3,
    PHYSICSOBJECT = 4,
    PHYSICSWORLD = 5,
    ENTITYUPDATES = 6,
    RENDEROBJECT = 7,
    RENDERGENERAL = 8
};
#endif