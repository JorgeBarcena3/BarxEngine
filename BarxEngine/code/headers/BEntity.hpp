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

class BComponent;
class BScene;
/*
* Es la unidad basica del motor
* Una entidad es todo lo que hay en el motor
* Pero como nos diferenciamos entre gamobject, sistemas de particulas...?
* Los componentes otorgan caracteristicas a la entidad (Componente de fisicas, de rederizacion de imagenes, de IA...)
*/
class BEntity
{

    string id;

    shared_ptr<BComponent> transform;

    shared_ptr<BScene> scene;

    shared_ptr<BEntity> parent;

    map< string, shared_ptr< BComponent > > components;

public:

    BEntity(string id);

    bool initialize();

    bool add_component
    (
        const string& type,
        shared_ptr< BComponent >& component
    );

    template <class T>
    shared_ptr<T> getComponent()
    {
        for (auto component : components)
        {
            auto thing = dynamic_pointer_cast<T>(component.second);

            if (thing != nullptr)
                return thing;
        }

        return nullptr;

    };

    const string getId() { return id; }

    list<shared_ptr<BComponent>> getComponents();

};
