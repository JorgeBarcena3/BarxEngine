#pragma once
#include "BtypeDef.hpp"
#include "BEntity.hpp"

/*
* Es un codigo que se ejecuta teniendo en cuenta todos los componentes especificos
* Ejemplo el systema de fisicas
* Es mas especifico
*/
class BScene {

    map<Id, BEntity*> entities;

};