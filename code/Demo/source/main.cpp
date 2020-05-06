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
#include "../../BEngine/headers/BKeyboardComponent.hpp"


BScene* scene;
shared_ptr< BKeyboardComponent            > InputManager; ///< ImputManager para manejar los eventos



void ballControl(float time, shared_ptr<BEntity> entity)
{
    auto physics = entity->getComponent<BPhysicsCompmponent>();

    if (InputManager->Keyboard->isKeyPresed("F"))
        physics->addForce(vec3<float>(0, 3, 0), vec3<float>(0, -1, 0));

}

int main() {

    scene = new BScene("resources/animacion.xml");

    ////////////// PLAYER ////////////// 

    //player = scene->getEntity("Player");
    //player->getComponent<BColliderComponent>()->setFunction(OnCollision);

    //////////////// CAMERA ////////////// 

    //scene->getEntity("Camera")->getComponent<BControlComponent>()->setFunction(cameraControlFunction);

    //cameraPlayerDistance = vec3<float>(
    //    scene->getEntity("Camera")->getTransform()->position.x - player->getTransform()->position.x,
    //    scene->getEntity("Camera")->getTransform()->position.y - player->getTransform()->position.y,
    //    scene->getEntity("Camera")->getTransform()->position.z - player->getTransform()->position.z        
    //    );

    ////////////////  PROPS ////////////// 

    //scene->getEntity("Wall1")->getComponent<BColliderComponent>()->setFunction(OnCollision);
    //scene->getEntity("Wall2")->getComponent<BColliderComponent>()->setFunction(OnCollision);
    //scene->getEntity("Wall3")->getComponent<BColliderComponent>()->setFunction(OnCollision);
    //scene->getEntity("Wall4")->getComponent<BColliderComponent>()->setFunction(OnCollision);

    ////////////////  ENEMIES ////////////// 

    //scene->getEntity("Enemy1")->getComponent<BControlComponent>()->setFunction(EnemyControlFunction);
    //scene->getEntity("Enemy1")->getComponent<BColliderComponent>()->setFunction(OnCollision);

    //scene->getEntity("Enemy2")->getComponent<BControlComponent>()->setFunction(EnemyControlFunction);
    //scene->getEntity("Enemy2")->getComponent<BColliderComponent>()->setFunction(OnCollision);

    //scene->getEntity("Enemy3")->getComponent<BControlComponent>()->setFunction(EnemyControlFunction);
    //scene->getEntity("Enemy3")->getComponent<BColliderComponent>()->setFunction(OnCollision);

    scene->getEntity("Ball")->getComponent<BControlComponent>()->setFunction(ballControl);
    InputManager = scene->getRootEntity()->getComponent< BKeyboardComponent  >();
    //scene->getEntity("Enemy4")->getComponent<BColliderComponent>()->setFunction(OnCollision);


    //////////////// AUDIO ////////////// 

    //collisionID = audio.loadSound("../../../binaries/assets/sfx/collision.wav");

    scene->run();

    return 0;

}