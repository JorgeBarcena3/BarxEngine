#include "..//headers/BComponent.hpp"
#include "..//headers/BControlComponent.hpp"
#include "..//headers/BControlTask.hpp"

BControlComponent::BControlComponent(shared_ptr <BEntity> parent) : BComponent(parent)
{
     task = shared_ptr<BControlTask>(new BControlTask(parent));
};