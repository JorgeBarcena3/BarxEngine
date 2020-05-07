// File: BCharacterCollider.cpp
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
#include "..\headers\BComponent.hpp"
#include "..\headers\BCharacterController.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTask.hpp"
#include "..\headers\BObserver.hpp"
#include "..\headers\BScene.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BCharacterControllerTask.hpp"

BCharacterControllerComponent::BCharacterControllerComponent(shared_ptr<BEntity> parent) : BComponent(parent, COMPONENT_INITIALIZATION::CONTROL_COMPONENT)
{
    task = shared_ptr<BCharacterControllerTask>(new BCharacterControllerTask(parent, shared_ptr<BCharacterControllerComponent>(this)));
}

bool BCharacterControllerComponent::initialize()
{
    return true;
}

bool BCharacterControllerComponent::parse_property(const string& name, const string& value)
{
    if (name == "Up")
        Up = value;
    else  if (name == "Down")
        Down = value;
    else  if (name == "Left")
        Left = value;
    else  if (name == "Right")
        Right = value;
    else  if (name == "Jump")
        Jump = value;
    else if (name == "speed")
        speed = stof(value);
    else if (name == "JumpForce")
        JumpForce = stof(value);

    return true;
}