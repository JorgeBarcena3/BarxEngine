// File: BShereColliderComponent.cpp
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

#include "..\headers\BColliderComponent.hpp"
#include "..\headers\BShereColliderComponent.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BBoxColliderComponent.hpp"
#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

BSphereColliderComponent::BSphereColliderComponent(shared_ptr<BEntity> parent) : BColliderComponent(parent)
{
    transform = parent->getTransform();
    type = COLLIDERTYPE::SPHERE;
    radius = 1;
}

bool BSphereColliderComponent::initialize()
{


    shape.reset(new btSphereShape(btScalar(radius)));

    
    return true;
}

bool BSphereColliderComponent::parse_property(const string& name, const string& value)
{

    if (name == "radius")
    {
        radius = stof(value);
    }

    return true;
}

shared_ptr<BEntity> BSphereColliderComponent::checkCollisions(shared_ptr<BEntity> other)
{
  

    return shared_ptr<BEntity>(nullptr);
}