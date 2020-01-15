#include "../headers/BScene.hpp"
#include "../headers/BTask.hpp"
#include "../headers/BTranformTask.hpp"
#include "../headers/BWindowTask.hpp"
#include "../headers/BRenderTask.hpp"
#include "../headers/BRenderObject_task.hpp"
#include <Render_Node.hpp>
#include <SDL.h>
#include "../headers/BComponent.hpp"


BTransform_task::BTransform_task(string _id, shared_ptr<BTransform_Component> _transformComponent)
{
    id = _id;
    transform = _transformComponent;
}

bool BTransform_task::initialize()
{
    return true;
}

bool BTransform_task::finalize()
{
    return true;
}

bool BTransform_task::execute(float time)
{
    auto obj = BRenderTask::instance->getRenderer()->get(id);

    obj->rotate_around_y(0.001f);

    return true;
}


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

    obj->translate(glt::Vector3(transform->position.x, transform->position.y, transform->position.z) );
 
    return true;
}
