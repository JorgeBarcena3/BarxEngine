#pragma once
#include "BtypeDef.hpp"
#include "BMessage.hpp"
#include "BObserver.hpp"

/*
* Es un singleton
* Se encarga de repartir los mensajes
* SingleCast / MultiCast (Depende del numero de destinatarios)
*/
class BDispacher {

public:

    //Devuelve una instancia al dispacher
    static BDispacher& instance()
    {
        static BDispacher d;
        return d;
    }

private:

    //Contructores

    map<Id, list<BOrbserver*>> observers;

public:

    // Añadimos un observador a la lista
    void add(BOrbserver& o, Id id)
    {
        observers[id].push_back(&o);
    }

    //Enviamos el mensaje
    void Send(BMessage& m)
    {
        auto list = observers.find(m.getId());

        if (list != observers.end())
        {
            for (auto & o : list->second) //Cogemos el valor del pair
            {
                o->handle(m);
            }
        }
    }
    

};