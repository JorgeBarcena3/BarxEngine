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
#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

BBoxColliderComponent::BBoxColliderComponent(shared_ptr<BEntity> parent) : BColliderComponent(parent)
{
    transform = parent->getTransform();
    type = COLLIDERTYPE::BOX;
    BoxShape = vec3<float>(1, 1, 1);
}

bool BBoxColliderComponent::initialize()
{

    shape.reset(new btBoxShape(btVector3(BoxShape.x, BoxShape.y, BoxShape.z)));
         
    return true;
}

bool BBoxColliderComponent::parse_property(const string& name, const string& value)
{
    std::stringstream test(value);
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(test, segment, ','))
    {
        seglist.push_back(segment);
    }

    if (name == "boxShape")
    {
        BoxShape.x = stof(seglist[0]);
        BoxShape.y = stof(seglist[1]);
        BoxShape.z = stof(seglist[2]);
    }
    else if (name == "mask")
    {
        collisionMask = static_cast<COLLISION_MASK>( atoi(value.c_str()) );
    }
    else if (name == "group")
    {
        collisionGroup = static_cast<COLLISION_GROUP>( atoi(value.c_str()) );
    }
    else if (name == "trigger")
    {
        isTrigger = value == "1" ? true : false;
    }

    return true;
}

shared_ptr<BEntity> BBoxColliderComponent::checkCollisions(shared_ptr<BEntity> other)
{


    return shared_ptr<BEntity>(nullptr);
}