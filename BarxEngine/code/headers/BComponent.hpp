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

/*
* Es mas un modelo de datos que de otra cosa
* Diferencian las entidades
*/
class BComponent
{
protected:

    BEntity* parent;

    //Id unico
    Id id;

public:

    BComponent(BEntity* parent) : parent(parent)
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

};

class BPhysics_Component : public BComponent
{

   /* shared_ptr< btCollisionShape > shape;
    shared_ptr< btRigidBody      > body;
    btDefaultMotionState 		   motion;*/
public:

    BPhysics_Component(BEntity* parent) : BComponent(parent)
    {
    };

    bool initialize()
    {
        // CREAR INSTANCIA DE RIGID BODY...
        return true;
    };

    bool parse_property(const string& name, const string& value)
    {
        // ...
        return true;
    };

};
