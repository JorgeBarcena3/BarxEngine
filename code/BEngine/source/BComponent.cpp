// File: BComponent.cpp
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

#include "..\headers\BTask.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BEntity.hpp"

using namespace glt;

BComponent::BComponent(shared_ptr<BEntity> parent, COMPONENT_INITIALIZATION prior) : parent(parent), priority(prior)
{    }
BComponent::~BComponent()
{    };

shared_ptr<BTask> BComponent::getTask()
{
    if (task != nullptr)
        return task;

    return shared_ptr<BTask>(nullptr);
}
shared_ptr<BEntity> BComponent::getEntity()
{
    return parent;
}

bool BComponent::operator<(const BComponent& other)
{
    return this->priority < other.priority;
}
