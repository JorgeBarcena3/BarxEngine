#include "..//headers/BScene.hpp"
#include "../headers/BComponent.hpp"
#include "../headers/BRenderObjectComponent.hpp"
#include "../headers/BKernel.hpp"
#include "../headers/BEntity.hpp"
#include "../headers/BWindowTask.hpp"
#include "../headers/BRenderTask.hpp"
#include "../headers/BMainRenderer.hpp"
#include "../headers/BMainWindowComponent.hpp"


BScene::BScene(const string& scene_description_file_path)
{

    entities = new Entity_Map();

    kernel = new BKernel();

    load(scene_description_file_path);

    init_kernel();

}

void BScene::load(const string& scene_description_file_path)
{ 

    //Creamos la entidad root
    root = shared_ptr< BEntity>(new BEntity("MainScene"));

    shared_ptr<BComponent> windowComponent = shared_ptr<BMainWindowComponent>(new BMainWindowComponent(root));
    shared_ptr<BComponent> mainRenderComponent = shared_ptr<BMainRenderer>(new BMainRenderer(root));

    root->add_component("mainRenderComponent", mainRenderComponent);
    root->add_component("windowComponent", windowComponent);


    //Luego pasamos a los mas especificos

    shared_ptr<BEntity> entity = shared_ptr< BEntity>(new BEntity("Conejo1"));

    shared_ptr<BComponent> renderComponent = shared_ptr<BRenderObjectComponent>(new BRenderObjectComponent(entity, "../../../assets/head.obj"));

    entity->add_component("RendererObject", renderComponent);

    (*entities)[entity->getId()] = entity;


}

void BScene::init_kernel()
{
    kernel->add_Task(root->getComponent<BMainWindowComponent>()->getTask());

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

    kernel->add_Task(root->getComponent<BMainRenderer>()->getTask());


}

void BScene::run()
{
    kernel->run();
}
