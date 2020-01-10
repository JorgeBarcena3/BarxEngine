#pragma once
#include "BtypeDef.hpp"
#include "BVariant.hpp"

/*
* Clase que se encarga de manejar los mensajes
*/
struct BMessage
{

    string id;

    map< string, BVariant > parameters;

    BMessage(const string& id) : id(id)
    {
    }

    void add_parameter(const string& name, const BVariant& value)
    {
        parameters[name] = value;
    }

    const string getId() {
        return id;
    }

};

////////////////////////////////////////////////////////////////////////////////////////////////////

//BMessage key_pressed("key_pressed");
//BVariant key_code();
//key_pressed.add_parameter("key_code", key_code);
//
//message_handler.multicast(key_pressed);


