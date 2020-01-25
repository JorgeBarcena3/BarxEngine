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
#include "..\headers\BColliderComponent.hpp"
#include "..\headers\BBoxColliderComponent.hpp"
#include "..\headers\BShereColliderComponent.hpp"
#include "..\headers\BColliderTask.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BEntity.hpp"

BBoxColliderComponent::BBoxColliderComponent(shared_ptr<BEntity> parent) : BColliderComponent(parent)
{
    transform = parent->getTransform();
    type      = COLLIDERTYPE::BOX     ;
    MaxOffset = vec3<float>(1, 1, 1)  ;
    MinOffset = vec3<float>(1, 1, 1)  ;
}

bool BBoxColliderComponent::initialize()
{
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

    if (name == "max")
    {
        MaxOffset.x = stof(seglist[0]);
        MaxOffset.y = stof(seglist[1]);
        MaxOffset.z = stof(seglist[2]);
    }
    else if (name == "min")
    {
        MinOffset.x = stof(seglist[0]);
        MinOffset.y = stof(seglist[1]);
        MinOffset.z = stof(seglist[2]);
    }

    return true;
}

shared_ptr<BEntity> BBoxColliderComponent::checkCollisions(shared_ptr<BEntity> other)
{
    shared_ptr< BColliderComponent> collider = other->getComponent<BColliderComponent>();

    if (collider->getType() == COLLIDERTYPE::SPHERE)
    {
        auto BTransform = other->getTransform();

        if (transform != BTransform)
        {
            shared_ptr< BShereColliderComponent > collider = other->getComponent<BShereColliderComponent>();

            vec3<float> Min(
                transform->position.x - MinOffset.x,
                transform->position.y - MinOffset.y,
                transform->position.z - MinOffset.z
                );

            vec3<float> Max(
                transform->position.x + MaxOffset.x,
                transform->position.y + MaxOffset.y,
                transform->position.z + MaxOffset.z
            );

            float x = max(Min.x, min(BTransform->position.x, Max.x));
            float y = max(Min.y, min(BTransform->position.y, Max.y));
            float z = max(Min.z, min(BTransform->position.z, Max.z));

            float distance = sqrt(
                (x - BTransform->position.x) * (x - BTransform->position.x) +
                (y - BTransform->position.y) * (y - BTransform->position.y) +
                (z - BTransform->position.z) * (z - BTransform->position.z)
            );

            if (distance < collider->radius)
                return other;


        }

    }
    else if (collider->getType() == COLLIDERTYPE::BOX)
    {
        auto BTransform = other->getTransform();

        if (transform != BTransform) {

            shared_ptr< BBoxColliderComponent> collider = other->getComponent<BBoxColliderComponent>();

            vec3<float> Min(
                transform->position.x - MinOffset.x,
                transform->position.y - MinOffset.y,
                transform->position.z - MinOffset.z
            );

            vec3<float> Max(
                transform->position.x + MaxOffset.x,
                transform->position.y + MaxOffset.y,
                transform->position.z + MaxOffset.z
            );


            vec3<float> CMin(
                BTransform->position.x - collider->MinOffset.x,
                BTransform->position.y - collider->MinOffset.y,
                BTransform->position.z - collider->MinOffset.z
            );

            vec3<float> CMax(
                BTransform->position.x + collider->MaxOffset.x,
                BTransform->position.y + collider->MaxOffset.y,
                BTransform->position.z + collider->MaxOffset.z
            );

            if (
                (Min.x <= CMax.x && Max.x >= CMin.x) &&
                (Min.y <= CMax.y && Max.y >= CMin.y) &&
                (Min.z <= CMax.z && Max.z >= CMin.z)
                )

                return other;

        }

    }

    return shared_ptr<BEntity>(nullptr);
}