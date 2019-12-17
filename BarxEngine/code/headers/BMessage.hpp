#pragma once
#include "BtypeDef.hpp"


/*
* Clase que se encarga de manejar los mensajes
*/
class BMessage
{

private:

    //Id unico del mensaje
    Id id;

    //Parametros del mensaje en cuestion
    Params params;


public:

    //Sobrecarga del operador [] que devuelve el variant asignado a una id
    BVariant& operator[](Id id)
    {
        return params[id];
    }

public:

    //Devuelve el Id
    Id getId() { return id; };


};

