#include "..\headers\BTask.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BPhysicsComponent.hpp"
#include "..\headers\BMainPhysicsComponent.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTranformTask.hpp"
#include "../headers/BPhysicsTask.hpp"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <LinearMath\btVector3.h>
#include "../headers/BColliderComponent.hpp"
#include "../headers/BBoxColliderComponent.hpp"
#include "../headers/BShereColliderComponent.hpp"
#include "../headers/BCapsulleColliderComponent.hpp"


BPhysicsCompmponent::BPhysicsCompmponent(shared_ptr<BEntity> parent) : BComponent(parent, COMPONENT_INITIALIZATION::PHYSICS_COMPONENT)
{
    type = BPSHYSIC_TYPE::DYNAMIC;
    task = shared_ptr<BPhysicsTask>(new BPhysicsTask(parent->getId(), shared_ptr<BPhysicsCompmponent>(this)));
    friction = 0;
    restitution = 0;
    active = true;
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

void BPhysicsCompmponent::addForce(vec3<float> force, vec3<float> point)
{
    setActiveStatus();
    body->applyForce(btVector3(force.x, force.y, force.z), btVector3(point.x, point.y, point.z));
}

void BPhysicsCompmponent::applyImpulse(vec3<float> force, vec3<float> point)
{
    setActiveStatus();
    body->applyImpulse(btVector3(force.x, force.y, force.z), btVector3(point.x, point.y, point.z));
}

float BPhysicsCompmponent::getMass()
{
    return body->getInvMass();
}

void BPhysicsCompmponent::setActive(bool a)
{
    active = a;
}

void BPhysicsCompmponent::setGravity(vec3<float> g)
{
    setActiveStatus();
    body->setGravity(btVector3(g.x, g.y, g.z));
}

void BPhysicsCompmponent::setLinearVelocity(vec3<float> v)
{
    setActiveStatus();
    body->setLinearVelocity(btVector3(v.x, v.y, v.z));
}

vec3<float> BPhysicsCompmponent::getLinearVelocity()
{
    btVector3 velocity = body->getLinearVelocity();

    return vec3<float>(velocity.getX(), velocity.getY(), velocity.getZ());
}

bool BPhysicsCompmponent::isInFloor()
{
    shared_ptr<BTransformComponent> transformComponent = getEntity()->getTransform();

    int numManifolds = BMainPhysicsComponent::instance->dynamicsWorld->getDispatcher()->getNumManifolds();
    for (int i = 0; i < numManifolds; i++)
    {
        btPersistentManifold* contactManifold = BMainPhysicsComponent::instance->dynamicsWorld->getDispatcher()->getManifoldByIndexInternal(i);
        const btCollisionObject* obA = static_cast<const btCollisionObject*>(contactManifold->getBody0());
        const btCollisionObject* obB = static_cast<const btCollisionObject*>(contactManifold->getBody1());
        BEntity* A = static_cast<BEntity*>((obA->getUserPointer()));
        BEntity* B = static_cast<BEntity*>((obB->getUserPointer()));

        if (
            (A->getId() == parent->getId() && B->getId().find("Floor") != string::npos) ||
            (B->getId() == parent->getId() && A->getId().find("Floor") != string::npos)
            )

            return true;
     
    }
    return false;
}

void BPhysicsCompmponent::createBulletRigidBody()
{

    shared_ptr<BTransformComponent> transformComponent = getEntity()->getTransform();
    shared_ptr<BColliderComponent> colliderComponent = getEntity()->getComponent<BColliderComponent>();
    auto shape = colliderComponent->getShape();

    btTransform transform;

    transform.setIdentity();
    transform.setOrigin(btVector3(transformComponent->position.x, transformComponent->position.y, transformComponent->position.z));

    btQuaternion qt;
    qt.setEuler(transformComponent->rotation.x, transformComponent->rotation.y, transformComponent->rotation.z);
    transform.setRotation(qt);

    state = shared_ptr< btDefaultMotionState >(new btDefaultMotionState(transform));

    btRigidBody::btRigidBodyConstructionInfo info_S(type == BPSHYSIC_TYPE::STATIC ? 0 : mass, state.get(), shape.get());
    body = shared_ptr< btRigidBody >(new btRigidBody(info_S));

    body->setRestitution(restitution);
    body->setFriction(friction);
    body->setUserPointer(parent.get());

    colliderComponent->configShape();

    setActiveStatus();

    // Add the body to the dynamics world.

    BMainPhysicsComponent::instance->dynamicsWorld->addRigidBody(body.get(), (int)colliderComponent->collisionGroup, (int)colliderComponent->collisionMask);

    // Save the smart pointers for automatic cleanup.

    BMainPhysicsComponent::instance->rigidBodies.push_back(body);
    BMainPhysicsComponent::instance->motionStates.push_back(state);
    BMainPhysicsComponent::instance->collisionShapes.push_back(shape);


}

void BPhysicsCompmponent::setActiveStatus()
{
    body->setActivationState(DISABLE_DEACTIVATION);
}
