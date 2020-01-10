#pragma once
#include "BtypeDef.hpp"
#include "BComponent.hpp"

/*
* Es la unidad basica del motor
* Una entidad es todo lo que hay en el motor
* Pero como nos diferenciamos entre gamobject, sistemas de particulas...?
* Los componentes otorgan caracteristicas a la entidad (Componente de fisicas, de rederizacion de imagenes, de IA...)
*/
class BEntity
{

    //BTransform_Component transform;

    map< string, shared_ptr< BComponent > > components;

public:

    bool initialize()
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

    bool add_component
    (
        const string& type,
        shared_ptr< BComponent >& component
    )
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

};
