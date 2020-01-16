#pragma once
#pragma once
#include "BtypeDef.hpp"

class BComponent;
class BWindowTask;
class BEntity;

class BMainWindowComponent : public BComponent
{  

public:

    BMainWindowComponent(shared_ptr <BEntity> parent, string windowName = "BarxEngine tool", int w = 1200, int h = 800, bool fs = false);

    bool initialize();

    bool parse_property(const string& name, const string& value)
    {
        return true;
    }


};