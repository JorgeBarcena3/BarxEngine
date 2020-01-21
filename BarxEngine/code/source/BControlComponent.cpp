// File: BControlComponent.cpp
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
#include "..\headers\BControlComponent.hpp"
#include "..\headers\BControlTask.hpp"

BControlComponent::BControlComponent(shared_ptr <BEntity> parent) : BComponent(parent)
{
     task = shared_ptr<BControlTask>(new BControlTask(parent));
     myFunction = nullptr;
}

void BControlComponent::setFunction(std::function<void(float, shared_ptr<BEntity>)> _myFunction)
{
    myFunction = _myFunction;
    auto controlComponent = dynamic_pointer_cast<BControlTask>(task);
    controlComponent->myFunction = _myFunction;
}

bool BControlComponent::initialize()
{
    return false;
}

bool BControlComponent::parse_property(const string& name, const string& value)
{
    return false;
}
