// File: BColliderComponent.hpp
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

#ifndef BARX_ENGINE_BCOLLIDERCOMPONENT
#define BARX_ENGINE_BCOLLIDERCOMPONENT

#include "BtypeDef.hpp"
#include "BComponent.hpp"

/**
* Adelantamiento de clases
*/
class BEntity;
class btCollisionShape;

/**
* Tipo de colider
*/
enum class COLLIDERTYPE {
    SPHERE = 0,
    BOX = 1,
    CAPSULE = 2
};

enum class COLLISION_MASK : int
{
    MASK_1 = 1,
    MASK_2 = 2,
    MASK_3 = 3,
    MASK_4 = 4,
    MASK_5 = 5
};

enum class COLLISION_GROUP : int
{
    GROUP_1 = 1,
    GROUP_2 = 2,
    GROUP_3 = 3,
    GROUP_4 = 4,
    GROUP_5 = 5
};

/**
* Clase base de componente de colisi�n
*/
class BColliderComponent : public BComponent
{

protected:

    /**
    * Tipo de colisi�n
    */
    COLLIDERTYPE type;

    /**
   * Shape de bullet
   */
    shared_ptr< btCollisionShape >     shape;



public:

    bool isTrigger;
    
    COLLISION_MASK collisionMask;

    COLLISION_GROUP collisionGroup;

    /**
    * Funcion de colision
    */
    std::function<void(BEntity*, BEntity* )> collisionFunction;



public:

    /**
    * Unico constructor
    */
    BColliderComponent(shared_ptr <BEntity> parent);

    /**
    * Determina la funcion que se va a ejecutar cuando se produzca la colisi�n
    */
    void setFunction(std::function<void(BEntity*, BEntity*)> myFunction);

    /**
    * Heredado del componente
    * Se ejecuta al inicializar el compomente
    */
    virtual bool initialize() = 0;

    /**
    * Heredado del componente
    * Parsea las propiedades del xml
    */
    virtual bool parse_property(const string& name, const string& value) = 0;

    /**
    * Funci�n virtual pura
    * Se ejecuta para comprobar la colisi�n
    */
    virtual shared_ptr<BEntity> checkCollisions(shared_ptr<BEntity> other) = 0;

    /**
    * Devuelve el tipo de collider que es
    */
    COLLIDERTYPE getType();

    /*
    * Devuelve la shape de las colisiones
    */
    shared_ptr< btCollisionShape > getShape();


    /*
    * Configura la shape
    */
    void configShape();

    /*
    * Cambia el estado de la shape a trigger o no
    */
    void setTrigger(float t);


};
#endif