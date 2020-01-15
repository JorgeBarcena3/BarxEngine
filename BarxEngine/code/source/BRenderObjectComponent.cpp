#include "../headers/BComponent.hpp"
#include "../headers/BRenderObjectComponent.hpp"
#include "../headers/BTransformComponent.hpp"
#include "../headers/BRenderTask.hpp"
#include "../headers/BRenderObject_task.hpp"
#include "../headers/BEntity.hpp"
#include <Model.hpp>
#include <Cube.hpp>
#include <Node.hpp>
#include <Drawable.hpp>
#include <Render_Node.hpp>
#include <Model_Obj.hpp>
#include <Render_Node.hpp>

BRenderObjectComponent::BRenderObjectComponent(shared_ptr<BEntity> parent, string _path) : BComponent(parent)
{
    renderTask = BRenderTask::instance;
    id = parent->getId();
    task = shared_ptr<BRenderObject_Task>(new BRenderObject_Task(id, renderTask, parent->getComponent<BTransform_Component>()));
    path = _path;
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
        model = shared_ptr<glt::Model_Obj>(new Model_Obj(path.c_str()));

    }

    renderTask->getRenderer()->add(id, model);
    return false;
}
