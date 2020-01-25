// File: BLightComponent.cpp
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

#include "..\headers\BtypeDef.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BLightComponent.hpp"
#include "..\headers\BRenderTask.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTransformComponent.hpp"
#include <Camera.hpp>
#include <Render_Node.hpp>
#include <Light.hpp>

BLightComponent::BLightComponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
}

bool BLightComponent::initialize()
{
    // Se crean los elementos básicos necesarios para dibujar un cubo:

    light = shared_ptr< glt::Light >(new glt::Light);

    BRenderTask::instance->getRenderer()->add(parent->getId(), light);
    BRenderTask::instance->getRenderer()->get(parent->getId())->translate(Vector3(
        parent->getTransform()->position.x,
        parent->getTransform()->position.y,
        parent->getTransform()->position.z
    ));

    return false;
}

bool BLightComponent::parse_property(const string& name, const string& value)
{
    return true;
};