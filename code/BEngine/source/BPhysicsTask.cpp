#include "..\headers\BTask.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BPhysicsTask.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BPhysicsComponent.hpp"
#include "..\headers\BRenderTask.hpp"

#include <Cube.hpp>
#include <Model.hpp>
#include <Light.hpp>
#include <Render_Node.hpp>

#include <btBulletDynamicsCommon.h>
#include <LinearMath\btVector3.h>
#include "../headers/BMainPhysicsComponent.hpp"

bool BPhysicsTask::initialize()
{

    return true;
}

bool BPhysicsTask::finalize()
{
    BMainPhysicsComponent::instance->dynamicsWorld->removeRigidBody(physicsComponent->getPhysicalBody().get());
    return false;
}

bool BPhysicsTask::execute(float time)
{

    if (physicsComponent->isActive())
    {
        // Apply the physics transform to the graphics model:
        auto transform = physicsComponent->getEntity()->getTransform();

        btTransform physics_transform;

        physicsComponent->getPhysicalBody()->getMotionState()->getWorldTransform(physics_transform);

        glt::Matrix44 matrix;

        physics_transform.getOpenGLMatrix(glm::value_ptr(matrix));

        (transform->transformationMatrix) = matrix;

        auto pos = extract_translation(matrix);

        transform->position = {pos.x, pos.y, pos.z};
    }

    return true;
}

BPhysicsTask::BPhysicsTask(string _id, shared_ptr< BPhysicsCompmponent > _physics_component) : BTask(TASKPRIORITY::PHYSICSOBJECT)
{
    physicsComponent = _physics_component;
    id = _id;
}
