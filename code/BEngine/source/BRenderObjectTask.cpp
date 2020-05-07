// File: BRenderObjectTask.cpp
// Author: Jorge B�rcena Lumbreras

// � Copyright (C) 2019  Jorge B�rcena Lumbreras

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "..\headers\BScene.hpp"
#include "..\headers\BTask.hpp"
#include "..\headers\BTranformTask.hpp"
#include "..\headers\BWindowTask.hpp"
#include "..\headers\BRenderTask.hpp"
#include "..\headers\BRenderObjectTask.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BTransformComponent.hpp"
#include <Render_Node.hpp>
#include <SDL.h>



BRenderObjectTask::BRenderObjectTask(string _id, const shared_ptr<BRenderTask> _instance, shared_ptr< BEntity > ent) : BTask(TASKPRIORITY::RENDEROBJECT)
{
    instance = _instance;
    id = _id;
    entity = ent;
}

bool BRenderObjectTask::initialize()
{

    return true;
}

bool BRenderObjectTask::finalize()
{

    BRenderTask::instance->getRenderer()->get(id)->set_visible(false);
    return true;
}

bool BRenderObjectTask::execute(float time)
{

    shared_ptr<glt::Matrix44> transform = entity->getTransform()->getOpenGLMatrix();
    auto obj = BRenderTask::instance->getRenderer()->get(id);
    obj->set_transformation(*transform);

    return true;
}