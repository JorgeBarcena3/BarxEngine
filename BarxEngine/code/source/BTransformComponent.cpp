#include "../headers/BTask.hpp"
#include "../headers/BComponent.hpp"
#include "../headers/BTransformComponent.hpp"
#include "../headers/BEntity.hpp"
#include "../headers/BTranformTask.hpp"

using namespace glt;

BTransformComponent::BTransformComponent(shared_ptr <BEntity> parent) : BComponent(parent)
{
    task = shared_ptr<BTransformTask>(new BTransformTask(parent->getId(), shared_ptr<BTransformComponent>(this)));
    parent->transform = shared_ptr<BTransformComponent>(this);

    position.x = 0; position.y = 0; position.z = 0;
    rotation.x = 0; rotation.y = 0; rotation.z = 0;
    scale.x = 1; scale.y = 1; scale.z = 1;

};
