#pragma once
#include "BtypeDef.hpp"
#include "BObserver.hpp"

class BComponent;
class BOrbserver;
class BEntity;
class BKeyboard;

class BKeyboardComponent : public BComponent, public BOrbserver
{


public:

    BKeyboardComponent(shared_ptr <BEntity> parent);

    // Inherited via BComponent
    virtual bool initialize();

    virtual bool parse_property(const string& name, const string& value)
    {        return true;
    };

    shared_ptr< BKeyboard > Keyboard;

    // Inherited via BOrbserver
    void handle(const BMessage& m);

};
