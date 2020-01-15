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

void BKernel::add_system(shared_ptr<BSystem> system)
{
    BSystems.insert(system);
}

void BKernel::run()
{

    exit = false; 

    for (auto task : BTasks)
    {
        task->initialize();
    }

    do 
    {

        for (auto task : BTasks)
        {
            if (!task->run((float)deltaTime.elapsed_milliseconds()))
                exit = true;
        }

        for (auto system : BSystems)
        {
            if (!system->execute((float)deltaTime.elapsed_milliseconds()))
                exit = true;
        }


    } while (!exit);

    for (auto task : BTasks)
    {
        task->finalize();
    }

}
