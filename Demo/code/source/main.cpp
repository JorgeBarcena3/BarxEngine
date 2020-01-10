// File: main.cpp
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

#include "BEngine.hpp"
#include <iostream>
#include "BScene.hpp"

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

    Id id = audio.loadMusic("media\\testogg.ogg");
    //Id id2 = audio.loadMusic("media\\testmp3.mp3");
    Id id3 = audio.loadSound("media\\testwaw.wav");

 /*   std::getchar();
    audio.makeSound(id);
    std::getchar();*/

    const std::string path = "CASA";
	std::cout << id << endl << id3;
    std::getchar();

    BScene * scene = new BScene();
  
    return 0;

}