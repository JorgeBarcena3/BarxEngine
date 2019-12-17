#pragma once
#include "BMessage.hpp"

/*
* Clase de que observa el mensaje
*/
class BOrbserver {

public:

    //Obliga a que todo lo que hereda de BOrbserver tenga un mensaje
    virtual void handle(const BMessage & m) = 0;

};