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

#ifndef BARX_ENGINE_BSCENE
#define BARX_ENGINE_BSCENE

#include "BtypeDef.hpp"
#include "BEntity.hpp"
#include "BDispacher.hpp"

/*
* Clases adelantadas
*/
class BModule;
class BKernel;
class BKeyboard;
class BkeyboardComponent;

/*
* Clase escena que se ejecuta en funcion de las entidades que posee
*/
class BScene
{
    typedef map< string, shared_ptr< BEntity > > Entity_Map ; ///< Tipo de dato que guarda las entidades que hay en la escena
    shared_ptr< Entity_Map >                     entities   ; ///< Entidades que hay en la escena
    shared_ptr< BKernel    >                     kernel     ; ///< Kernel de la escena
    shared_ptr< BEntity    >                     root       ; ///< Entidad root de la escena


public:

    /*
    * Constructor de la escena
    */
    BScene(const string& scene_description_file_path = "");

    /*
    * Devuelve una entidad por ID
    */
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
    * Inicia el bucle run del kernel
    */
    void run();

    /*
    * Recarga la escena (TODO)
    */
    void reloadScene(const string& scene_description_file_path);

    /*
    * Devuelve las entidades que tienen N componentes
    */
    template <class T>
    list<shared_ptr<BEntity>> entitesWithComponent()
    {
        list<shared_ptr<BEntity>> list;

        for (auto entity : *entities)
        {
            shared_ptr< T > component = (*entity.second).getComponent< T >();

            if (component != nullptr)
            {
                list.push_back((*entities)[entity.first]);
            }
        }

        return list;
    }

    /*
    * Devuelve el dispacher
    */
    shared_ptr< BDispacher > getDispacher();

    /*
    * Devuelve la entidad root de la escena
    */
    shared_ptr<BEntity> getRootEntity();

    /*
    * Devuelve el keyboard manager
    */
    shared_ptr<BKeyboard> getKeyBoardManager();

};
#endif