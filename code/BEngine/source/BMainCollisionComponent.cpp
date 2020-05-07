#include "../headers/BComponent.hpp"
#include "../headers/BMainCollisionComponent.hpp"
#include "../headers/BEntity.hpp"
#include "../headers/BMainCollisionTask.hpp"

BMainCollisionComponent::BMainCollisionComponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
    collisionFrecuency = 0;
    task = shared_ptr<BMainCollisionTask>(new BMainCollisionTask(parent->getId(), shared_ptr<BMainCollisionComponent>(this)));
}

BMainCollisionComponent::~BMainCollisionComponent()
{
}

bool BMainCollisionComponent::initialize()
{
    return false;
}

bool BMainCollisionComponent::parse_property(const string& name, const string& value)
{
    return false;
}
