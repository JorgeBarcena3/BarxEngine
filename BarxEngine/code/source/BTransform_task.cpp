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
    
   
    return true;
}