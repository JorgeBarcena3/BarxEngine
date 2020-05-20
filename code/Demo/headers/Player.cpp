#include "Player.hpp"
#include "BulletDemo.hpp"


void Player::update(float time, shared_ptr<BEntity> entity)
{
    if (BulletDemo::getInstance().isEndScene())
    {
        BulletDemo::entityToCenter(this, time);
        return;
    }
}

void Player::onCollision(BEntity* me, BEntity* other)
{

    auto vel = physicsComponent->getLinearVelocity();
    bool parado = ( physicsComponent->getLinearVelocity().x == 0 ) && (physicsComponent->getLinearVelocity().y == 0) && (physicsComponent->getLinearVelocity().z == 0);

    if (other->getId() == "Floor 3" && hasKey && !BulletDemo::getInstance().isEndScene())
    {
        BulletDemo::getInstance().endScene();
    }
}

void Player::start(BScene* scene)
{
    cout << "Player start" << endl;

    entity = (scene->getEntity("Player"));

    hasKey = false;

    physicsComponent = entity->getComponent<BPhysicsCompmponent>();

    entity->getComponent<BControlComponent>()->setFunction([this](float time, shared_ptr<BEntity> entity) { update(time, entity);  });

    entity->getComponent<BColliderComponent>()->setFunction([this](BEntity* me, BEntity* other) { onCollision(me, other);  });

}

