// File: BKeyboardComponent.cpp
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
#include "..\headers\BKeyboardComponent.hpp"
#include "..\headers\BObserver.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTask.hpp"
#include "..\headers\BScene.hpp"
#include "..\headers\BKeyboard.hpp"

BKeyboardComponent::BKeyboardComponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
    task              = shared_ptr<BTask>(nullptr)            ;  
    Keyboard          = shared_ptr<BKeyboard>(new BKeyboard());
    parent->getScene()->getDispacher()->add(*this, "Keyboard"); //Nos subscribimos al evento de keyboard
}

bool BKeyboardComponent::initialize()
{
    return true;
}

bool BKeyboardComponent::parse_property(const string& name, const string& value)
{
    return false;
}

void BKeyboardComponent::handle(const BMessage& m)
{
    for (auto param : m.parameters)
    {
        if (param.first == "KeyDown")
        {
            Keyboard->setKeyDown(param.second);
        }
        else if (param.first == "KeyUp")
        {
            Keyboard->setKeyUp(param.second);
        }
    }
}
