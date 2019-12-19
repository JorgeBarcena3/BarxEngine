// File: BMessage.hpp
// Author: Jorge B�rcena Lumbreras

// � Copyright (C) 2019  Jorge B�rcena Lumbreras

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


/*
* Clase que se encarga de manejar los mensajes
*/
class BMessage
{

private:

    //Id unico del mensaje
    Id id;

    //Parametros del mensaje en cuestion
    Params params;


public:

    //Sobrecarga del operador [] que devuelve el variant asignado a una id
    BVariant& operator[](Id id)
    {
        return params[id];
    }

public:

    //Devuelve el Id
    Id getId() { return id; };


};

