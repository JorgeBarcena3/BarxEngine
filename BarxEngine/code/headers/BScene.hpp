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

class BModule;
class BEntity;
class BKernel;
class BSystem;

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
};
