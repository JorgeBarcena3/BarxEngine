#include "..\headers\BTask.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BMainCollisionTask.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BMainCollisionComponent.hpp"
#include "..\headers\BRenderTask.hpp"
#include "../headers/BMainPhysicsComponent.hpp"
#include "../headers/BColliderComponent.hpp"
#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

bool BMainCollisionTask::initialize()
{
    current_time = 0;
    return true;
}

bool BMainCollisionTask::finalize()
{
    return true;
}

bool BMainCollisionTask::execute(float time)
{

    current_time += time;

    if (current_time > mainCollisionComponent->collisionFrecuency)
    {

        current_time = 0;;

        int numManifolds = BMainPhysicsComponent::instance->dynamicsWorld->getDispatcher()->getNumManifolds();
        for (int i = 0; i < numManifolds; i++)
        {
            btPersistentManifold* contactManifold = BMainPhysicsComponent::instance->dynamicsWorld->getDispatcher()->getManifoldByIndexInternal(i);
            const btCollisionObject* obA = static_cast<const btCollisionObject*>(contactManifold->getBody0());
            const btCollisionObject* obB = static_cast<const btCollisionObject*>(contactManifold->getBody1());

            int numContacts = contactManifold->getNumContacts();
            for (int j = 0; j < numContacts; j++)
            {
                btManifoldPoint& pt = contactManifold->getContactPoint(j);
                if (pt.getDistance() < 0.f)
                {

                    BEntity* A = static_cast<BEntity*>((obA->getUserPointer()));
                    BEntity* B = static_cast<BEntity*>((obB->getUserPointer()));
                    auto collider_A = A->getComponent<BColliderComponent>();
                    auto collider_B = B->getComponent<BColliderComponent>();

                    if (collider_A->collisionFunction)
                        collider_A->collisionFunction(A, B);
                    if (collider_B->collisionFunction)
                        collider_B->collisionFunction(B, A);

                    // Solo entra una vez por frame
                    j = numContacts;

                }
            }
        }

    }

    return true;
}

BMainCollisionTask::BMainCollisionTask(string _id, shared_ptr<BMainCollisionComponent> _mainCollisionComponent) : BTask(TASKPRIORITY::COLLISIONS)
{
    id = _id;

    mainCollisionComponent = _mainCollisionComponent;
}

BMainCollisionTask::~BMainCollisionTask()
{
}

