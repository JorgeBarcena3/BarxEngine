// File: BEntity.hpp
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
#include "BComponent.hpp"

/*
* Es la unidad basica del motor
* Una entidad es todo lo que hay en el motor
* Pero como nos diferenciamos entre gamobject, sistemas de particulas...?
* Los componentes otorgan caracteristicas a la entidad (Componente de fisicas, de rederizacion de imagenes, de IA...)
*/
class BEntity
{

    //BTransform_Component transform;

    map< string, shared_ptr< BComponent > > components;

public:

    bool initialize()
    {
        bool result = true;

        for (auto component : components)
        {
            if (component.second->initialize() == false)
            {
                result = false;
            }
        }

        return result;
    }

    bool add_component
    (
        const string& type,
        shared_ptr< BComponent >& component
    )
    {
        if (components.count(type) != 0)
        {
            return false;
        }
        else
        {
            components[type] = component;
            return true;
        }
    }

};
