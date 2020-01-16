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

shared_ptr<BEntity> player;
BAudio audio;
Id collisionID;

void playerControlFunction(float time, shared_ptr<BEntity> entity)
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

    //shared_ptr<BTransform_Component> comp = entity->getTransform();
    //comp->rotation.y = 0.001;

    //player->getTransform()->position.x += 0.001f;
}

void EnemyControlFunction(float time, shared_ptr<BEntity> entity)
{
    auto transform = entity->getTransform();

    vec3<float> direction;
    direction.setValues(
        transform->position.x - player->getTransform()->position.x,
        transform->position.y - player->getTransform()->position.y,
        transform->position.z - player->getTransform()->position.z
    );

    direction.normalize();

    transform->position.x -= direction.x * 0.002f;
    transform->position.y -= direction.y * 0.002f;
    transform->position.z -= direction.z * 0.002f;

}

void OnCollision(shared_ptr<BEntity> A, shared_ptr<BEntity> B)
{

    if (A->getId() == "Player" && B->getId().find("Enemy") != std::string::npos)
    {
        audio.makeSound(collisionID);
    }

};

int main() {

    BScene* scene = new BScene("../../assets/scene/scene.xml");

    player = scene->getEntity("Player");
    player->getComponent<BColliderComponent>()->setFunction(OnCollision);

    scene->getEntity("Enemy1")->getComponent<BControlComponent>()->setFunction(EnemyControlFunction);
    scene->getEntity("Enemy1")->getComponent<BColliderComponent>()->setFunction(OnCollision);

    scene->getEntity("Enemy2")->getComponent<BControlComponent>()->setFunction(EnemyControlFunction);
    scene->getEntity("Enemy2")->getComponent<BColliderComponent>()->setFunction(OnCollision);

    scene->getEntity("Enemy3")->getComponent<BControlComponent>()->setFunction(EnemyControlFunction);
    scene->getEntity("Enemy3")->getComponent<BColliderComponent>()->setFunction(OnCollision);

    scene->getEntity("Enemy4")->getComponent<BControlComponent>()->setFunction(EnemyControlFunction);
    scene->getEntity("Enemy4")->getComponent<BColliderComponent>()->setFunction(OnCollision);

    collisionID = audio.loadSound("assets\\sfx\\collision.wav");

    scene->run();

    return 0;

}