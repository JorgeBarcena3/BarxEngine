#include "..//headers/BComponent.hpp"
#include "..//headers/BControlComponent.hpp"
#include "..//headers/BControlTask.hpp"

BControlComponent::BControlComponent(shared_ptr <BEntity> parent) : BComponent(parent)
{
     task = shared_ptr<BControlTask>(new BControlTask(parent));
}

void BControlComponent::setFunction(std::function<void(float, shared_ptr<BEntity>)> _myFunction)
{
    auto controlComponent = dynamic_pointer_cast<BControlTask>(task);
    controlComponent->myFunction = _myFunction;
}

bool BControlComponent::initialize()
{
    return false;
}
bool BControlComponent::parse_property(const string& name, const string& value)
{
    return false;
}
;