// File: BTimer.hpp
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

#ifndef BARX_ENGINE_BTIMER
#define BARX_ENGINE_BTIMER

#include "BtypeDef.hpp"

/**
* Clase que maneja el tiempo
*/
class BTimer
{

    uint32_t startTick; ///< Tick del start
    uint32_t lastTick ; ///< Tick de la ultima vez que se pidio

public:

    /**
    * Constructor
    */
    BTimer();

    /**
    * Comienza el contador
    */
    void start();

    /**
    * Devuelve los segundos transcurridos
    */
    float elapsedSeconds() const;  

    /**
    * Devuelve los milisegundos transcurridos
    */
    uint32_t elapsedMiliseconds() const;

    /**
   * Devuelve los milisegundos transcurridos
   */
    uint32_t lastFrameElapsedMiliseconds() const;

    /**
    * Devuelve el timDeltaTime
    */
    float timeDeltatime();

};
#endif