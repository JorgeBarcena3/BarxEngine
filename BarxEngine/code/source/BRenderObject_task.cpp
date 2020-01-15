#include "../headers/BScene.hpp"
#include "../headers/BTask.hpp"
#include "../headers/BTranformTask.hpp"
#include "../headers/BWindowTask.hpp"
#include "../headers/BRenderTask.hpp"
#include "../headers/BRenderObject_task.hpp"
#include "../headers/BComponent.hpp"
#include "../headers/BTransformComponent.hpp"
#include <Render_Node.hpp>
#include <SDL.h>


BRenderObject_Task::BRenderObject_Task(string _id, const shared_ptr<BRenderTask> _instance, const shared_ptr< BTransform_Component > _transformComponent)
{
    instance = _instance;
    id = _id;
    transform = _transformComponent;
}

bool BRenderObject_Task::initialize()
{

    return true;
}

bool BRenderObject_Task::finalize()
{
    return true;
}

bool BRenderObject_Task::execute(float time)
{

    auto obj = instance->getRenderer()->get(id);

    obj->translate(glt::Vector3(transform->position.x, transform->position.y, transform->position.z));

    obj->scale(transform->scale.x, transform->scale.y, transform->scale.z);

    obj->rotate_around_x(transform->rotation.x);
    obj->rotate_around_y(transform->rotation.y);
    obj->rotate_around_z(transform->rotation.z);

    return true;
}