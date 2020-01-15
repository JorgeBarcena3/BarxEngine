#pragma once
#include "BtypeDef.hpp"


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
        scale.x = 1; scale.y = 1; scale.z = 1;

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
