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

using namespace glt;

BTransform_Component::BTransform_Component(shared_ptr <BEntity> parent) : BComponent(parent)
{
    task = shared_ptr<BTransform_task>(new BTransform_task(parent->getId(),shared_ptr<BTransform_Component>( this )));
};

BControlComponent::BControlComponent(shared_ptr <BEntity> parent) : BComponent(parent)
{
   // task = shared_ptr<BTransform_task>(new BTransform_task());
};

BRenderComponent::BRenderComponent(shared_ptr<BEntity> parent, shared_ptr<BRender> _system, string _path) : BComponent(parent)
{
    system = _system;
    id = parent->getId();
    task = shared_ptr<BRender_Task>(new BRender_Task(id, system, parent->getComponent<BTransform_Component>()));
    path = _path;   
}

bool BRenderComponent::initialize()
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
