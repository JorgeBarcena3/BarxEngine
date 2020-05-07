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

#ifndef BARX_ENGINE_BENTITY
#define BARX_ENGINE_BENTITY

#include "BtypeDef.hpp"

/**
* Clases adelantadas
*/
class BComponent;
class BTransformComponent;
class BScene;

/**
* Es la unidad basica del motor
* Una entidad es todo lo que hay en el motor
* Los componentes otorgan caracteristicas a la entidad (Componente de fisicas, de rederizacion de imagenes, de IA...)
*/
class BEntity
{

    string                                  id        ; ///< Id de la entidad

    shared_ptr< BScene                    > scene     ; ///< Escena a la que pertenece

    map< string, shared_ptr< BComponent > > components ; ///< Componentes de la entidad

public:

    shared_ptr< BComponent                > transform ; ///< Transform de la entidad


public:

    /**
    * Constructor de la clase
    */
    BEntity(string id, shared_ptr<BScene> scene);

    /**
    * Inicializa la entidad
    */
    bool initialize();

    /**
    * Devuelve el transform de la entidad
    */
    shared_ptr<BTransformComponent> getTransform(); 
    

    /**
    * Devuelve la escena en la que está
    */
    shared_ptr<BScene> getScene();   

    /**
    * Clases adelantadas
    */
    bool addComponent
    (
        const string& type,                  ///< Tipo de componente
        shared_ptr< BComponent >& component  ///< Componente que hay que añadir
    );

    /**
    * Devuelve un componente en concreto de la entidad
    */
    template <class T>
    shared_ptr<T> getComponent()
    {
        for (auto component : components)
        {
            auto thing = dynamic_pointer_cast<T>(component.second);

            if (thing != nullptr)
                return thing;
        }

        return shared_ptr<T>(nullptr);

    };

    /**
    * Devuelve el ID de la entidad
    */
    const string getId();

    /**
    * Devuelve todos los componentes
    */
    list<shared_ptr<BComponent>> getComponents();

    /**
    * Elimina la entidad
    */
    void removeEntity();

};
#endif