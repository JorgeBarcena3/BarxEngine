#include "..\headers\BEntity.hpp"
#include "../headers/BComponent.hpp"
#include "..//headers/BtypeDef.hpp"
#include "..//headers/BTransformComponent.hpp"

BEntity::BEntity(string _id)
{
    id = _id;

    components = map< string, shared_ptr< BComponent > >();

    transform = shared_ptr<BTransform_Component>(new BTransform_Component(shared_ptr<BEntity>(this)));

    add_component("Transform", transform);
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

shared_ptr<BTransform_Component> BEntity::getTransform()
{
    return dynamic_pointer_cast<BTransform_Component>(transform);
}

bool BEntity::add_component(const string& type, shared_ptr<BComponent>& component)
{
   
    if (components.count(type) != 0)
    {
        return false;
    }
    else
    {
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
