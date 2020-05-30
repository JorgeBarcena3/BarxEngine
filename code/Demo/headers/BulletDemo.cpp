#include "BulletDemo.hpp"
#include "DemoEntity.hpp"
#include "AscensionPlatform.hpp"
#include "Key.hpp"
#include "Door.hpp"
#include "StaticEntity.hpp"

BulletDemo::BulletDemo()
{

    player = new Player();

    entities.push_back(new StaticEntity("Floor 1"));
    entities.push_back(new StaticEntity("Escalon 1 Floor"));
    entities.push_back(new StaticEntity("Escalon 2 Floor"));
    entities.push_back(new StaticEntity("Escalon 3 Floor"));
    entities.push_back(new StaticEntity("Escalon 4 Floor"));
    entities.push_back(new StaticEntity("Floor 2"));
    entities.push_back(new StaticEntity("Floor 3"));

    entities.push_back(new LateralMovemementPlattfom());
    entities.push_back(new AscensionPlatform());
    entities.push_back(new Key());
    entities.push_back(player);
    //entities.push_back(new Door());

    scene = new BScene("resources/animacion.xml", [this](BScene* scene) { startSceneFunction(scene);  });

}

BulletDemo::~BulletDemo()
{
    for (auto entity : entities)
        delete entity;

    delete scene;
}

void BulletDemo::start()
{
    scene->run();
}

void BulletDemo::endScene()
{
    cout << "Ending scene..." << endl;
    endingScene = true;


    // Desactivamos las fisicas
    for (auto entity : entities)
        entity->getPhysicsComponent()->setActive(false);
}

void BulletDemo::entityToCenter(DemoEntity* entity, float time)
{

    static float currentTime = 0;

    currentTime += time;

    if (currentTime > 10)
    {

        vec3<float> center = { 0,0,-4 };
        float speed = 0.25f;

        vec3<float> pos = entity->getEntity()->getTransform()->position;

        vec3<float> dir = center - pos;
        float lenght = dir.length();

        dir.normalize();

        if (lenght < 0.5)
        {
            BulletDemo::getInstance().entities.erase(std::remove(BulletDemo::getInstance().entities.begin(), BulletDemo::getInstance().entities.end(), entity), BulletDemo::getInstance().entities.end());
            entity->getEntity()->removeEntity();
            return;
        }

        pos = pos + (dir * speed);

        entity->getEntity()->getTransform()->position = pos;
    }
}

void BulletDemo::startSceneFunction(BScene* scene)
{

    endingScene = false;

    for (size_t i = 0; i < entities.size(); i++)
    {
        entities[i]->start(scene);
    }

    cout << "Start";
}
