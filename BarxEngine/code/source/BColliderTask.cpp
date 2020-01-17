#include "..\headers\BColliderTask.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BScene.hpp"
#include "../headers/BColliderComponent.hpp"

BColliderTask::BColliderTask(shared_ptr<BEntity> _transfom, shared_ptr<BScene> _scene) : BTask(TASKPRIORITY::COLLISIONS)
{
    entity = _transfom;
    scene = _scene;
}

bool BColliderTask::initialize()
{
    transform = entity->getTransform();
    colliderEntites = scene->entitesWithComponent<BColliderComponent>();
    return true;
}

bool BColliderTask::finalize()
{
    return true;
}

bool BColliderTask::execute(float time)
{

    for (auto AEntity : colliderEntites)
    {
        auto BTransform = AEntity->getTransform();

        if (transform != BTransform && onCollision)
        {

            auto BColliderA = AEntity->getComponent<BColliderComponent>();
            auto BColliderB = entity->getComponent<BColliderComponent>();

            float dx = (transform->position.x - BTransform->position.x);
            float dy = (transform->position.y - BTransform->position.y);
            float dz = (transform->position.z - BTransform->position.z);

            float distance = sqrt(dx * dx + dy * dy + dz * dz);

            if (distance <= (BColliderA->radius + BColliderB->radius))
            {
                onCollision(entity, AEntity);
            }
        }


    }
    return true;
}
