#pragma once
#include "../headers/BtypeDef.hpp"
#include "../headers/BTask.hpp"
#include "../headers/BRender.hpp"
#include "..//headers/BEntity.hpp"
#include "..//headers/BComponent.hpp"
#include "..//headers/BTransform_Component.hpp"
#include <Render_Node.hpp>


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

bool BTransform_task::run(float time)
{
    auto obj = BRender::instance->getRenderer()->get(id);

    obj->rotate_around_y(0.001f);

    return true;
}