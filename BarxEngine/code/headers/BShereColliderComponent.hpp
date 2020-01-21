// File: BShereColliderComponent.hpp
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

#ifndef BARX_ENGINE_BSPHERECOLLIDERCOMPONENT
#define BARX_ENGINE_BSPHERECOLLIDERCOMPONENT
#include "BtypeDef.hpp"

/*
* Clases adelantadas
*/
class BComponent;
class BEntity;
class BColliderComponent;
class BTransformComponent;

/*
* Tipo de colisionador de esfera
*/
class BShereColliderComponent : public BColliderComponent
{

    shared_ptr < BTransformComponent > transform; ///< Posici�n del objeto

public:

    float                               radius  ; ///< Radio del collider de la esfera
    
    /*
    * Constructor por defecto del collider de la esfera
    */
    BShereColliderComponent(shared_ptr <BEntity> parent);

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

    /*
    * Heredado del BColliderComponent
    * Se realiza cuando se produce una colisi�n
    */
    shared_ptr<BEntity> checkCollisions(shared_ptr<BEntity> other);


};
#endif