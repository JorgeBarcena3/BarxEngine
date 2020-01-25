// File: BColliderTask.hpp
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

#ifndef BARX_ENGINE_BCOLLIDERTASK
#define BARX_ENGINE_BCOLLIDERTASK

#include "BtypeDef.hpp"
#include "BTask.hpp"

/**
* Clases adelantadas
*/
class BEntity;
class BScene;

/**
* Tarea de colision
*/
class BColliderTask : public BTask
{

public:

    /**
    * Constructor de collider
    */
    BColliderTask(shared_ptr<BEntity> transfom, shared_ptr<BScene> scene);

    shared_ptr<BEntity>                                           entity     ;  ///< Entidad de referencia

    std::function<void(shared_ptr<BEntity>, shared_ptr<BEntity>)> onCollision;  ///< Funcion que se ejecuta cuando hay colision


private:

    shared_ptr<BTransformComponent> transform      ;  ///< Transform de la entidad

    list < shared_ptr<BEntity> >    colliderEntites; ///< Entidades que son colisionadoras

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