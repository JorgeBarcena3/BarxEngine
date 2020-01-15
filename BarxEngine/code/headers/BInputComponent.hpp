#pragma once
#include "BtypeDef.hpp"

class BComponent;
class BEntity;

class BInputComponent : public BComponent
{
    
public:

    BInputComponent(shared_ptr <BEntity> parent);

    // Inherited via BComponent
    virtual bool initialize();

    virtual bool parse_property(const string& name, const string& value);

};
