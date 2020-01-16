#include "..//headers/BComponent.hpp"
#include "..//headers/BMainWindowComponent.hpp"
#include "..//headers/BWindowTask.hpp"

BMainWindowComponent::BMainWindowComponent(shared_ptr<BEntity> parent, string windowName , int w, int h, bool fs) : BComponent(parent)
{
    task = shared_ptr<BWindowTask>(new BWindowTask(windowName, w, h, fs));

}

bool BMainWindowComponent::initialize()
{
    return false;
}
