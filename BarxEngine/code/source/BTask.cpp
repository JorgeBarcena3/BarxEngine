#include "..\headers\BPhysicsTask.hpp"
#include "../headers/BScene.hpp"
#include "../headers/BTask.hpp"
#include "../headers/BWindow.hpp"
#include "../headers/BRender.hpp"
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

bool BTransform_task::run(float time)
{
    auto obj = BRender::instance->getRenderer()->get(id);

    obj->rotate_around_y(0.001f);

    return true;
}


BRender_Task::BRender_Task(string _id, shared_ptr<BRender> _instance, shared_ptr< BTransform_Component > _transformComponent)
{
    instance = _instance;
    id = _id;
    transform = _transformComponent;
}

bool BRender_Task::initialize()
{
    
    return true;
}

bool BRender_Task::finalize()
{
    return true;
}

bool BRender_Task::run(float time)
{

    auto obj = instance->getRenderer()->get(id);

    obj->translate(glt::Vector3(transform->position.x, transform->position.y, transform->position.z) );
 
    return true;
}
