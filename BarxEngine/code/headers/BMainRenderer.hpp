// File: BMainRenderer.hpp
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

#ifndef BARX_ENGINE_BMAINRENDERERCOMPONENT
#define BARX_ENGINE_BMAINRENDERERCOMPONENT

#include "BtypeDef.hpp"

/*
* Clases adelantadas
*/
class BComponent;
class BRenderTask;
class BEntity;

/*
* Clase que se encarga del renderizado general de la escena
*/
class BMainRenderer : public BComponent
{

public:

    /*
    * Constructor por defecto de BMainRenderer
    */
    BMainRenderer(shared_ptr <BEntity> parent);

    /*
    * Heredado del componente
    * Se ejecuta al inicializar el compomente
    */
    bool initialize();

    /*
    * Heredado del componente
    * Parsea las propiedades del xml
    */
    bool parse_property(const string& name, const string& value);

};
#endif