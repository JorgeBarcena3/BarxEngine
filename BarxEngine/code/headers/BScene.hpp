#pragma once

#include "BtypeDef.hpp"

#include "BEntity.hpp"
#include "BKernel.hpp"
#include "BPhysicsModule.hpp"
#include "BModule.hpp"


/*
* Es un codigo que se ejecuta teniendo en cuenta todos los componentes especificos
* Ejemplo el systema de fisicas
* Es mas especifico
*/
class BScene
{
    typedef map< string, shared_ptr< BModule > > FModule_Map;
    typedef map< string, shared_ptr< BEntity > > Entity_Map;


    FModule_Map modules;
    BKernel     kernel;
    BEntity     root;

public:

    BScene(const string& scene_description_file_path = "")
    {
        //  load(scene_description_file_path

        shared_ptr< BPhysics_Module::BPhysics_Module_Factory > physicsFactory();

        BModule::FModule_Map& factories = BModule::get_module_map();

        BEntity* entity = new BEntity();

        shared_ptr< BComponent> componente = shared_ptr< BPhysics_Component >(new BPhysics_Component(entity));

        string physicsName = "physics";

        modules["physics"] = factories[physicsName]->create_module();

        entity->add_component("physics", componente);

        init_kernel();
    }

private:

    void load(const string& scene_description_file_path)
    {


        //const BModule::FModule_Map& factories =
        //    BModule::get_module_map();

        //// ...
        //// Parseando entidades:

        //shared_ptr< BEntity > entity(new BEntity);

        // ...
        // Parseando componentes de entidades:

       /* for (auto component : xml_components)
        {
            BModule* module = nullptr;

            if (modules.count(component.type) == 0)
            {
                if (factories.count(component.type) == 0)
                {
                    // FALLAR SI ES CRÍTICO U OMITIRLO
                    // SI NO LO ES
                }
                else
                {
                    modules[component.type] =
                        factories[component.type]->create();

                        module = modules[component.type].get();
                }
            }
            else
            {
                module = modules[component.type].get();
            }

            if (module)
            {
                // INSTANCIAR EL COMPONENTE Y AÑADIRLO A LA ENTIDAD
            }
        }
        */


    }

    void init_kernel()
    {
        for (auto module : modules)
        {
            BTask* task = module.second->get_task();

            if (task)
            {
                kernel.add_Task(*task);
            }
        }
    }

};
