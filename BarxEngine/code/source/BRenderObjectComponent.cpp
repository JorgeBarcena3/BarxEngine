#include "../headers/BComponent.hpp"
#include "../headers/BRenderObjectComponent.hpp"
#include "../headers/BTransformComponent.hpp"
#include "../headers/BRenderTask.hpp"
#include "../headers/BRenderObjectTask.hpp"
#include "../headers/BEntity.hpp"
#include <Model.hpp>
#include <Cube.hpp>
#include <Node.hpp>
#include <Drawable.hpp>
#include <Render_Node.hpp>
#include <Model_Obj.hpp>
#include <Render_Node.hpp>

BRenderObjectComponent::BRenderObjectComponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
    renderTask = BRenderTask::instance;
    id = parent->getId();
    task = shared_ptr<BRenderObjectTask>(new BRenderObjectTask(id, renderTask, parent->getComponent<BTransformComponent>()));
    color = vec3<float>(.4f, .5f, .5f);
}

bool BRenderObjectComponent::initialize()
{
    if (path == "")
    {

        model = shared_ptr<Model>(new Model);
        model->add(shared_ptr< Drawable >(new Cube), Material::default_material());

    }
    else
    {
        model = shared_ptr<glt::Model_Obj>(new Model_Obj(path.c_str(), Vector3(color.x, color.y, color.z)));

    }

    renderTask->getRenderer()->add(id, model);
    return false;
}
