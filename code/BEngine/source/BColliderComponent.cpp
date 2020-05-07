// File: BColliderComponent.cpp
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
#include "..\headers\BEntity.hpp"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <LinearMath\btVector3.h>

BColliderComponent::BColliderComponent(shared_ptr<BEntity> parent) : BComponent(parent, COMPONENT_INITIALIZATION::COLLIDER_COMPONENT)
{
    shape = shared_ptr< btCollisionShape >(nullptr);

}

void BColliderComponent::setFunction(std::function<void(BEntity * , BEntity *)> myFunction)
{
    collisionFunction = myFunction;
}

COLLIDERTYPE BColliderComponent::getType()
{
    return type;
}

shared_ptr<btCollisionShape> BColliderComponent::getShape()
{
    return shape;
}
