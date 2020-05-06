// File: BRenderObjectComponent.hpp
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
#include "..\headers\BMainPhysicsTask.hpp"
#include "..\headers\BtypeDef.hpp"
#include "..\headers\BMainPhysicsComponent.hpp"
#include <btBulletDynamicsCommon.h>


BMainPhysicsTask::BMainPhysicsTask(shared_ptr<BMainPhysicsComponent> _phyComp) : BTask(TASKPRIORITY::COLLISIONS)
{
    physicsComponent = _phyComp;
}

BMainPhysicsTask::~BMainPhysicsTask()
{
}


bool BMainPhysicsTask::initialize()
{
    return false;
}

bool BMainPhysicsTask::finalize()
{
    return false;
}

bool BMainPhysicsTask::execute(float time)
{
    physicsComponent->dynamicsWorld->stepSimulation(1.f / 60.f);
    return true;
}
