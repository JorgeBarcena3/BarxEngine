#pragma once
#pragma once
#include "BtypeDef.hpp"

class BComponent;
class BWindowTask;
class BEntity;

class BMainWindowComponent : public BComponent
{  

public:

    BMainWindowComponent(shared_ptr <BEntity> parent);

    bool initialize();

    bool parse_property(const string& name, const string& value)
    {
        return true;
    }


};