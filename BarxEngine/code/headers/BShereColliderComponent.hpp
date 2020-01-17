
#pragma once
#include "BtypeDef.hpp"

class BComponent;
class BEntity;
class BColliderComponent;
class BTransformComponent;

class BShereColliderComponent : public BColliderComponent
{

    shared_ptr<BTransformComponent> transform;

public:

    float radius;

    BShereColliderComponent(shared_ptr <BEntity> parent);

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

    // Inherited via BColliderComponent
    shared_ptr<BEntity> checkCollisions(shared_ptr<BEntity> other);

};
