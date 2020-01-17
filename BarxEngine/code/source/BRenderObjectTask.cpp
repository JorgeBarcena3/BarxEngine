#include "../headers/BScene.hpp"
#include "../headers/BTask.hpp"
#include "../headers/BTranformTask.hpp"
#include "../headers/BWindowTask.hpp"
#include "../headers/BRenderTask.hpp"
#include "../headers/BRenderObjectTask.hpp"
#include "../headers/BComponent.hpp"
#include "../headers/BTransformComponent.hpp"
#include <Render_Node.hpp>
#include <SDL.h>


BRenderObjectTask::BRenderObjectTask(string _id, const shared_ptr<BRenderTask> _instance, const shared_ptr< BTransformComponent > _transformComponent) : BTask(TASKPRIORITY::RENDEROBJECT)
{
    instance = _instance;
    id = _id;
    transform = _transformComponent;
}

bool BRenderObjectTask::initialize()
{

    auto obj = instance->getRenderer()->get(id);

    Matrix44 transformation = obj->get_transformation();

    obj->translate(glt::Vector3(
        transform->position.x - transformation[3].x,
        transform->position.y - transformation[3].y,
        transform->position.z - transformation[3].z));

    obj->rotate_around_x(transform->rotation.x);
    obj->rotate_around_y(transform->rotation.y);
    obj->rotate_around_z(transform->rotation.z);

    transform->rotation.x = 0;
    transform->rotation.x = 0;
    transform->rotation.z = 0;

    obj->scale(
        transform->scale.x,
        transform->scale.y,
        transform->scale.z);

    transform->scale.x = 1;
    transform->scale.x = 1;
    transform->scale.x = 1;

    return true;
}

bool BRenderObjectTask::finalize()
{
    return true;
}

bool BRenderObjectTask::execute(float time)
{

    auto obj = instance->getRenderer()->get(id);

    Matrix44 transformation = obj->get_transformation();

    glt::Vector3 difference = glt::Vector3(
        transform->position.x - transformation[3].x,
        transform->position.y - transformation[3].y,
        transform->position.z - transformation[3].z);

    if (glm::length(difference) > 0)
        obj->translate(difference);

   /* difference = glt::Vector3(
        entity->scale.x - transformation[0].x,
        entity->scale.y - transformation[1].y,
        entity->scale.z - transformation[2].z);

    if (glm::length(difference) > 0)
        obj->scale(difference.x, difference.y, difference.z);*/

    if (transform->rotation.x > 0)
    {
        obj->rotate_around_x(transform->rotation.x);
        transform->rotation.x = 0;
    }

    if (transform->rotation.y > 0)
    {
        obj->rotate_around_y(transform->rotation.y);
        transform->rotation.y = 0;
    }

    if (transform->rotation.z > 0)
    {
        obj->rotate_around_z(transform->rotation.z);
        transform->rotation.z = 0;
    }

    return true;
}