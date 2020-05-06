#include "..\headers\BTask.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BPhysicsComponent.hpp"
#include "..\headers\BMainPhysicsComponent.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTranformTask.hpp"
#include "../headers/BPhysicsTask.hpp"
#include <btBulletDynamicsCommon.h>
#include <LinearMath\btVector3.h>
#include "../headers/BColliderComponent.hpp"
#include "../headers/BBoxColliderComponent.hpp"
#include "../headers/BShereColliderComponent.hpp"

BPhysicsCompmponent::BPhysicsCompmponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
    type = BPSHYSIC_TYPE::DYNAMIC;
    task = shared_ptr<BPhysicsTask>(new BPhysicsTask(parent->getId(), shared_ptr<BPhysicsCompmponent>(this)));
    friction = 0;
    restitution = 0;
}

bool BPhysicsCompmponent::initialize()
{
    createBulletRigidBody();
    return true;
}

bool BPhysicsCompmponent::parse_property(const string& name, const string& value)
{

    if (name == "type")
    {
        if (value == "STATIC")
        {
            type = BPSHYSIC_TYPE::STATIC;
        }
        else
        {
            type = BPSHYSIC_TYPE::DYNAMIC;
        }
    }
    else if (name == "mass")
    {
        mass = atof(value.c_str());
    } 
    else if (name == "damping")
    {
        damping = atof(value.c_str());
    } 
    else if (name == "friction")
    {
        friction = atof(value.c_str());
    }
    else if (name == "restitution")
    {
        restitution = atof(value.c_str());
    }
     

    return true;
}

shared_ptr<btRigidBody> BPhysicsCompmponent::getPhysicalBody()
{
    return body;
}

void BPhysicsCompmponent::createBulletRigidBody()
{

    shared_ptr<BTransformComponent> transformComponent = getEntity()->getTransform();
    shared_ptr<BColliderComponent> colliderComponent = getEntity()->getComponent<BColliderComponent>();

    if (colliderComponent->getType() == COLLIDERTYPE::BOX)
    {
        shared_ptr< BBoxColliderComponent > boxCollider = dynamic_pointer_cast<BBoxColliderComponent>(colliderComponent);

        shape = shared_ptr< btCollisionShape >(new btBoxShape(btVector3(boxCollider->btBoxShape.x, boxCollider->btBoxShape.y, boxCollider->btBoxShape.z)));


        btVector3 center;
        btScalar radius;
        shape->getBoundingSphere(center, radius);

    }
    else if(colliderComponent->getType() == COLLIDERTYPE::SPHERE)
    { 

        shared_ptr< BSphereColliderComponent > sphereCollider = dynamic_pointer_cast<BSphereColliderComponent>(colliderComponent);

        shape = shared_ptr< btCollisionShape >(new btSphereShape(btScalar(sphereCollider->radius)));


    }

    btTransform transform;
    transform.setIdentity();
    transform.setOrigin(btVector3(transformComponent->position.x, transformComponent->position.y, transformComponent->position.z));
    btQuaternion qt;
    qt.setEuler(transformComponent->rotation.x, transformComponent->rotation.y, transformComponent->rotation.z);
    transform.setRotation(qt);
    state = shared_ptr< btDefaultMotionState >(new btDefaultMotionState(transform));


    if (type == BPSHYSIC_TYPE::STATIC)
    {
        // GROUND
        {
            // Using motionstate is optional for static objects.

            btRigidBody::btRigidBodyConstructionInfo info_S(0, state.get(), shape.get());
            body = shared_ptr< btRigidBody >(new btRigidBody(info_S));

        }
    }
    else
    {
              
        btScalar _mass = mass;
        btVector3 localInercia(0, 0, 0);
        shape->calculateLocalInertia(_mass, localInercia);

        btRigidBody::btRigidBodyConstructionInfo info_D(_mass, state.get(), shape.get());

        body.reset(new btRigidBody(info_D));

    }

    body->setRestitution(restitution);
    body->setFriction(friction);

    // Add the body to the dynamics world.

    BMainPhysicsComponent::instance->dynamicsWorld->addRigidBody(body.get());

    // Save the smart pointers for automatic cleanup.

    BMainPhysicsComponent::instance->rigidBodies.push_back(body);
    BMainPhysicsComponent::instance->motionStates.push_back(state);
    BMainPhysicsComponent::instance->collisionShapes.push_back(shape);


}
