#pragma once
#include "BtypeDef.hpp"
#include "BObserver.hpp"

class BComponent;
class BEntity;

class BCharacterControllerComponent : public BComponent
{

public:

    string Up;
    string Down;
    string Left;
    string Right;

    float speed;

public:

    BCharacterControllerComponent(shared_ptr <BEntity> parent);

    // Inherited via BComponent
    virtual bool initialize();

    virtual bool parse_property(const string& name, const string& value)
    {
        if (name == "Up")
            Up = value;
        else  if (name == "Down")
            Down = value;
        else  if (name == "Left")
            Left = value;
        else  if (name == "Right")
            Right = value;
        else if (name == "speed")
            speed = stof(value);

        return true;
    };


};
