#pragma once
#include "BtypeDef.hpp"

class BComponent;
class BEntity;

class BColliderComponent : public BComponent
{


public:

    float radius;

    BColliderComponent(shared_ptr <BEntity> parent);

    void setFunction(std::function<void(shared_ptr<BEntity>, shared_ptr<BEntity>)> myFunction);

    bool initialize()
    {
        return true;
    };

    bool parse_property(const string& name, const string& value)
    {
        

        if (name == "radius")
        {
            radius = stof(value);
        }

        return true;
    };

};
