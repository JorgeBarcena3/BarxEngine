#include "..\headers\BEntity.hpp"
#include "../headers/BComponent.hpp"
#include "..//headers/BtypeDef.hpp"
#include "..//headers/BTransformComponent.hpp"

BEntity::BEntity(string _id, shared_ptr<BScene> _scene)
{
    id = _id;
    scene = _scene;
    components = map< string, shared_ptr< BComponent > >();
  
}

bool BEntity::initialize()
{

    bool result = true;

    for (auto component : components)
    {
        if (component.second->initialize() == false)
        {
            result = false;
        }
    }

    return result;
}

shared_ptr<BTransformComponent> BEntity::getTransform()
{
    return dynamic_pointer_cast<BTransformComponent>(transform);
}

bool BEntity::add_component(const string& type, shared_ptr<BComponent>& component)
{
   
    if (components.count(type) != 0)
    {
        return false;
    }
    else
    {
        //component->initialize();
        components[type] = component;
        return true;
    }

}


list<shared_ptr<BComponent>> BEntity::getComponents()
{
    std::list<shared_ptr<BComponent>> list;

    for (auto component : components) 
    {
        list.push_back(component.second);
    }
    return list;
}
