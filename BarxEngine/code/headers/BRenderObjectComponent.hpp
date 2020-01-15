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

    BRenderObjectComponent(shared_ptr <BEntity> parent, string path = "");

    bool initialize();


    bool parse_property(const string& name, const string& value)
    {
        return true;
    }


};