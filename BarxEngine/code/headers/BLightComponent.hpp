#pragma once
#include "BtypeDef.hpp"

class BComponent;
class BEntity;

class BLightComponent : public BComponent
{

    shared_ptr< glt::Light > light;


public:

    BLightComponent(shared_ptr <BEntity> parent);

    // Inherited via BComponent
    virtual bool initialize();

    virtual bool parse_property(const string& name, const string& value)
    {
        return true;
    };


};
