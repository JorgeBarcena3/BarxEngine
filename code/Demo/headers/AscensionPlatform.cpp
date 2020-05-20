#include "AscensionPlatform.hpp"
#include "BulletDemo.hpp"

void AscensionPlatform::update(float time, shared_ptr<BEntity> entity)
{
    if (BulletDemo::getInstance().isEndScene())
    {
        BulletDemo::entityToCenter(this, time);
        return;
    }

    auto position = entity->getTransform()->position;

    if (isPlayer && position.y < limitYUp)
    {

        physicsComponent->setLinearVelocity(vec3<float>(0, speed, 0));

    }
    else if (position.y > limitYDown)
    {
        physicsComponent->setLinearVelocity(vec3<float>(0, -speed, 0));

    }
    else
    {
        physicsComponent->setLinearVelocity(vec3<float>(0, 0, 0));

    }

    isPlayer = false;

}

void AscensionPlatform::onCollision(BEntity* me, BEntity* other)
{
    if (other->getId() == "Player")
    {
        isPlayer = true;
    }
}

void AscensionPlatform::start(BScene* scene)
{
    cout << "Ascension Plattform start" << endl;

    speed = 0.5;

    limitYUp = -1.75;

    limitYDown = -4;

    isPlayer = false;

    entity = (scene->getEntity("ElevatorPlatform Floor"));

    physicsComponent = entity->getComponent<BPhysicsCompmponent>();

    entity->getComponent<BControlComponent>()->setFunction([this](float time, shared_ptr<BEntity> entity) { update(time, entity);  });

    entity->getComponent<BColliderComponent>()->setFunction([this](BEntity* me, BEntity* other) { onCollision(me, other);  });
}
