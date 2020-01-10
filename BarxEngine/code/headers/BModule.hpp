#pragma once
#include "BtypeDef.hpp"
#include "BPhysicsModule.hpp"


class BTask;
class BScene;

class BModule
{
public:

    class BFactory
    {
    public:
        virtual shared_ptr< BModule > create_module() = 0;
    };


public:

    typedef map < std::string, shared_ptr< BModule::BFactory >> FModule_Map;

    static FModule_Map modules;

public:

    // Reimplementar si se tiene Task.
    virtual BTask* get_task()
    {
        return nullptr;
    }

public:

    BModule(BScene* owner);

    virtual ~BModule()
    {
    }

    static void register_module(const std::string& id, BModule::BFactory* factory)
    {
        auto aa = factory->create_module();
        modules[id] = shared_ptr<BModule>(aa);
    }

    static FModule_Map& get_module_map()
    {
        return modules;
    }

};


