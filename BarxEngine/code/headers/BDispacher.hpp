// File: BDispacher.hpp
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

#ifndef BARX_ENGINE_BDISPACHER
#define BARX_ENGINE_BDISPACHER
#include "BtypeDef.hpp"

/*
* Clases adelantadas
*/
class BOrbserver;
class BMessage;

/*
* Es un singleton
* Se encarga de repartir los mensajes
*/
class BDispacher {

public:
    
    /*
    * Devuelve una instancia del dispacher
    */
    static shared_ptr<BDispacher> instance();

private:

    /*
    * Instancia del dispacher
    */
    static shared_ptr< BDispacher > _instance;

    /*
    * Lista de observadores subscritos
    */
    map<string, list<BOrbserver*>> observers;

public:

    /*
    * Añadimos un observador a la lista
    */
    void add(BOrbserver& o, string id);
    
    /*
    * Enviamos los mensajes a traves de los observadores
    */
    void Send(BMessage& m);   

};
#endif