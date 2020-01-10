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
