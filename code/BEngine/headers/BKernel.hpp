// File: BKernel.hpp
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

#ifndef BARX_ENGINE_BKERNEL
#define BARX_ENGINE_BKERNEL

#include "BtypeDef.hpp"
#include "BTimer.hpp"

/**
* Clases adelantadas
*/
class BTask;
class BScene;
class BEntity;

/**
* Maneja el bicle principal del motor
*/
class BKernel
{
    typedef std::vector< shared_ptr<BTask> > BTask_List; ///< Tipo que guarda la lista de tareas
    BTask_List                               BTasks    ; ///< Lista de tareas
    BScene *                                 scene     ; ///< Escena que se está ejecutando
    bool                                     exit      ; ///< Si se debe acabar el ciclo
    bool                                     paused    ; ///< Si se debe parar

public:

    /**
    * Clases adelantadas
    */
    BKernel(BScene * _scene);

    /**
    * Clases adelantadas
    */
    ~BKernel();

    /**
    * Clases adelantadas
    */
    void addTask(shared_ptr<BTask> task);

    /**
    * Clases adelantadas
    */
    void run();

    /**
    * Clases adelantadas
    */
    void stop();
  
    /**
    * Clases adelantadas
    */
    void pause();   

    /**
    * Clases adelantadas
    */
    void resume();

    /**
    * Clases adelantadas
    */
    BScene * getScene();

    /**
    * Elimina las tareas de la entidad
    */
    void removeTaskForEntity(BEntity* entity);

private:


    vector<shared_ptr<BTask>> toRemoveTask;

    /**
    * Elimina las tareas que estan en la cola
    */
    void removeEntitiesQueue();

};
#endif