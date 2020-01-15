#pragma once
#include "BtypeDef.hpp"

#include "BTimer.hpp"

class BTask;
class BSystem;

class BKernel
{
    typedef std::multiset< shared_ptr<BTask> > BTask_List;
    typedef std::multiset< shared_ptr<BSystem>> BSystems_list;

    BTask_List      BTasks;
    BSystems_list   BSystems;

    BTimer deltaTime;

    bool exit;
    bool paused;

public:

    BKernel()
    {
        BTasks = std::multiset< shared_ptr<BTask> >();
        BSystems = std::multiset< shared_ptr<BSystem> >();
    }

    void add_Task(shared_ptr<BTask> task);

    void add_system(shared_ptr<BSystem> system);

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

