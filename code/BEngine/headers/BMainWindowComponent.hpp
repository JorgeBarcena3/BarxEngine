// File: BMainWindowComponent.hpp
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

#ifndef BARX_ENGINE_BBMAINWINDOWCOMPONENT
#define BARX_ENGINE_BBMAINWINDOWCOMPONENT

#include "BtypeDef.hpp"

/**
* Clases adelantadas
*/
class BComponent;
class BWindowTask;
class BEntity;

/**
* Componente que se encarga de crear la ventana 
*/
class BMainWindowComponent : public BComponent
{  


public:

    /**
    * Constructor por defecto de la clase BMainWindowComponente
    */
    BMainWindowComponent(shared_ptr <BEntity> parent           , ///< Padre de la entidad
                         string windowName = "BarxEngine tool" , ///< Nombre de la ventana
                         int w = 1200                          , ///< Ancho de la ventana
                         int h = 800                           , ///< ALtura de la ventana
                         bool fs = false                         ///< Si se ejecutará en fullscreen o no
    );

    /**
    * Heredado del componente
    * Se ejecuta al inicializar el compomente
    */
    bool initialize();

    /**
    * Heredado del componente
    * Parsea las propiedades del xml
    */
    bool parse_property(const string& name, const string& value);

};
#endif