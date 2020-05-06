#include "..\headers\BTask.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BPhysicsTask.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BPhysicsComponent.hpp"

#include <btBulletDynamicsCommon.h>
#include <LinearMath\btVector3.h>

bool BPhysicsTask::initialize()
{
    auto transform = physicsComponent->getEntity()->getTransform();

    btTransform currentTransform;

    currentTransform.setOrigin(btVector3(transform->position.x, transform->position.y, transform->position.z));

    physicsComponent->getPhysicalBody()->getMotionState()->setWorldTransform(currentTransform);  

    return true;
}

bool BPhysicsTask::finalize()
{
    return false;
}

bool BPhysicsTask::execute(float time)
{
    // Apply the physics transform to the graphics model:

    btTransform physics_transform;

    physicsComponent->getPhysicalBody()->getMotionState()->getWorldTransform(physics_transform);

    glt::Matrix44 matrix;

    physics_transform.getOpenGLMatrix(glm::value_ptr(matrix));

    auto position = extract_translation(matrix);

    auto transform = physicsComponent->getEntity()->getTransform();

    transform->position = vec3<float>(position.x, position.y, position.z);

    return true;
}

BPhysicsTask::BPhysicsTask(string _id, shared_ptr< BPhysicsCompmponent > _physics_component)
{
    physicsComponent = _physics_component;
    id = _id;
}
