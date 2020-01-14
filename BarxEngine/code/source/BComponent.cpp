#include "../headers/BTask.hpp"
#include "../headers/BComponent.hpp"

BTransform_Component::BTransform_Component(shared_ptr <BEntity> parent) : BComponent(parent)
{
    task = shared_ptr<BPhysics_task>(new BPhysics_task());
};

BControlComponent::BControlComponent(shared_ptr <BEntity> parent) : BComponent(parent)
{
    task = shared_ptr<BPhysics_task>(new BPhysics_task());
};