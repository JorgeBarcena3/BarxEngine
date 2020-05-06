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

BPhysicsCompmponent::BPhysicsCompmponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
    type = BPSHYSIC_TYPE::DYNAMIC;
    task = shared_ptr<BPhysicsTask>(new BPhysicsTask(parent->getId(), shared_ptr<BPhysicsCompmponent>(this)));
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
        mass = atof(value.c_str());

    return true;
}

shared_ptr<btRigidBody> BPhysicsCompmponent::getPhysicalBody()
{
    return body;
}

void BPhysicsCompmponent::createBulletRigidBody()
{

    shared_ptr<BTransformComponent> transformComponent = getEntity()->getTransform();

    if (type == BPSHYSIC_TYPE::STATIC)
    {
        // GROUND
        {
            shape = shared_ptr< btCollisionShape >(new btBoxShape(btVector3(25,0.1f,25)));


            btTransform transform;
            transform.setIdentity();
            transform.setOrigin(btVector3(transformComponent->position.x, transformComponent->position.y, transformComponent->position.z));


            // Using motionstate is optional for static objects.

            state = shared_ptr< btDefaultMotionState >(new btDefaultMotionState());
            btRigidBody::btRigidBodyConstructionInfo info_S(0, state.get(), shape.get());
            body = shared_ptr< btRigidBody >(new btRigidBody(info_S));

            body->setRestitution(0.7f);

            // Add the body to the dynamics world.

            BMainPhysicsComponent::instance->dynamicsWorld->addRigidBody(body.get());

            // Save the smart pointers for automatic cleanup.

            BMainPhysicsComponent::instance->rigidBodies.push_back(body);
            BMainPhysicsComponent::instance->motionStates.push_back(state);
            BMainPhysicsComponent::instance->collisionShapes.push_back(shape);
        }
    }
    else
    {
         shape = shared_ptr< btCollisionShape >(new btSphereShape(btScalar(0.1f)));

        // Create Dynamic Objects.

        btTransform transform;
        transform.setIdentity();
        transform.setOrigin(btVector3(transformComponent->position.x, transformComponent->position.y, transformComponent->position.z));

        btScalar _mass = mass;
        btVector3 localInercia(0, 0, 0);
        shape->calculateLocalInertia(_mass, localInercia);

        // Using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects

        state = shared_ptr< btDefaultMotionState >(new btDefaultMotionState(transform));
        btRigidBody::btRigidBodyConstructionInfo info_D(0, state.get(), shape.get());
        body = shared_ptr< btRigidBody >(new btRigidBody(info_D));

        shared_ptr< btDefaultMotionState >       state(new btDefaultMotionState(transform));
        btRigidBody::btRigidBodyConstructionInfo info(_mass, state.get(), shape.get(), localInercia);

        body.reset(new btRigidBody(info));

        body->setRestitution(1.0);

        BMainPhysicsComponent::instance->dynamicsWorld->addRigidBody(body.get());

        // Save the smart pointers for automatic cleanup.

        BMainPhysicsComponent::instance->rigidBodies.push_back(body);
        BMainPhysicsComponent::instance->motionStates.push_back(state);
        BMainPhysicsComponent::instance->collisionShapes.push_back(shape);
    }
}
