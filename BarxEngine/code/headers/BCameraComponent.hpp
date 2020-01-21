// File: BCameraCollider.hpp
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

#ifndef BARX_ENGINE_BCAMERACOMPONENT
#define BARX_ENGINE_BCAMERACOMPONENT

#include "BtypeDef.hpp"
#include "BObserver.hpp"

/*
* Clases adelantadas
*/
class BComponent;
class BEntity;

/*
* Componente que se encarga del manejo de la camara
*/
class BCameraComponent : public BComponent
{

    shared_ptr< glt::Camera > camera     ; ///< Objeto Camara creado

    float                     fov        ; ///< Propiedad FOV de la camara
    float                     near       ; ///< Propiedad NEAR de la camara
    float                     far        ; ///< Propiedad FAR de la camara
    float                     aspectRatio; ///< Propiedad ASPECTRATIO de la camara


public:

    /*
    * Constructor por defecto de la camara
    */
    BCameraComponent(shared_ptr <BEntity> parent);

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