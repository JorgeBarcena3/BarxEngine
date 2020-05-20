#include "LateralMovemementPlattfom.hpp"
#include "BulletDemo.hpp"

void LateralMovemementPlattfom::update(float time, shared_ptr<BEntity> entity)
{
    if (BulletDemo::getInstance().isEndScene())
    {
        BulletDemo::entityToCenter(this, time);
        return;
    }

    physicsComponent->setGravity({0,0,0});
    physicsComponent->setLinearVelocity({0,0,0});

    if (currentDirection == DIRECTION::LEFT)
        physicsComponent->setLinearVelocity(vec3<float>(-speed, 0, 0));
    else
        physicsComponent->setLinearVelocity(vec3<float>(speed, 0, 0));

}

void LateralMovemementPlattfom::onCollision(BEntity* me, BEntity* other)
{
    if (other->getId() == "Floor 1")
    {
        currentDirection = DIRECTION::RIGHT;
    }        
    else if (other->getId() == "Floor 2")
    {
        currentDirection = DIRECTION::LEFT;
    }

}

void LateralMovemementPlattfom::start(BScene* scene)
{

    cout << "Lateral movement Plattform start" << endl;

    speed = 0.5;

    currentDirection = DIRECTION::LEFT;

    entity = (scene->getEntity("MovementPlatform Floor"));

    physicsComponent = entity->getComponent<BPhysicsCompmponent>();

    entity->getComponent<BControlComponent>()->setFunction([this](float time, shared_ptr<BEntity> entity) { update(time, entity);  });

    entity->getComponent<BColliderComponent>()->setFunction([this](BEntity* me, BEntity* other) { onCollision(me, other);  });


}
