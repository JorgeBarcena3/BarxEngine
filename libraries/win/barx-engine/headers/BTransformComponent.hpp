// File: BTransformComponent.hpp
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

#ifndef BARX_ENGINE_BTRANSFORMCOMPONENT
#define BARX_ENGINE_BTRANSFORMCOMPONENT

#include "BtypeDef.hpp"
#include "BComponent.hpp"
#include "Math.hpp"


/**
* Clase que se encarga de manejar la posicion de los objetos en la escena
*/
class BTransformComponent : public BComponent
{

public:

    vec3<float> position; ///< Posicion de la entidad
    vec3<float> rotation; ///< Rotacion de la entidad
    vec3<float> scale; ///< Escala de la entidad

    glt::Matrix44 transformationMatrix;

    /**
    * Constructor por defecto de la clase
    */
    BTransformComponent(shared_ptr <BEntity> parent);

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


    /**
    * Obtiene la matriz de transformacion
    */
    shared_ptr<glt::Matrix44> getOpenGLMatrix();

};
#endif