// File: BInputHandlerTask.hpp
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
#include "BTask.hpp"

/*
* Se ejecutará en segundo plano recogiendo todos los eventos y los guardara en una cola de eventos
* Cuando se de una vuelta de bucle entera, se pasan al inputmapper, traduciendo los inputs para enviarlo mediante mensajes
*/
class BMyInputHandlerTask : public BTask
{

public: 

    BMyInputHandlerTask(bool active);

private:

    // Inherited via BTask
    virtual bool initialize() override;

    virtual bool finalize() override;

    virtual bool execute(float time) override;

};