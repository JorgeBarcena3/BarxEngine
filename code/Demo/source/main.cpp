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


BScene* scene;
shared_ptr< BKeyboardComponent            > InputManager; ///< ImputManager para manejar los eventos



void ballControl(float time, shared_ptr<BEntity> entity)
{

    auto physics = entity->getComponent<BPhysicsCompmponent>();

    if (InputManager->Keyboard->isKeyPresed("F"))
        physics->addForce(vec3<float>(15, 0, 0), vec3<float>(0, 0, 0));

}

void collisionCheck(BEntity * me, BEntity* other)
{
    auto physics = me->getComponent<BPhysicsCompmponent>();
    cout << "trigering";
    other->removeEntity();
    //physics->setLinearVelocity(vec3<float>(0,10,0));
}

int main() {

    scene = new BScene("resources/animacion.xml");

    InputManager = scene->getRootEntity()->getComponent< BKeyboardComponent  >();  

    scene->getEntity("Ball")->getComponent<BControlComponent>()->setFunction(ballControl);
    scene->getEntity("Ball")->getComponent<BColliderComponent>()->setFunction(collisionCheck);

    scene->run();

    return 0;

}