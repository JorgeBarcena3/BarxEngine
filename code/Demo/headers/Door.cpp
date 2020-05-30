#include "Door.hpp"
#include "BulletDemo.hpp"



void Door::update(float time, shared_ptr<BEntity> entity)
{
    if (BulletDemo::getInstance().getScene()->getKeyBoardManager()->isKeyPresed("R"))
    {
        cout << "PERMITIENDO TODO..." << endl;
        constraintComponent->eneableMotor(true);
        constraintComponent->setVelocity(200);
        constraintComponent->eneableAngularMotor(true);

    }
}

void Door::onCollision(BEntity* me, BEntity* other)
{

}

void Door::start(BScene* scene)
{
    cout << "Door start" << endl;

    A = (scene->getEntity("Puerta"));
    B = (scene->getEntity("Pivote Puerta"));

    constraintComponent = (scene->getEntity("zconstraintEntity")->getComponent<BPhysicsConstraintComponent>());

    constraintComponent->getEntity()->getComponent<BControlComponent>()->setFunction([this](float time, shared_ptr<BEntity> entity) { update(time, entity);  });

}
