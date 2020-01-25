// File: BColliderTask.cpp
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

#include "..\headers\BColliderTask.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BScene.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BColliderComponent.hpp"

BColliderTask::BColliderTask(shared_ptr<BEntity> _entity, shared_ptr<BScene> _scene) : BTask(TASKPRIORITY::COLLISIONS)
{
    entity = _entity;
}

bool BColliderTask::initialize()
{
    transform = entity->getTransform();
    colliderEntites = entity->getScene()->entitesWithComponent<BColliderComponent>();
    return true;
}

bool BColliderTask::finalize()
{
    return true;
}

bool BColliderTask::execute(float time)
{

    for (auto AEntity : colliderEntites)
    {
        if (onCollision) {

            auto collision = entity->getComponent<BColliderComponent>()->checkCollisions(AEntity);

            if (collision != nullptr)
            {
                onCollision(entity, AEntity);
            }
        }
    }
    return true;
}
