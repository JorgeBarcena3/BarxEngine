#pragma once
#include "BtypeDef.hpp"
#include "BObserver.hpp"

class BComponent;
class BEntity;

class BCameraComponent : public BComponent
{

    shared_ptr< glt::Camera > camera;

    float fov;
    float near;
    float far;
    float aspectRatio;


public:

    BCameraComponent(shared_ptr <BEntity> parent);

    // Inherited via BComponent
    virtual bool initialize();

    virtual bool parse_property(const string& name, const string& value)
    {
        if (name == "fov")
        {
            fov = stof(value);
        }
        else   if (name == "near")
        {
            near = stof(value);
        }
        else   if (name == "far")
        {
            far = stof(value);
        }
        else   if (name == "aspectRatio")
        {
            aspectRatio = stof(value);
        }
        return true;
    };


};
