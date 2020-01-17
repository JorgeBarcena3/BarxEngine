#include "..\headers\BColliderComponent.hpp"
#include "..\headers\BShereColliderComponent.hpp"
#include "../headers/BSphereColliderTask.hpp"
#include "../headers/BTransformComponent.hpp"
#include "../headers/BEntity.hpp"
#include "../headers/BBoxColliderComponent.hpp"

BShereColliderComponent::BShereColliderComponent(shared_ptr<BEntity> parent) : BColliderComponent(parent)
{
    transform = parent->getTransform();
    type = COLLIDERTYPE::SPHERE;
    radius = 1;
}

shared_ptr<BEntity> BShereColliderComponent::checkCollisions(shared_ptr<BEntity> other)
{
    shared_ptr< BColliderComponent> collider = other->getComponent<BColliderComponent>();

    if (collider->getType() == COLLIDERTYPE::SPHERE)
    {
        auto BTransform = other->getTransform();

        if (transform != BTransform)
        {
            shared_ptr< BShereColliderComponent> collider = other->getComponent<BShereColliderComponent>();

            float dx = (transform->position.x - BTransform->position.x);
            float dy = (transform->position.y - BTransform->position.y);
            float dz = (transform->position.z - BTransform->position.z);

            float distance = sqrt(dx * dx + dy * dy + dz * dz);

            if (distance <= (radius + collider->radius))
            {
                return other;
            }
        }

    }
    else if (collider->getType() == COLLIDERTYPE::BOX)
    {
        auto BTransform = other->getTransform();

        if (transform != BTransform) {

            shared_ptr< BBoxColliderComponent> collider = other->getComponent<BBoxColliderComponent>();

            vec3<float> Min(
                BTransform->position.x - collider->MinOffset.x,
                BTransform->position.y - collider->MinOffset.y,
                BTransform->position.z - collider->MinOffset.z
            );

            vec3<float> Max(
                BTransform->position.x + collider->MaxOffset.x,
                BTransform->position.y + collider->MaxOffset.y,
                BTransform->position.z + collider->MaxOffset.z
            );

            //Punto mas cercano a la sphera
            float x = max(Min.x, min(transform->position.x, Max.x));
            float y = max(Min.y, min(transform->position.y, Max.y));
            float z = max(Min.z, min(transform->position.z, Max.z));

            float distance = sqrt(
                (x - transform->position.x) * (x - transform->position.x) +
                (y - transform->position.y) * (y - transform->position.y) +
                (z - transform->position.z) * (z - transform->position.z) 
            );

            if(distance < radius)
                return other;
        }

    }

    return shared_ptr<BEntity>(nullptr);
}
