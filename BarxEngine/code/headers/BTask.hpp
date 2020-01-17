#pragma once
#include "BtypeDef.hpp"

class BKernel;
class BRenderTask;
class BRenderTask;
class BTransformComponent;

// Tareas consumibles o no consumibles
// Secuancia de tareas (hereda de task y tiene una lista de tasks)
class BTask
{

protected:

    BKernel* kernel;

    string id;

 

public:

    int priority;

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
    virtual bool execute(float time) = 0;

public:

    bool operator < (const BTask& other) const
    {
        return this->priority > other.priority;
    }

};

