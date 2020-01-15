
#include "../headers/BComponent.hpp"
#include "../headers/BControl_Component.hpp"

BControl_Component::BControl_Component(shared_ptr <BEntity> parent) : BComponent(parent)
{
    // task = shared_ptr<BTransform_task>(new BTransform_task());
};