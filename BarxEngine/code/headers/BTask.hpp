#pragma once
#include "BtypeDef.hpp"

class BKernel;

// Tareas consumibles o no consumibles
// Secuancia de tareas (hereda de task y tiene una lista de tasks)
class BTask
{

protected:

    BKernel* kernel;

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

class BWindow;

class BWindow_Task : public BTask
{

public:

    BWindow_Task();

private:


    shared_ptr< BWindow > instance;

    bool initialize();

    bool finalize();

    bool run(float time);

};


