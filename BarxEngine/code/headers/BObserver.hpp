// File: BObserver.hpp
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

#ifndef BARX_ENGINE_BOBSERVER
#define BARX_ENGINE_BOBSERVER

#include "BMessage.hpp"

/*
* Clase de que observa el mensaje
*/
class BOrbserver {

public:

    /*
    * Se ejecuta al recibir un mensaje
    */
    virtual void handle(const BMessage & m) = 0;

};
#endif