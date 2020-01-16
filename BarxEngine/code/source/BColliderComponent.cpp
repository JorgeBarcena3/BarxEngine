#include "..\headers\BComponent.hpp"
#include "..\headers\BColliderComponent.hpp"
#include "..\headers\BColliderTask.hpp"
#include "..\headers\BEntity.hpp"

BColliderComponent::BColliderComponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
    task = shared_ptr<BColliderTask>(new BColliderTask(parent,  parent->getScene()));
    radius = 1;
}

void BColliderComponent::setFunction(std::function<void(shared_ptr<BEntity>, shared_ptr<BEntity>)> myFunction)
{
    auto colliderComponet = dynamic_pointer_cast<BColliderTask>(task);
    colliderComponet->onCollision = myFunction;
}
