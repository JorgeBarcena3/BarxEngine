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

    return true;
}

bool BRenderObjectTask::finalize()
{
    return true;
}

bool BRenderObjectTask::execute(float time)
{
    //EN EL FUTURO SE AÑADIRAN MATERIALES Y DEMAS

    return true;
}