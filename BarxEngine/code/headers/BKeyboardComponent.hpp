// File: BKeyboardComponent.hpp
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

#ifndef BARX_ENGINE_BKEYBOARDCOMPONENT
#define BARX_ENGINE_BKEYBOARDCOMPONENT

#include "BtypeDef.hpp"
#include "BObserver.hpp"

/*
* Clases adelantadas
*/
class BComponent;
class BOrbserver;
class BEntity;
class BKeyboard;

/*
* Componente que maneja el input por teclado
* Observer que se subscribe a los eventeos del input
*/
class BKeyboardComponent : public BComponent, public BOrbserver
{


public:

    shared_ptr< BKeyboard > Keyboard; ///< Objeto que guarda la informacion de las teclas presionadas

    /*
    * Constructor del componente del teclado
    */
    BKeyboardComponent(shared_ptr <BEntity> parent);

    /*
    * Heredado del componente
    * Se ejecuta al inicializar el compomente
    */
    bool initialize();

    /*
    * Heredado del componente
    * Parsea las propiedades del xml
    */
    bool parse_property(const string& name, const string& value);

    /*
    * Heredado de BObserver
    * Se ejecuta cuando recive un mensaje a traves del observer
    */    
    void handle(const BMessage& m);

};
#endif