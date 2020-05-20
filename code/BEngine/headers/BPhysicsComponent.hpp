// File: BRenderObjectComponent.hpp
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

#ifndef BARX_ENGINE_BPHYSICSCOMPONENT
#define BARX_ENGINE_BPHYSICSCOMPONENT

#include "BtypeDef.hpp"
#include "BComponent.hpp"

/**
* Clases adelantadas
*/
//class BComponent;
class btCollisionShape;
class btDefaultMotionState;
class btRigidBody;

/**
* Posibles tipo de fisicas
*/
enum BPSHYSIC_TYPE
{
    STATIC = 0,
    DYNAMIC = 1
};

/**
* Clase que se encarga de renderizar un modelo 3D
*/
class BPhysicsCompmponent : public BComponent
{

private:

    /**
    * Tipo de fisica del objeto
    */
    BPSHYSIC_TYPE type;

    float  mass;
    float  damping;
    float  friction;
    float  restitution;

    bool active;

    shared_ptr< btDefaultMotionState > state;

    shared_ptr< btRigidBody >          body;


public:

    /**
    * Constructor por defecto de la clase
    */
    BPhysicsCompmponent(shared_ptr <BEntity> parent);

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
    * Devuelve el componente fisico del cuerpo
    */
    shared_ptr< btRigidBody > getPhysicalBody();

    /**
    * Añade x fuerza al cuerpo
    */
    void addForce(vec3<float> force, vec3<float> point = vec3<float>{ 0, 0, 0 });

    /**
    * Añade x fuerza al cuerpo
    */
    void setGravity(vec3<float> g);

    /**
    * Añade x fuerza al cuerpo
    */
    void setLinearVelocity(vec3<float> v);
    
    /**
    * Devuelve la velocidad actual del cuerpo
    */
    vec3<float> getLinearVelocity();

    /**
    * Añade x impulso
    */
    void applyImpulse(vec3<float> impulse, vec3<float> point);

    /**
    * Devuelve la inversa de la masa del rigidbody
    */
    float getMass();

    /**
    * Activa o desactiva las fisicas de un objeto
    */
    void setActive(bool a);

    /**
    * Si el objeto está o no activado
    */
    inline const bool isActive() { return active; };

    /**
    * Determina si el objeto está en un suelo o no
    */
    bool isInFloor();


private:

    /**
    * Crea el rigidBody
    */
    void createBulletRigidBody();

    /**
    * Activa el objeto si se ha dormido en el mundo de Bullet
    */
    void setActiveStatus();

};
#endif;