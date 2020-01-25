// File: BTask.hpp
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

#ifndef BARX_ENGINE_BTASK
#define BARX_ENGINE_BTASK

#include "BtypeDef.hpp"

/**
* Clases adelantadas
*/
class BKernel;
class BRenderTask;
class BRenderTask;
class BTransformComponent;

/**
* Tareas que se ejecutaran en cada vuelta de bucle
*/
class BTask
{

protected:

    BKernel* kernel; ///< Kernel al que está adjudicado la tarea

    string id;       ///< Id de la tarea

public:

    int priority;    ///< Prioridad de la tarea

    /**
    * Constructor por defecto
    */
    BTask(int priority = 0);

    /**
    * Destructor por defecto
    */
    virtual ~BTask();

    /**
    * Selecciona un kernel
    */
    void setKernel(BKernel* new_kernel);

public:

    /**
    * Inicializa la tarea
    */
    virtual bool initialize()        = 0;

    /**
    * Finaliza la tarea
    */
    virtual bool finalize()          = 0;

    /**
    * Ejecuta la tarea 
    */
    virtual bool execute(float time) = 0;


public:

    /**
    * Sobrecarga del operador <
    */
    bool operator < (const BTask& other) const;
   
};
#endif