// File: BInputComponent.cpp
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

#include "..\headers\BComponent.hpp"
#include "..\headers\BInputComponent.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTask.hpp"
#include "..\headers\BInputHandlerTask.hpp"
#include "..\headers\BControlTask.hpp"

BInputComponent::BInputComponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
    task =  shared_ptr<BMyInputHandlerTask>(new BMyInputHandlerTask(true));
}

bool BInputComponent::initialize()
{
    return false;
}

bool BInputComponent::parse_property(const string& name, const string& value)
{
    return false;
}
