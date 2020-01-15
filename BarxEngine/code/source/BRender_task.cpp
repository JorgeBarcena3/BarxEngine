#pragma once
#include "../headers/BtypeDef.hpp"
#include "../headers/BTask.hpp"
#include "../headers/BRender.hpp"
#include "..//headers/BEntity.hpp"
#include "..//headers/BComponent.hpp"
#include "..//headers/BTransform_Component.hpp"
#include "../headers/BRender_task.hpp"
#include <Render_Node.hpp>



BRender_Task::BRender_Task(string _id, const shared_ptr<BRender> _instance, const shared_ptr< BTransform_Component > _transformComponent)
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

    auto obj = instance->getRenderer()->get(id);

    obj->translate(glt::Vector3(transform->position.x, transform->position.y, transform->position.z));

    return true;
}