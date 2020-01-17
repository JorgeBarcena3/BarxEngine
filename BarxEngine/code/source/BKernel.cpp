#include "..\headers\BKernel.hpp"
#include "..\headers\BSystem.hpp"
#include "..\headers\BTask.hpp"
#include "..\headers\BAlgoritmosDeOrdenacion.hpp"


void BKernel::add_Task(shared_ptr<BTask> task)
{

    if (task != nullptr)
    {
        BTasks.push_back(task);
        task->set_kernel(this);
    }

}


void BKernel::run()
{

    exit = false;

    BAlgoritmosDeOrdenacion::algoritmoBurbuja<shared_ptr<BTask>>(BTasks.data(), BTasks.size());

    for (auto task : BTasks)
    {
        task->initialize();
    }

    float time = 1.f / 60.f;

    BTimer timer;

    int now = timer.elapsed_milliseconds();
    int lastFrame = timer.elapsed_milliseconds();
    long TimeToSleep = (1000 / 60) / 1000;

    do
    {
        now = timer.elapsed_milliseconds();
        int delta = now - lastFrame;
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

        time = (float)timer.elapsed_milliseconds();


    } while (!exit);

    for (auto task : BTasks)
    {
        task->finalize();
    }

}
