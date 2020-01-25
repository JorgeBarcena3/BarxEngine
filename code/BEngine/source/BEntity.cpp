// File: BEntity.cpp
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

#include "..\headers\BEntity.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BtypeDef.hpp"
#include "..\headers\BTransformComponent.hpp"

BEntity::BEntity(string _id, shared_ptr<BScene> _scene)
{
    id = _id;
    scene = _scene;
    components = map< string, shared_ptr< BComponent > >();
  
}

bool BEntity::initialize()
{

    bool result = true;

    for (auto component : components)
    {
        if (component.second->initialize() == false)
        {
            result = false;
        }
    }

    return result;
}

shared_ptr<BTransformComponent> BEntity::getTransform()
{
    return dynamic_pointer_cast<BTransformComponent>(transform);
}

shared_ptr<BScene> BEntity::getScene()
{
    return scene;
}

bool BEntity::addComponent(const string& type, shared_ptr<BComponent>& component)
{
   
    if (components.count(type) != 0)
    {
        return false;
    }
    else
    {
        components[type] = component;
        return true;
    }

}

const string BEntity::getId() {
    return id; 
}

list<shared_ptr<BComponent>> BEntity::getComponents()
{
    std::list<shared_ptr<BComponent>> list;

    for (auto component : components) 
    {
        list.push_back(component.second);
    }
    return list;
}
