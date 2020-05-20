#include "Key.hpp"
#include "BulletDemo.hpp"


void Key::update(float time, shared_ptr<BEntity> entity)
{

    static float rot = 0.1f;

    entity->getTransform()->rotation.x += rot;
}

void Key::onCollision(BEntity* me, BEntity* other)
{
    if (other->getId() == "Player")
    {
        cout << "Getting key..." << endl;
        me->removeEntity();
        BulletDemo::getInstance().getPlayer()->getKey();
    }

}


void Key::start(BScene* scene)
{
    cout << "Key start" << endl;

    entity = (scene->getEntity("Key"));

    physicsComponent = entity->getComponent<BPhysicsCompmponent>();

    entity->getComponent<BControlComponent>()->setFunction([this](float time, shared_ptr<BEntity> entity) { update(time, entity);  });

    entity->getComponent<BColliderComponent>()->setFunction([this](BEntity* me, BEntity* other) { onCollision(me, other);  });


}

