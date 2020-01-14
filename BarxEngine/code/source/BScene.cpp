#include "..\headers\BScene.hpp"
#include "../headers/BComponent.hpp"
#include "../headers/BKernel.hpp"
#include "../headers/BEntity.hpp"

BScene::BScene(const string& scene_description_file_path)
{

    entities = new Entity_Map();

    kernel = new BKernel();

    load(scene_description_file_path);

    init_kernel();

    run();
}

void BScene::load(const string& scene_description_file_path)
{

    shared_ptr<BEntity> entity = shared_ptr< BEntity>(new BEntity());

    //RAPID XML

   /* shared_ptr< BComponent> componente = shared_ptr< BTransform_Component >(new BTransform_Component(entity));

    entity->add_component("physics", componente);*/

    (*entities)["Objeto1"] = entity;


}

void BScene::init_kernel()
{

    //HAY QUE AÑADIR LA VENTANA
    shared_ptr<BWindow_Task> windowTask = shared_ptr<BWindow_Task>(new BWindow_Task());
    kernel->add_Task(windowTask);
    //HAY QUE AÑADIR EL INPUT

    for (auto entity : *entities)
    {
        auto components = (*entity.second).getComponents();

        for (auto comp : components)
        {
            shared_ptr<BTask> task = comp->getTask();
            kernel->add_Task(task);
        }

    }
}

void BScene::run()
{
    kernel->run();
}
