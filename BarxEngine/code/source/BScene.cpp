#include "..//headers/BScene.hpp"
#include "../headers/BComponent.hpp"
#include "../headers/BKernel.hpp"
#include "../headers/BEntity.hpp"
#include "../headers/BWindowTask.hpp"
#include "../headers/BRenderTask.hpp"

BScene::BScene(const string& scene_description_file_path)
{

    entities = new Entity_Map();

    kernel = new BKernel();

    //Creamos las tareas principales
    shared_ptr<BTask> windowTask = shared_ptr<BWindowTask>(new BWindowTask("Barx Engine Tool", 1200, 800));
    shared_ptr<BTask> RenderTask = shared_ptr<BRenderTask>(new BRenderTask(BWindowTask::instance));

    load(scene_description_file_path);

    init_kernel();

    run();
}

void BScene::load(const string& scene_description_file_path)
{ 


    //Luego pasamos a los mas especificos

    shared_ptr<BEntity> entity = shared_ptr< BEntity>(new BEntity("Conejo1"));

    shared_ptr<BComponent> renderComponent = shared_ptr<BRenderComponent>(new BRenderComponent(entity, BRenderTask::instance, "../../../assets/head.obj"));

    entity->add_component("renderer", renderComponent);

    (*entities)[entity->getId()] = entity;


}

void BScene::init_kernel()
{
    kernel->add_Task(BWindowTask::instance);

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

    kernel->add_Task(BRenderTask::instance);


}

void BScene::run()
{
    kernel->run();
}
