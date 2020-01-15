// File: BComponent.hpp
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
//

#pragma once
#include "BtypeDef.hpp"

class BEntity;
class BTask;
class BPhysics_task;

using namespace glt;

/*
* Es mas un modelo de datos que de otra cosa
* Diferencian las entidades
*/
class BComponent
{
protected:

    string id;

    shared_ptr<BEntity> parent;

    shared_ptr<BTask> task;

public:

    BComponent(shared_ptr<BEntity> parent) : parent(parent)
    {

    };

    virtual ~BComponent()
    {
    };

    virtual bool initialize() = 0;

    virtual bool parse_property
    (
        const string& name,
        const string& value
    ) = 0;


    shared_ptr<BTask> getTask()
    {
        return task;
    };
};


class BTransform_Component : public BComponent
{


public:

    vec3<float> position;
    vec3<float> rotation;
    vec3<float> scale;

    BTransform_Component(shared_ptr <BEntity> parent);

    bool initialize()
    {
        position.x = 0; position.y = 0; position.z = 0; 
        rotation.x = 0; rotation.y = 0; rotation.z = 0;
        scale.x = 0; scale.y = 0; scale.z = 0; 
        
        return true;
    };

    bool parse_property(const string& name, const string& value)
    {
        std::stringstream test(value);
        std::string segment;
        std::vector<std::string> seglist;

        while (std::getline(test, segment, ','))
        {
            seglist.push_back(segment);
        }

        if (name == "Position")
        {
            position.x = stof(seglist[0]);
            position.y = stof(seglist[1]);
            position.z = stof(seglist[2]);
        }
        else if (name == "Rotation")
        {
            rotation.x = stof(seglist[0]);
            rotation.y = stof(seglist[1]);
            rotation.z = stof(seglist[2]);

        }
        else if (name == "Scale")
        {
            scale.x = stof(seglist[0]);
            scale.y = stof(seglist[1]);
            scale.z = stof(seglist[2]);
        }


        return true;
    };

};

class BRender;

class BRenderComponent : public BComponent
{
    string path;
    shared_ptr<BRender> system;
    shared_ptr< glt::Model > model;

public:

    BRenderComponent(string name, shared_ptr <BEntity> parent, shared_ptr<BRender> system, string path = "");

    bool initialize();
    

    bool parse_property(const string& name, const string& value)
    {
        return true;
    }


};


class BControlComponent : public BComponent
{
    vec3<float> direction;
    vec3<float> velocity;

    BControlComponent(shared_ptr <BEntity> parent);
};
