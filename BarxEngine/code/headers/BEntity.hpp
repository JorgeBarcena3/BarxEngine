#pragma once
#include "BtypeDef.hpp"
#include "BComponent.hpp"

/*
* Es la unidad basica del motor
* Una entidad es todo lo que hay en el motor
* Pero como nos diferenciamos entre gamobject, sistemas de particulas...?
* Los componentes otorgan caracteristicas a la entidad (Componente de fisicas, de rederizacion de imagenes, de IA...)
*/
class BEntity {

    //Id unico
    Id id;

    //Componentes de las entidades
    map<Id, BComponent*> components;

};