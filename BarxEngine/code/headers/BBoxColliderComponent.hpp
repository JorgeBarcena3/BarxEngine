
#pragma once
#include "BtypeDef.hpp"

class BComponent;
class BEntity;
class BColliderComponent;
class BTransformComponent;

class BBoxColliderComponent : public BColliderComponent
{
    
    shared_ptr<BTransformComponent> transform;

public:
   
    vec3<float> MaxOffset;
    vec3<float> MinOffset;

    BBoxColliderComponent(shared_ptr <BEntity> parent);

    bool initialize()
    {
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

        if (name == "max")
        {
            MaxOffset.x = stof(seglist[0]);
            MaxOffset.y = stof(seglist[1]);
            MaxOffset.z = stof(seglist[2]);
        }
        else if (name == "min")
        {
            MinOffset.x = stof(seglist[0]);
            MinOffset.y = stof(seglist[1]);
            MinOffset.z = stof(seglist[2]);
        }
       

        return true;
    };

    // Inherited via BColliderComponent
    shared_ptr<BEntity> checkCollisions(shared_ptr<BEntity> other);

};
