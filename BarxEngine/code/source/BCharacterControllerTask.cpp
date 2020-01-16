#include "..\headers\BTask.hpp"
#include "..\headers\BCharacterControllerTask.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "../headers/BCharacterController.hpp"
#include "../headers/BKeyboardComponent.hpp"
#include "../headers/BScene.hpp"
#include "../headers/BKeyboard.hpp"

BCharacterControllerTask::BCharacterControllerTask(shared_ptr<BEntity> _entity, shared_ptr<BCharacterControllerComponent> _component)
{
    transform = _entity->getTransform();
    component = _component;
    InputManager = _entity->getScene()->getRootEntity()->getComponent<BKeyboardComponent>();
}

bool BCharacterControllerTask::initialize()
{
    return true;
}

bool BCharacterControllerTask::finalize()
{
    return true;
}

bool BCharacterControllerTask::execute(float time)
{
    if (InputManager->Keyboard->isKeyPresed(component->Up))
    {
        transform->position.z -= 0.001f * component->speed;
    }
    else  if (InputManager->Keyboard->isKeyPresed(component->Down))
    {
        transform->position.z += 0.001f * component->speed;

    }

    if (InputManager->Keyboard->isKeyPresed(component->Left))
    {
        transform->position.x -= 0.001f * component->speed;

    }
    else  if (InputManager->Keyboard->isKeyPresed(component->Right))
    {
        transform->position.x += 0.001f * component->speed;

    }

    return true;
}
