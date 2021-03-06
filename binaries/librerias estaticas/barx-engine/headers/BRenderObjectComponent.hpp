// File: BRenderObjectComponent.hpp
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

#ifndef BARX_ENGINE_BRENDEROBJECTCOMPONENT
#define BARX_ENGINE_BRENDEROBJECTCOMPONENT

#include "BtypeDef.hpp"

/**
* Clases adelantadas
*/
class BComponent;
class BRenderTask;
class BRenderObjectTask;

/**
* Clase que se encarga de renderizar un modelo 3D
*/
class BRenderObjectComponent : public BComponent
{
    string                     path       ; ///< Path del modelo 3D
    shared_ptr< glt::Model  >  model      ; ///< Objeto del modelo 3D
    vec3      < float       >  color      ; ///< Modifica todo el material por defecto de openGLToolKit (TODO)
    shared_ptr< BRenderTask >  renderTask ; ///< Tarea de la renderizacion


public:

    /**
    * Constructor por defecto de la clase
    */
    BRenderObjectComponent(shared_ptr <BEntity> parent);

    /**
    * Heredado del componente
    * Se ejecuta al inicializar el compomente
    */
    bool initialize();

    /**
    * Heredado del componente
    * Parsea las propiedades del xml
    */
    bool parse_property(const string& name, const string& value); 


};
#endif;