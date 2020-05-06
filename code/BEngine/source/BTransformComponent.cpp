// File: BTransformComponent.cpp
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
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTranformTask.hpp"
#include <btBulletDynamicsCommon.h>
#include <LinearMath\btVector3.h>
#include <Math.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


using namespace glt;

BTransformComponent::BTransformComponent(shared_ptr <BEntity> parent) : BComponent(parent)
{
    task              = shared_ptr<BTransformTask>(new BTransformTask(parent->getId(), shared_ptr<BTransformComponent>(this)));
    parent->transform = shared_ptr<BTransformComponent>(this);

    position.x = 0; position.y = 0; position.z = 0;
    rotation.x = 0; rotation.y = 0; rotation.z = 0;
    scale.x    = 1; scale.y    = 1; scale.z    = 1;

}

bool BTransformComponent::initialize()
{
    return true;
}

bool BTransformComponent::parse_property(const string& name, const string& value)
{
    std::stringstream test(value);
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(test, segment, ','))
    {
        seglist.push_back(segment);
    }

    if (name == "position")
    {
        position.x = stof(seglist[0]);
        position.y = stof(seglist[1]);
        position.z = stof(seglist[2]);
    }
    else if (name == "rotation")
    {
        rotation.x = stof(seglist[0]);
        rotation.y = stof(seglist[1]);
        rotation.z = stof(seglist[2]);

    }
    else if (name == "scale")
    {
        scale.x = stof(seglist[0]);
        scale.y = stof(seglist[1]);
        scale.z = stof(seglist[2]);
    }
    
    return true;
}

shared_ptr<glt::Matrix44> BTransformComponent::getOpenGLMatrix()
{
    glm::mat4 trans = glm::mat4(1.0f);

    trans = glm::translate(trans, glm::vec3(position.x, position.y, position.z));
    trans = glm::rotate(trans, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    trans = glm::rotate(trans, rotation.x, glm::vec3(0.0f, 1.0f, 0.0f));
    trans = glm::rotate(trans, rotation.x, glm::vec3(0.0f, 0.0f, 1.0f));
    trans = glm::scale(trans, glm::vec3(scale.x, scale.y, scale.z));

    return shared_ptr<glm::mat4>(new glm::mat4(trans));
}
