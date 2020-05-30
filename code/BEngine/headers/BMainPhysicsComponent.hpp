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

#ifndef BARX_ENGINE_BMAINPHYSICSCOMPONENT
#define BARX_ENGINE_BMAINPHYSICSCOMPONENT

#include "BtypeDef.hpp"
#include "BComponent.hpp"

/**
* Clases adelantadas
*/
class BComponent;
class BEntity;
class btDiscreteDynamicsWorld;
class btRigidBody;
class btDefaultMotionState;
class btCollisionShape;
class btDefaultCollisionConfiguration;
class btCollisionDispatcher;
class btDbvtBroadphase;
class btSequentialImpulseConstraintSolver;
class btHingeConstraint;

/**
* Clase que se encarga de renderizar un modelo 3D
*/
class BMainPhysicsComponent : public BComponent
{
public:

    //Instancia del componente general del mundo
    static BMainPhysicsComponent* instance;

    // Atributos del mundo de Bullet
    shared_ptr< btDiscreteDynamicsWorld > dynamicsWorld;


    // Keep track of the shapes, states and rigid bodies.
   // Make sure to reuse collision shapes among rigid bodies whenever possible!

    vector< shared_ptr< btRigidBody          > > rigidBodies;
    vector< shared_ptr< btDefaultMotionState > > motionStates;
    vector< shared_ptr< btCollisionShape     > > collisionShapes;
    vector< shared_ptr< btHingeConstraint     > > constraints;


private:

    shared_ptr< btDefaultCollisionConfiguration     > collisionConfiguration;
    shared_ptr< btCollisionDispatcher               > collisionDispatcher;
    shared_ptr< btDbvtBroadphase                    > overlappingPairCache;
    shared_ptr< btSequentialImpulseConstraintSolver > constraintSolver;


public:

    /**
    * Constructor por defecto de la clase
    */
    BMainPhysicsComponent(shared_ptr <BEntity> parent);

    ~BMainPhysicsComponent();

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
#endif;