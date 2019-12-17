#include "BEngine.hpp"
#include <iostream>


int main() {


    ////BScene s;
    ////s.exec(); --> Se va a ejecutar el kernel
    ////Para probar creamos una clase que hereda de Escena. Se añaden las entidades a la clase de entidades.
    ////Ir poniendo console.log para ver si se esta ejecutando todo
    ////Se van a necesitar solamente un componente grafico, y un sistema de render que será una tarea.
    ////Un componente de control, un script que manipula la entidad
    ////Sistema de update. Se recorren toda la lista de entidades y pedirle un puntero al componente que buscan
    ////El transformComponent importante

    BWindow window ("Test", 600, 600);

    BAudio audio;

    Id id = audio.loadMusic("test.ogg");

    audio.startMusic(id);

    std::getchar();

    return 0;

}