#include "../headers/BScene.hpp"
#include "../headers/BTask.hpp"
#include "../headers/BControlTask.hpp"
#include "../headers/BWindowTask.hpp"
#include "../headers/BRenderTask.hpp"
#include "../headers/BRenderObject_task.hpp"
#include "../headers/BComponent.hpp"
#include "../headers/BTransformComponent.hpp"
#include <Render_Node.hpp>
#include <SDL.h>


BControlTask::BControlTask(shared_ptr<BEntity> _entityReference)
{
    entityReference = _entityReference;
    //myFunction = funcion;

}

bool BControlTask::initialize()
{
    return true;
}

bool BControlTask::finalize()
{
    return true;
}

bool BControlTask::execute(float time)
{
    myFunction(time, entityReference);
    return true;
}
