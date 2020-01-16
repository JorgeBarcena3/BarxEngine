#include "..\headers\BtypeDef.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BCharacterController.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTask.hpp"
#include "..\headers\BObserver.hpp"
#include "..\headers\BScene.hpp"
#include "..\headers\BTransformComponent.hpp"

BCharacterController::BCharacterController(shared_ptr<BEntity> parent) : BComponent(parent)
{
    task = shared_ptr<BTask>(nullptr);
    parent->getScene()->getDispacher()->add(*this, "Keyboard"); //Nos subscribimos al evento de keyboard
}

bool BCharacterController::initialize()
{
    return true;
}

void BCharacterController::handle(const BMessage& m)
{

    for (auto param : m.parameters)
    {
        if (param.first == "KeyDown")
        {
            if (param.second == Up)
            {
                parent->getTransform()->position.z -= 0.001f * speed;;
            }
            else  if (param.second == Down)
            {
                parent->getTransform()->position.z += 0.001f * speed;;

            }

            if (param.second == Left)
            {
                parent->getTransform()->position.x -= 0.001f * speed;;

            }
            else  if (param.second == Right)
            {
                parent->getTransform()->position.x += 0.001f * speed;;

            }
        }
    }

}
