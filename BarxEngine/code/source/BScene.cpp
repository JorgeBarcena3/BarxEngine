#include "..\headers\BScene.hpp"
#include "../headers/BComponent.hpp"
#include "../headers/BKernel.hpp"
#include "../headers/BEntity.hpp"
#include "../headers/BWindow.hpp"
#include "../headers/BRender.hpp"

BScene::BScene(const string& scene_description_file_path)
{

    entities = new Entity_Map();

    kernel = new BKernel();

    //CREAMOS LOS SISTEMAS NECESARIOS
    shared_ptr<list<shared_ptr< BSystem>>> systems(new list<shared_ptr< BSystem>>);

    systems->push_back( shared_ptr<BWindow> (new BWindow("Test", 600, 600) ) );
    systems->push_back( shared_ptr<BRender> (new BRender(BWindow::instance)) );

    load(scene_description_file_path);

    init_kernel(systems);

    run();
}

void BScene::load(const string& scene_description_file_path)
{

    shared_ptr<BEntity> entity = shared_ptr< BEntity>(new BEntity("Conejo1"));

    shared_ptr<BComponent> renderComponent = shared_ptr<BRenderComponent>(new BRenderComponent( entity, BRender::instance, "../../../assets/bunny-lowpoly.obj"));

    entity->add_component("renderer", renderComponent);

    (*entities)["Objeto1"] = entity;


}

void BScene::init_kernel(shared_ptr<list<shared_ptr< BSystem>>> systems)
{

    for (auto entity : *entities)
    {
        (*entity.second).initialize();
        auto components = (*entity.second).getComponents();

        for (auto comp : components)
        {
            shared_ptr<BTask> task = comp->getTask();
            kernel->add_Task(task);
        }

    }

    for (auto system : *systems)
    {
        kernel->add_system(system);
    }
}

void BScene::run()
{
    kernel->run();
}
