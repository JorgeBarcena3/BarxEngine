// Author: Jorge B�rcena Lumbreras

// � Copyright (C) 2020  Jorge B�rcena Lumbreras

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

#include <string>
#include <BEngine.hpp>

#ifndef DEMOENTITY
#define DEMOENTITY


class DemoEntity
{
      

protected:

    shared_ptr<BEntity> entity;

    shared_ptr<BPhysicsCompmponent> physicsComponent;

public:

    std::string id;


public:

    DemoEntity() = default;

    virtual void start(BScene * scene) = 0;

    virtual void update(float time, shared_ptr<BEntity> entity) = 0;

    virtual void onCollision(BEntity* me, BEntity* other) = 0;

    shared_ptr<BPhysicsCompmponent> getPhysicsComponent()
    {
        return physicsComponent;
    };

    shared_ptr<BEntity> getEntity()
    {
        return entity;
    };

};
#endif