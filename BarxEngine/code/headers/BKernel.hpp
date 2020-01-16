#pragma once
#include "BtypeDef.hpp"

#include "BTimer.hpp"

class BTask;
class BScene;

class BKernel
{
    typedef std::multiset< shared_ptr<BTask> > BTask_List;

    BTask_List      BTasks;

    shared_ptr<BScene> scene;

    bool exit;
    bool paused;

public:

    BKernel(shared_ptr<BScene> _scene)
    {
        BTasks = std::multiset< shared_ptr<BTask> >();
        scene = _scene;
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

    shared_ptr<BScene> getScene() { return scene; }

};

