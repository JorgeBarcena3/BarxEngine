#pragma once
#include "BtypeDef.hpp"
#include "BObserver.hpp"

class BComponent;
class BEntity;

class BCharacterController : public BComponent, public BOrbserver
{

    string Up;
    string Down;
    string Left;
    string Right;

    float speed;

public:

    BCharacterController(shared_ptr <BEntity> parent);

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


    // Inherited via BOrbserver
    virtual void handle(const BMessage& m) override;

};
