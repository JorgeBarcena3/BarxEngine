// Author: Jorge Bárcena Lumbreras

// © Copyright (C) 2020  Jorge Bárcena Lumbreras

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

#ifndef BULLETDEMO
#define BULLETDEMO

#include "LateralMovemementPlattfom.hpp"
#include <BEngine.hpp>
#include "Player.hpp"

class BulletDemo
{

public:

    static BulletDemo& getInstance()
    {
        static BulletDemo scene;

        return scene;
    }

    static void entityToCenter(DemoEntity* entity, float time);


private:

    BScene * scene;

    std::vector<DemoEntity * > entities;

    DemoEntity* player;

    bool endingScene = false;

public:

    BulletDemo();

    ~BulletDemo();

    void start();

    inline Player* getPlayer()
    {
        return (Player*)player;
    };

    void endScene();

    const bool isEndScene() { return endingScene; };


private:

    void startSceneFunction(BScene* scene);

};
#endif