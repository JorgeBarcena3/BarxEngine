#include "..\headers\BKernel.hpp"

void BKernel::run()
{

    exit = false; 

    do 
    {

        for (auto task : BTasks)
        {
            if (!task->run((float)deltaTime.elapsed_milliseconds()))
                exit = true;
        }


    } while (!exit);

    for (auto task : BTasks)
    {
        task->finalize();
    }

}
