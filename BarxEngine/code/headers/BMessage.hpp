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

#ifndef BARX_ENGINE_BMESSAGE
#define BARX_ENGINE_BMESSAGE

#include "BtypeDef.hpp"

/*
* Clase que se encarga de manejar los mensajes
*/
class BMessage
{

public:

    string                id         ; ///< Id del mensaje

    map< string, string > parameters ; ///< Parámetros de los mensajes

    /*
    * Constructor por defecto
    */
    BMessage(const string& id);

    /*
    * Añadimos parametros a los mensajes
    */
    void add_parameter(const string& name, string value);

    /*
    * Devuelve el ID del mensaje
    */
    const string getId();

};
#endif;

