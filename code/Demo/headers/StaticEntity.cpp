#include "StaticEntity.hpp"
#include "BulletDemo.hpp"

StaticEntity::StaticEntity(std::string _name)
{
    name = _name;
}

void StaticEntity::start(BScene* scene)
{
    cout << name + " start" << endl;

    entity = (scene->getEntity(name));

    physicsComponent = entity->getComponent<BPhysicsCompmponent>();

    entity->getComponent<BControlComponent>()->setFunction([this](float time, shared_ptr<BEntity> entity) { update(time, entity);  });

    entity->getComponent<BColliderComponent>()->setFunction([this](BEntity* me, BEntity* other) { onCollision(me, other);  });
}

void StaticEntity::update(float time, shared_ptr<BEntity> entity)
{
    if (BulletDemo::getInstance().isEndScene())
    {
        BulletDemo::entityToCenter(this, time);
        return;
    }
}

void StaticEntity::onCollision(BEntity* me, BEntity* other)
{
}
