#include "../headers/BComponent.hpp"
#include "../headers/BRender_Component.hpp"
#include "../headers/BTask.hpp"
#include "../headers/BComponent.hpp"
#include "../headers/BRender.hpp"
#include "../headers/BEntity.hpp"
#include <Model.hpp>
#include <Cube.hpp>
#include <Node.hpp>
#include <Drawable.hpp>
#include <Render_Node.hpp>
#include <Model_Obj.hpp>
#include "../headers/BRender_task.hpp"

using namespace glt;



BRender_Component::BRender_Component(shared_ptr<BEntity> parent, shared_ptr<BRender> _system, string _path) : BComponent(parent)
{
    system = _system;
    id = parent->getId();
    task = shared_ptr<BRender_Task>(new BRender_Task(id, system, parent->getComponent<BTransform_Component>()));
    path = _path;
}

bool BRender_Component::initialize()
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

    system->getRenderer()->add(id, model);
    return false;
}