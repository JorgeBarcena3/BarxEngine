#include "..//headers/BComponent.hpp"
#include "..//headers/BMainWindowComponent.hpp"
#include "..//headers/BWindowTask.hpp"

BMainWindowComponent::BMainWindowComponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
    task = shared_ptr<BWindowTask>(new BWindowTask("Barx engine tool", 1200, 800));

}

bool BMainWindowComponent::initialize()
{
    return false;
}
