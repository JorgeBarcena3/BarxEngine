#pragma once
#include "BModule.hpp"
#include "BTask.hpp"
#include "BComponent.hpp"

class BPhysics_Module : public BModule
{
public:

    class BPhysics_Module_Factory : public BFactory
    {
    public:

        BPhysics_Module_Factory()
        {
            BModule::register_module("physics", this);
        }

        shared_ptr< BModule > create_module() override
        {
            return shared_ptr< BModule >();
        }
    };


    class BPhysics_task : public BTask
    {
        BPhysics_Module& module;

        BPhysics_task(BPhysics_Module& module) : module(module)
        {
        }

        bool initialize()
        {
            //module.world.reset(new btDynamicWorld(...));
            // ...
        }

        bool finalize()
        {
            // ...
        }

        bool runstep(float time)
        {
            //module.world->Step(time);
        }
    };

    class BPhysics_Component : public BComponent
    {
        //btRight world;
    };

    static BPhysics_Module_Factory factory;
    // Definir BPhysics_Module_Factory BPhysics_Module::factory(); un archivo .CPP

    //BPhysics_task task;

    //shared_ptr< btDynamicWorld > world;

public:

    //BPhysics_Module() //: task(*this)
    //{
    //}

    //BTask* get_task() // Override
    //{
    //    return task;
    //}

};
