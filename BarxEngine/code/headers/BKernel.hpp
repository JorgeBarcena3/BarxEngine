#pragma once
#include "BtypeDef.hpp"

#include "BTimer.hpp"
#include "BTask.hpp"

class BKernel
{
    typedef std::multiset< shared_ptr<BTask> > BTask_List;

    BTask_List BTasks;

    BTimer deltaTime;

    bool exit;
    bool paused;

public:

    BKernel()
    {
        BTasks = std::multiset< shared_ptr<BTask> >();
    }

    void add_Task(shared_ptr<BTask> task)
    {
        if (task->initialize()) 
        {
            BTasks.insert(task);
            task->set_kernel(this);
        };
      
    }

    //Aqui está el bucle principal
    void run();

    void execute()
    {
        exit = false;

        for (auto BTask : BTasks)
        {
            BTask->initialize();
        }

        float time = 1.f / 60.f;

        while (!exit)
        {
            BTimer timer;
            timer.start();

            for (auto BTask : BTasks)
            {
                if (exit)
                {
                    break;
                }
                else if (paused)
                {
                    while (paused)
                    {
                        //thread::current_thread().sleep(10);
                    }
                }

                //task->step(time);  // Hacer una barra de carga
            }

            time = timer.elapsed_seconds();
        }

        for (auto BTask : BTasks)
        {
            BTask->finalize();
        }
    }

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

