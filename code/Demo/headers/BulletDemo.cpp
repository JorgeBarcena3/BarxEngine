#include "BulletDemo.hpp"
#include "DemoEntity.hpp"
#include "AscensionPlatform.hpp"

BulletDemo::BulletDemo()
{
    entities.push_back(new LateralMovemementPlattfom());
    entities.push_back(new AscensionPlatform());

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

void BulletDemo::startSceneFunction(BScene* scene)
{   
    for (size_t i = 0; i < entities.size(); i++)
    {
        entities[i]->start(scene);
    }

    cout << "Start";
}
