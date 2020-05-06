// File: BScene.cpp
// Author: Jorge B�rcena Lumbreras

// � Copyright (C) 2019  Jorge B�rcena Lumbreras

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "..\headers\BScene.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BTransformComponent.hpp"
#include "..\headers\BRenderObjectComponent.hpp"
#include "..\headers\BColliderComponent.hpp"
#include "..\headers\BControlComponent.hpp"
#include "..\headers\BKernel.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BWindowTask.hpp"
#include "..\headers\BRenderTask.hpp"
#include "..\headers\BMainRenderer.hpp"
#include "..\headers\BMainWindowComponent.hpp"
#include "..\headers\BMainPhysicsComponent.hpp"
#include "..\headers\BInputComponent.hpp"
#include "..\headers\rapidxml.hpp"
#include "..\headers\rapidxml_utils.hpp"
#include "..\headers\BCharacterController.hpp"
#include "..\headers\BKeyboardComponent.hpp"
#include "..\headers\BKeyboard.hpp"
#include "..\headers\BCameraComponent.hpp"
#include "..\headers\BLightComponent.hpp"
#include "..\headers\BShereColliderComponent.hpp"
#include "..\headers\BBoxColliderComponent.hpp"
#include "../headers/BPhysicsComponent.hpp"

BScene::BScene(const string& _scene_description_file_path)
{

    entities = shared_ptr<Entity_Map>(new Entity_Map())                   ;

    kernel   = shared_ptr<BKernel>(new BKernel(shared_ptr<BScene>(this))) ;

    load(_scene_description_file_path)                                    ;

    init_kernel()                                                         ;

}

shared_ptr<BEntity> BScene::getEntity(string id)
{
    return (*entities)[id];
}

void BScene::load(const string& scene_description_file_path)
{
    rapidxml::file<> xmlFile(scene_description_file_path.c_str());
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());

    auto rootNode = doc.first_node();

    if (root == nullptr)
        //Creamos la entidad root
        root = shared_ptr< BEntity>(new BEntity("MainScene", shared_ptr<BScene>(this)));

    shared_ptr<BComponent> windowComponent = shared_ptr<BMainWindowComponent>(new BMainWindowComponent(
        root,
        (
            rootNode->first_attribute("WindowName")->value()),
        stoi(rootNode->first_attribute("windowWidth")->value()),
        stoi(rootNode->first_attribute("windowHeith")->value()),
        stoi(rootNode->first_attribute("fullScreen")->value())
    ));

    shared_ptr<BComponent> mainRenderComponent = shared_ptr<BMainRenderer>(new BMainRenderer(root));
    shared_ptr<BComponent> inputComponent = shared_ptr<BInputComponent>(new BInputComponent(root));
    shared_ptr<BComponent> keyboardComponent = shared_ptr<BKeyboardComponent>(new BKeyboardComponent(root));
    shared_ptr<BComponent> mainPhysicsComponent = shared_ptr<BMainPhysicsComponent>(new BMainPhysicsComponent(root));

    root->addComponent("mainRenderComponent", mainRenderComponent);
    root->addComponent("windowComponent", windowComponent);
    root->addComponent("inputComponent", inputComponent);
    root->addComponent("keyboardComponent", keyboardComponent);
    root->addComponent("mainPhysicsComponent ", mainPhysicsComponent);


    for (rapidxml::xml_node<>* entityNode = rootNode->first_node(); entityNode; entityNode = entityNode->next_sibling()) //Son las entidades
    {
        shared_ptr<BEntity> entity = shared_ptr< BEntity>(new BEntity(entityNode->first_attribute("id")->value(), shared_ptr<BScene>(this)));

        for (rapidxml::xml_node<>* componentNode = entityNode->first_node(); componentNode; componentNode = componentNode->next_sibling()) //Son los componentes
        {
            string typeComponent = componentNode->first_attribute("type")->value();
            shared_ptr<BComponent> currentComponent;

            if (typeComponent == "BTransform_Component")
                currentComponent = shared_ptr<BTransformComponent>(new BTransformComponent(entity));
            else if (typeComponent == "BRenderObjectComponent")
                currentComponent = shared_ptr<BRenderObjectComponent>(new BRenderObjectComponent(entity));
            else if (typeComponent == "BControlComponent")
                currentComponent = shared_ptr<BControlComponent>(new BControlComponent(entity));
            else if (typeComponent == "BShereColliderComponent")
                currentComponent = shared_ptr<BSphereColliderComponent>(new BSphereColliderComponent(entity));
            else if (typeComponent == "BBoxColliderComponent")
                currentComponent = shared_ptr<BBoxColliderComponent>(new BBoxColliderComponent(entity));
            else if (typeComponent == "BCharacterController")
                currentComponent = shared_ptr<BCharacterControllerComponent>(new BCharacterControllerComponent(entity));
            else if (typeComponent == "BCameraComponent")
                currentComponent = shared_ptr<BCameraComponent>(new BCameraComponent(entity));
            else if (typeComponent == "BLightComponent")
                currentComponent = shared_ptr<BLightComponent>(new BLightComponent(entity));
            else if (typeComponent == "BPhysicsCompmponent")
                currentComponent = shared_ptr<BPhysicsCompmponent>(new BPhysicsCompmponent(entity));

            // A�adimos todos los componentes que vayamos creando en el motor

            for (rapidxml::xml_node<>* propertyComponent = componentNode->first_node(); propertyComponent; propertyComponent = propertyComponent->next_sibling()) //Son las propiedades de los componentes
            {
                currentComponent->parse_property(propertyComponent->name(), propertyComponent->value());
            }

            entity->addComponent(typeComponent, currentComponent);

        }

        (*entities)[entity->getId()] = entity;

    }
    
}

void BScene::init_kernel()
{
    kernel->addTask(root->getComponent<BMainWindowComponent>()->getTask());
    kernel->addTask(root->getComponent<BInputComponent>()->getTask());
    kernel->addTask(root->getComponent<BMainPhysicsComponent>()->getTask());

    for (auto entity : *entities)
    {
        (*entity.second).initialize();
        auto components = (*entity.second).getComponents();

        for (auto comp : components)
        {
            shared_ptr<BTask> task = comp->getTask();
            kernel->addTask(task);
        }

    }

    kernel->addTask(root->getComponent<BMainRenderer>()->getTask());
    
}

void BScene::run()
{
    kernel->run();
}

void BScene::reloadScene(const string& scene_description_file_path)
{
    //root.reset(new BEntity("MainScene", shared_ptr<BScene>(this)));

    //kernel.reset(new BKernel(shared_ptr<BScene>( this )));

    //entities.reset(new Entity_Map());

    //load(scene_description_file_path);

    //init_kernel();

    //run();

}

shared_ptr<BDispacher> BScene::getDispacher()
{
    return BDispacher::instance();
}

shared_ptr<BEntity> BScene::getRootEntity()
{
    return root;
}

shared_ptr<BKeyboard> BScene::getKeyBoardManager()
{
    return getRootEntity()->getComponent<BKeyboardComponent>()->Keyboard;
}
