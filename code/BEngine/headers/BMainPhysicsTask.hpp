// File: BRenderTask.hpp
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

#ifndef BARX_ENGINE_BMAINPHYSICSTASK
#define BARX_ENGINE_BMAINPHYSICSTASK

#include "BtypeDef.hpp"
#include "BTask.hpp"

/**
* Clases adelantadas
*/
class BMainPhysicsComponent;

/**
* Tarea de render
*/
class BMainPhysicsTask : public BTask
{

    shared_ptr< BMainPhysicsComponent >      physicsComponent; ///< Puntero a la ventana que se esta ejecutando

public:

    /**
    * Constructor por defecto
    */
    BMainPhysicsTask(shared_ptr< BMainPhysicsComponent > _phyComp);

    /**
    * Destructor por defecto
    */
    ~BMainPhysicsTask();

      
    /**
    * Inicializa la tarea
    */
    virtual bool initialize() override;

    /**
    * Finaliza la tarea
    */
    virtual bool finalize() override;

    /**
    * Ejecuta la tarea
    */
    virtual bool execute(float time) override;

};
#endif