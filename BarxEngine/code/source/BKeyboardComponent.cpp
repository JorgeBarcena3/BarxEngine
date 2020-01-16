#include "..\headers\BComponent.hpp"
#include "..\headers\BKeyboardComponent.hpp"
#include "..\headers\BObserver.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTask.hpp"
#include "..\headers\BScene.hpp"
#include "..\headers\BKeyboard.hpp"

BKeyboardComponent::BKeyboardComponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
    task = shared_ptr<BTask>(nullptr);  
    Keyboard = shared_ptr<BKeyboard>(new BKeyboard());
    parent->getScene()->getDispacher()->add(*this, "Keyboard"); //Nos subscribimos al evento de keyboard
}

bool BKeyboardComponent::initialize()
{
   

    return true;
}

void BKeyboardComponent::handle(const BMessage& m)
{
    for (auto param : m.parameters)
    {
        if (param.first == "KeyDown")
        {
            Keyboard->setKeyDown(param.second);
        }
        else if (param.first == "KeyUp")
        {
            Keyboard->setKeyUp(param.second);
        }
    }
}
