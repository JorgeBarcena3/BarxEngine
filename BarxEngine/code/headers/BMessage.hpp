// File: BMessage.hpp
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
#include "BVariant.hpp"

/*
* Clase que se encarga de manejar los mensajes
*/
class BMessage
{

public:

    string id;

    map< string, BVariant > parameters;

    BMessage(const string& id) : id(id)
    {
    }

    void add_parameter(const string& name, const BVariant& value)
    {
        parameters[name] = value;
    }

    const string getId() {
        return id;
    }

};

////////////////////////////////////////////////////////////////////////////////////////////////////

//BMessage key_pressed("key_pressed");
//BVariant key_code();
//key_pressed.add_parameter("key_code", key_code);
//
//message_handler.multicast(key_pressed);


