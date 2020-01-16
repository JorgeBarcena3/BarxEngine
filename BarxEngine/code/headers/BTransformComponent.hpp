#pragma once
#include "BtypeDef.hpp"
#include "BComponent.hpp"


class BTransformComponent : public BComponent
{


public:

    vec3<float> position;
    vec3<float> rotation;
    vec3<float> scale;

    BTransformComponent(shared_ptr <BEntity> parent);

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
    };

};
