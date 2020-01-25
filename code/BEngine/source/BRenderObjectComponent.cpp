// File: BRenderObjectComponent.cpp
// Author: Jorge Bárcena Lumbreras

// © Copyright (C) 2019  Jorge Bárcena Lumbreras

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

#include "..\headers\BComponent.hpp"
#include "..\headers\BRenderObjectComponent.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BRenderTask.hpp"
#include "..\headers\BRenderObjectTask.hpp"
#include "..\headers\BEntity.hpp"
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
    id         = parent->getId();
    task       = shared_ptr<BRenderObjectTask>(new BRenderObjectTask(id, renderTask));
    color      = vec3<float>(.4f, .5f, .5f);
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

bool BRenderObjectComponent::parse_property(const string& name, const string& value)
{
    if (name == "model")
        path = value;

    return true;
}
