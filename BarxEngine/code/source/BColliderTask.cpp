#include "..\headers\BSphereColliderTask.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BScene.hpp"
#include "../headers/BEntity.hpp"
#include "../headers/BColliderComponent.hpp"

BColliderTask::BColliderTask(shared_ptr<BEntity> _entity, shared_ptr<BScene> _scene) : BTask(TASKPRIORITY::COLLISIONS)
{
    entity = _entity;
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
        if (onCollision) {

            auto collision = entity->getComponent<BColliderComponent>()->checkCollisions(AEntity);

            if (collision != nullptr)
            {
                onCollision(entity, AEntity);
            }
        }
    }
    return true;
}
