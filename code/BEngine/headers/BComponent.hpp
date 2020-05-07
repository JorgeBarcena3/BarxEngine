// File: BComponent.hpp
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

#ifndef BARX_ENGINE_BCOMPONENT
#define BARX_ENGINE_BCOMPONENT

#include "BtypeDef.hpp"

/**
* Clases adelantadas
*/
class BEntity;
class BTask;
class BTransformTask;
class BRenderTask;

using namespace glt;

/**
* Componentes que son poseidos por las entidades
*/
class BComponent
{

private:

    COMPONENT_INITIALIZATION priority;

protected:

    string              id;  ///< Id del componente
    shared_ptr<BEntity> parent;  ///< Entidad que posee el componente
    shared_ptr<BTask  >   task;  ///< Tarea que tiene asignada

public:

    /**
    * Constructor por defecto
    */
    BComponent(shared_ptr<BEntity> parent, COMPONENT_INITIALIZATION prior = COMPONENT_INITIALIZATION::DEFAULT_COMPONENT);

    /**
    * Destructor por defecto
    */
    virtual ~BComponent();

    /**
    * Función virtual pura
    * Se ejetua al inicializar el componente
    */
    virtual bool initialize() = 0;

    /**
    * Función virtual pura
    * Parsea las propiedades del xml
    */
    virtual bool parse_property
    (
        const string& name,
        const string& value
    ) = 0;

    /**
    * Devuelve la tarea que tiene asignada, en caso de que la tenga
    */
    shared_ptr<BTask> getTask();

    shared_ptr<BEntity> getEntity();

public:

    /**
   * Sobrecarga del operador <
   */
    bool operator < (const BComponent& other);

};
#endif