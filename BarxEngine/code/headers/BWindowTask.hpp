// File: BWindowTask.hpp
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

#ifndef BARX_ENGINE_BWINDOWTASK
#define BARX_ENGINE_BWINDOWTASK

#include "BtypeDef.hpp"
#include "BTask.hpp"

/*
* Clase que maneja la ventana
*/
class BWindowTask : public BTask
{

public:

    static shared_ptr< BWindowTask > instance; ///< Instancia de la ventana

private:

    SDL_Window   * window     ; ///< SDL windows
    SDL_GLContext  gl_context ; ///< Contexto de SDL

    int            width      ; ///< Anchura de la pantalla
    int            heigth     ; ///< Altura de la pantalla

public:


    /*
    * Constructor por defecto
    */                                   
    BWindowTask(const std::string& title, ///< Nombre de la ventana
                int _width,               ///< Ancho de la ventana
                int _height,              ///< ALtura de la ventana
                bool fullscreen = false   ///< Si se ejecutará en fullscreen
    );

    /*
    * Destructor
    */    
    ~BWindowTask();   

    /*
    * Cambia a fullscreen
    */
    void setFullScreen(uint32_t type = 0);

    /*
    * Cambia a  modo ventana
    */
    void setWindowed();

    /*
    * Devuelve el ancho de la pantalla
    */
    unsigned getWidth() const;

    /*
    * Devuelve la altura
    */
    unsigned getHeight() const;

    /*
    * Cambia el titulo de la ventana
    */
    void setWindowTitle(const char* title);

    /*
    * Posiciona la posicion
    */
    void setPosition(int new_left_x, int new_top_y);

    /*
    * Cambia el tamaño de la pantalla
    */
    void setSize(int new_width, int new_height);   

    /*
    * Intercambia los buffer de la pantalla
    */
    void swapBuffers() const;

    /*
    * Limpia la pantalla
    */
    void clear() const;

    /*
    * Inicializa la tarea
    */
    virtual bool initialize() override;

    /*
    * Finaliza la tarea
    */
    virtual bool finalize() override;

    /*
    * Ejecuta la tarea 
    */
    virtual bool execute(float time) override;

};
#endif
