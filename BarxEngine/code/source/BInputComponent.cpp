#include "..//headers/BComponent.hpp"
#include "..\headers\BInputComponent.hpp"
#include "..//headers/BEntity.hpp"
#include "../headers/BTask.hpp"
#include "../headers/BInputHandlerTask.hpp"
#include "../headers/BControlTask.hpp"

BInputComponent::BInputComponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
    task =  shared_ptr<BMyInputHandlerTask>(new BMyInputHandlerTask(true));
}

bool BInputComponent::initialize()
{
    return false;
}

bool BInputComponent::parse_property(const string& name, const string& value)
{
    return false;
}
