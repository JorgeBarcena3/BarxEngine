// File: BMainWindowComponent.cpp
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
#include "..\headers\BMainWindowComponent.hpp"
#include "..\headers\BWindowTask.hpp"

BMainWindowComponent::BMainWindowComponent(shared_ptr<BEntity> parent, string _windowName, int w, int h, bool fs) : BComponent(parent)
{
    task = shared_ptr<BWindowTask>(new BWindowTask(_windowName, w, h, fs));
}

bool BMainWindowComponent::initialize()
{
    return false;
}

bool BMainWindowComponent::parse_property(const string& name, const string& value)
{
    return true;
}
