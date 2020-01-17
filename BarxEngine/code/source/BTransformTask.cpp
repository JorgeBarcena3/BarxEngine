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


BTransformTask::BTransformTask(string _id, shared_ptr<BTransformComponent> _transformComponent) : BTask(TASKPRIORITY::TRANSFORM)
{
    id = _id;
    transform = _transformComponent;
}

bool BTransformTask::initialize()
{
    return true;
}

bool BTransformTask::finalize()
{
    return true;
}

bool BTransformTask::execute(float time)
{
  
    return true;
}