#pragma once
#include "BtypeDef.hpp"

#include "BTimer.hpp"

class BTask;
class BSystem;

class BKernel
{
    typedef std::multiset< shared_ptr<BTask> > BTask_List;

    BTask_List      BTasks;

    BTimer deltaTime;

    bool exit;
    bool paused;

public:

    BKernel()
    {
        BTasks = std::multiset< shared_ptr<BTask> >();
    }

    void add_Task(shared_ptr<BTask> task);

    //Aqui está el bucle principal
    void run();


    void stop()
    {
        exit = true;
    }

    void pause()
    {
        paused = true;
    }

    void resume()
    {
        paused = false;
    }

};

