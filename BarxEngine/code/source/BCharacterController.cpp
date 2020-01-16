#include "..\headers\BtypeDef.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BCharacterController.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTask.hpp"
#include "..\headers\BObserver.hpp"
#include "..\headers\BScene.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BCharacterControllerTask.hpp"

BCharacterControllerComponent::BCharacterControllerComponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
    task = shared_ptr<BCharacterControllerTask>(new BCharacterControllerTask(parent, shared_ptr<BCharacterControllerComponent>(this)));
}

bool BCharacterControllerComponent::initialize()
{
    return true;
}

