// File: BPhysicsConstraintComponent.hpp
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

#ifndef BARX_ENGINE_BPHYSICSCONSTRAINTCOMPONENT
#define BARX_ENGINE_BPHYSICSCONSTRAINTCOMPONENT

#include "BtypeDef.hpp"
#include "BComponent.hpp"

/**
* Clases adelantadas
*/
class btHingeConstraint;
class btVector3;
class BPhysicsCompmponent;
class BEntity;


/**
* Clase que se encarga de renderizar un modelo 3D
*/
class BPhysicsConstraintComponent : public BComponent
{

private:

    shared_ptr<BPhysicsCompmponent> A;

    shared_ptr<BPhysicsCompmponent> B;

    vec3<float> axisA;
    vec3<float> axisB;

    vec3<float> pivotA;
    vec3<float> pivotB;

    bool initialiced;

    shared_ptr<btHingeConstraint> physicsHingeConstraint;


public:

    /**
    * Constructor por defecto de la clase
    */
    BPhysicsConstraintComponent(shared_ptr <BEntity> parent);

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
    * Activa la restriccion del movimiento
    */
    void eneableMotor(bool eneable = true);

    /**
    * Activa el motor angular del joint
    */
    void eneableAngularMotor(bool eneable = true);
    
    /**
    * Determina la velocidad del motor
    */
    void setVelocity(float speed);

};
#endif;