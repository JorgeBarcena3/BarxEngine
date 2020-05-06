// File: BColliderComponent.cpp
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

#include "..\headers\BColliderComponent.hpp"
#include "..\headers\BColliderTask.hpp"
#include "..\headers\BEntity.hpp"

BColliderComponent::BColliderComponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
    task = shared_ptr<BColliderTask>(new BColliderTask(parent, parent->getScene()));
}

void BColliderComponent::setFunction(std::function<void(shared_ptr<BEntity>, shared_ptr<BEntity>)> myFunction)
{
    auto colliderComponet         = dynamic_pointer_cast<BColliderTask>(task);
    colliderComponet->onCollision = myFunction;
}

COLLIDERTYPE BColliderComponent::getType()
{
    return type;
}