#pragma once
#include "BtypeDef.hpp"

class BComponent;
class BRenderTask;
class BEntity;

class BMainRenderer : public BComponent
{

public:

    BMainRenderer(shared_ptr <BEntity> parent);

    bool initialize();

    bool parse_property(const string& name, const string& value)
    {
        return true;
    }


};