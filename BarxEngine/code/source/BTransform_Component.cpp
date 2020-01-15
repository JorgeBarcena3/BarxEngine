#include "../headers/BComponent.hpp"
#include "../headers/BTransform_Component.hpp"
#include "../headers/BTask.hpp"
#include "../headers/BEntity.hpp"


BTransform_Component::BTransform_Component(shared_ptr <BEntity> parent) : BComponent(parent)
{
    task = shared_ptr<BTransform_task>(new BTransform_task(parent->getId(), shared_ptr<BTransform_Component>(this)));
}

bool BTransform_Component::initialize()
{
    position.x = 0; position.y = 0; position.z = 0;
    rotation.x = 0; rotation.y = 0; rotation.z = 0;
    scale.x = 0; scale.y = 0; scale.z = 0;

    return true;
}
bool BTransform_Component::parse_property(const string& name, const string& value)
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