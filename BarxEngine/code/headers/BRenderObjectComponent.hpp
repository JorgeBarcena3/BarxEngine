#pragma once
#include "BtypeDef.hpp"

class BComponent;
class BRenderTask;
class BRenderObject_Task;

class BRenderObjectComponent : public BComponent
{
    string path;
    shared_ptr<BRenderTask> renderTask;
    shared_ptr< glt::Model > model;

public:

    BRenderObjectComponent(shared_ptr <BEntity> parent);

    bool initialize();


    bool parse_property(const string& name, const string& value)
    {
        if (name == "model")
            path = value;

        return true;
    }


};