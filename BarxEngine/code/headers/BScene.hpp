// File: BScene.hpp
// Author: Jorge Bárcena Lumbreras

// © Copyright (C) 2019  Jorge Bárcena Lumbreras

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
//
#pragma once

#include "BtypeDef.hpp"
#include "BEntity.hpp"
#include "BDispacher.hpp"

class BModule;
class BKernel;

/*
* Es un codigo que se ejecuta teniendo en cuenta todos los componentes especificos
* Ejemplo el systema de fisicas
* Es mas especifico
*/
class BScene
{
    //typedef map< string, shared_ptr< BModule > > FModule_Map;
    typedef map< string, shared_ptr< BEntity > > Entity_Map;


    Entity_Map* entities;
    BKernel* kernel;
    shared_ptr< BEntity> root;

public:

    /*
    * Constructor de la escena
    */
    BScene(const string& scene_description_file_path = "");

    shared_ptr < BEntity > getEntity(string id);


private:

    /*
    * Cargamos una escena desde un archivo xml
    */
    void load(const string& scene_description_file_path);

    /*
    * Inicializa un kernel
    */
    void init_kernel();

public:

    /*
    * Aqui se halla el bucle principal
    */
    void run();

    template <class T>
    list<shared_ptr<BEntity>> entitesWithComponent()
    {
        list<shared_ptr<BEntity>> list;

        for (auto entity : *entities)
        {
            shared_ptr< T > component = (*entity.second).getComponent< T >();

            if (component != nullptr)
            {
                list.push_back( (*entities)[entity.first]);
            }
        }

        return list;
    }

     shared_ptr< BDispacher > getDispacher() {

        return BDispacher::instance() ;

    }
};


