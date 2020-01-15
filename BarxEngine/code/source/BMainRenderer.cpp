#include "..//headers/BComponent.hpp"
#include "..//headers/BMainRenderer.hpp"
#include "..//headers/BRenderTask.hpp"
#include "..//headers/BWindowTask.hpp"

BMainRenderer::BMainRenderer(shared_ptr<BEntity> parent) : BComponent(parent)
{
    task = shared_ptr<BRenderTask>(new BRenderTask(BWindowTask::instance));

}

bool BMainRenderer::initialize()
{
    return false;
}
