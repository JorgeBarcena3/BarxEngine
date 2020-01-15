#pragma once
#include "BtypeDef.hpp"

class BKernel;
class BWindow;
class BRender;

// Tareas consumibles o no consumibles
// Secuancia de tareas (hereda de task y tiene una lista de tasks)
class BTask
{

protected:

    BKernel* kernel;

    string id;

    int priority;

public:

    BTask(int priority = 0) :priority(priority)
    {
        kernel = nullptr;
    }

    virtual ~BTask()
    {
    }

    void set_kernel(BKernel* new_kernel)
    {
        kernel = new_kernel;
    }

public:

    virtual bool initialize() = 0;
    virtual bool finalize() = 0;
    virtual bool run(float time) = 0;

public:

    bool operator < (const BTask& other) const
    {
        return this->priority < other.priority;
    }

};


class BPhysics_task : public BTask
{

public:

    BPhysics_task();

private:

    bool initialize();

    bool finalize();

    bool run(float time);

};

class BRender;
class BTransform_Component;

class BRender_Task : public BTask
{

public:

    BRender_Task(string id, shared_ptr< BRender > instance, shared_ptr< BTransform_Component > transformComponent);

private:


    shared_ptr< BRender > instance;

    shared_ptr< BTransform_Component > transform;

    bool initialize();

    bool finalize();

    bool run(float time);

};



