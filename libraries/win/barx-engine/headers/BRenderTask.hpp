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

#ifndef BARX_ENGINE_BRENDERTASK
#define BARX_ENGINE_BRENDERTASK

#include "BtypeDef.hpp"
#include "BTask.hpp"

/**
* Clases adelantadas
*/
class BWindowTask;

/**
* Tarea de render
*/
class BRenderTask : public BTask
{  

    shared_ptr< glt::Render_Node > renderer; ///< Puntero al Render_Node necesario para renderizar la  escena

    shared_ptr< BWindowTask >      window  ; ///< Puntero a la ventana que se esta ejecutando

public:

    static shared_ptr< BRenderTask > instance; ///< Instancia estatica del render

    /**
    * Constructor por defecto
    */
                                     BRenderTask(shared_ptr< BWindowTask > given_window);
                                  
    /**
    * Destructor por defecto
    */
                                     ~BRenderTask (                                    );
    
    /**
    * Renderiza la escena
    */                                 
    void                             render       (                                    );
              
    /**
    * Devuelve la instancia de Render_node actual
    */
    shared_ptr< glt::Render_Node >   getRenderer  (                                    );
          
    /**
    * Devuelve la ventana donde se ejecuta el render
    */
    shared_ptr< BWindowTask      >   getWindow    (                                    );

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