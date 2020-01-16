#include "..\headers\BKernel.hpp"
#include "..\headers\BSystem.hpp"
#include "..\headers\BTask.hpp"


void BKernel::add_Task(shared_ptr<BTask> task)
{

    if (task != nullptr)
    {
        BTasks.insert(task);
        task->set_kernel(this);
    }

}


void BKernel::run()
{

    exit = false;

    //Ordenamos las task por orden de preferemcia

    for (auto task : BTasks)
    {
        task->initialize();
    }

    float time = 1.f / 60.f;

    BTimer timer;

    int now = timer.elapsed_milliseconds();
    int lastFrame = timer.elapsed_milliseconds();
    int TimeToSleep = (1000 / 60) / 1000;

    do
    {
        now = timer.elapsed_milliseconds();
        float delta = now - lastFrame;
        lastFrame = now;
        
        //Limitamos a 60 el numero de FPS
        if (delta < TimeToSleep)
        {
            std::this_thread::sleep_for(std::chrono::seconds(TimeToSleep));
        }

      

        for (auto task : BTasks)
        {
            if (!task->execute(time))
                exit = true;
        }

        time = timer.elapsed_milliseconds();
        

    } while (!exit);

    for (auto task : BTasks)
    {
        task->finalize();
    }

}
