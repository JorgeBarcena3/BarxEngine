#include "..\headers\BPhysicsTask.hpp"
#include "../headers/BScene.hpp"
#include "../headers/BTask.hpp"
#include "../headers/BWindow.hpp"
#include "../headers/BRender.hpp"
#include <Render_Node.hpp>
#include <SDL.h>
#include "../headers/BComponent.hpp"

BPhysics_task::BPhysics_task()
{
}

bool BPhysics_task::initialize()
{
    return true;
}

bool BPhysics_task::finalize()
{
    return true;
}

bool BPhysics_task::run(float time)
{
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

    auto cube = instance->getRenderer()->get(id);
    
    cube->translate(glt::Vector3(transform->position.x, transform->position.y, transform->position.z) );
      
    return true;
}
