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

#include <BEngine.hpp>


void controlFunction(float time, shared_ptr<BEntity> entity)
{
    /*if (Input::getKeyDown(BKeyboard::keyMapper.A))
    {
        shared_ptr<BTransform_Component> comp = entity->getTransform();
        comp->position.x -= 0.001; 

    }
    else if (Input::getKeyDown(BKeyboard::keyMapper.W))
    {
        shared_ptr<BTransform_Component> comp = entity->getTransform();
        comp->position.y += 0.001;

    }
    else if (Input::getKeyDown(BKeyboard::keyMapper.S))
    {
        shared_ptr<BTransform_Component> comp = entity->getTransform();
        comp->position.y -= 0.001;
    }
    else if (Input::getKeyDown(BKeyboard::keyMapper.D))
    {
        shared_ptr<BTransform_Component> comp = entity->getTransform();
        comp->position.x += 0.001;

    }
*/
  
    shared_ptr<BTransform_Component> comp = entity->getTransform();
    comp->rotation.y += 0.000001;

}

int main() {


    ////BScene s;
    ////s.exec(); --> Se va a ejecutar el kernel
    ////Para probar creamos una clase que hereda de Escena. Se añaden las entidades a la clase de entidades.
    ////Ir poniendo console.log para ver si se esta ejecutando todo
    ////Se van a necesitar solamente un componente grafico, y un sistema de render que será una tarea.
    ////Un componente de control, un script que manipula la entidad
    ////Sistema de update. Se recorren toda la lista de entidades y pedirle un puntero al componente que buscan
    ////El transformComponent importante

    //BWindowTask window ("Test", 600, 600);

    BScene* scene = new BScene();

    scene->getEntity("Objeto")->getComponent<BControlComponent>()->setFunction(controlFunction);

    scene->run();

    return 0;

}