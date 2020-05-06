#include "..\headers\BComponent.hpp"
#include "..\headers\BTask.hpp"
#include "..\headers\BMainPhysicsComponent.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTranformTask.hpp"
#include <btBulletDynamicsCommon.h>
#include "../headers/BMainPhysicsTask.hpp"

shared_ptr<BMainPhysicsComponent> BMainPhysicsComponent::instance = shared_ptr<BMainPhysicsComponent>(nullptr);

BMainPhysicsComponent::BMainPhysicsComponent(shared_ptr<BEntity> parent) : BComponent(parent)
{

    task = shared_ptr<BMainPhysicsTask>(new BMainPhysicsTask(shared_ptr<BMainPhysicsComponent>(this)));

    /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- +\
                                       PHYSISCS WORLD INITIALIZATION
    \+ -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

    // Collision configuration contains default setup for memory, collision setup.
    // Advanced users can create their own configuration.

    collisionConfiguration = shared_ptr<btDefaultCollisionConfiguration>(new btDefaultCollisionConfiguration());

    // Use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded).

    collisionDispatcher = shared_ptr<btCollisionDispatcher>(new btCollisionDispatcher(&(*collisionConfiguration)));

    // btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.

    overlappingPairCache = shared_ptr<btDbvtBroadphase>(new btDbvtBroadphase());

    // The default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded).

    constraintSolver = shared_ptr<btSequentialImpulseConstraintSolver>(new btSequentialImpulseConstraintSolver());

    // Create and configure the physiscs world:

    dynamicsWorld = shared_ptr< btDiscreteDynamicsWorld >
        (
            new btDiscreteDynamicsWorld
            (
                &(*collisionDispatcher),
                &(*overlappingPairCache),
                &(*constraintSolver),
                &(*collisionConfiguration)
            )
            );

    dynamicsWorld->setGravity(btVector3(0, -2, 0));

    BMainPhysicsComponent::instance = shared_ptr<BMainPhysicsComponent>(this);
}

BMainPhysicsComponent::~BMainPhysicsComponent()
{
    dynamicsWorld.reset();
}

bool BMainPhysicsComponent::initialize()
{
    return false;
}

bool BMainPhysicsComponent::parse_property(const string& name, const string& value)
{
    return false;
}