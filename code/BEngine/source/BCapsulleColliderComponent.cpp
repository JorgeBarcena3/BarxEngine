// File: BBoxColliderComponent.cpp
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
#include <Math.hpp>
#include "..\headers\BColliderComponent.hpp"
#include "..\headers\BBoxColliderComponent.hpp"
#include "..\headers\BShereColliderComponent.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BCapsulleColliderComponent.hpp"
#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

BCapsulleColliderComponent::BCapsulleColliderComponent(shared_ptr<BEntity> parent) : BColliderComponent(parent)
{
    transform = parent->getTransform();
    type = COLLIDERTYPE::CAPSULE;
    radius = 1;
    height = 1;
}

bool BCapsulleColliderComponent::initialize()
{

    shape.reset(new btCapsuleShape(radius, height));

    return true;
}

bool BCapsulleColliderComponent::parse_property(const string& name, const string& value)
{

    if (name == "radius")
    {
        radius = atof(value.c_str());
    }
    else if (name == "height")
    {
        radius = atof(value.c_str());
    }
    else if (name == "mask")
    {
        collisionMask = static_cast<COLLISION_MASK>(atoi(value.c_str()));
    }
    else if (name == "group")
    {
        collisionGroup = static_cast<COLLISION_GROUP>(atoi(value.c_str()));
    }
    else if (name == "trigger")
    {
        isTrigger = value == "1" ? true : false;
    }

    return true;
}

shared_ptr<BEntity> BCapsulleColliderComponent::checkCollisions(shared_ptr<BEntity> other)
{
    return shared_ptr<BEntity>();
}
