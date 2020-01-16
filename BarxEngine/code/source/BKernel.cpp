#include "..\headers\BKernel.hpp"
#include "..\headers\BSystem.hpp"
#include "..\headers\BTask.hpp"


void BKernel::add_Task(shared_ptr<BTask> task)
{
    if (task->initialize())
    {
        BTasks.insert(task);
        task->set_kernel(this);
    };

}


void BKernel::run()
{

    exit = false; 

    for (auto task : BTasks)
    {
        task->initialize();
    }

    float time = 1.f / 60.f;

    do 
    {
        BTimer timer;

        for (auto task : BTasks)
        {
            if (!task->execute(time))
                exit = true;
        }

        time = timer.timeDeltatime();
        

    } while (!exit);

    for (auto task : BTasks)
    {
        task->finalize();
    }

}
