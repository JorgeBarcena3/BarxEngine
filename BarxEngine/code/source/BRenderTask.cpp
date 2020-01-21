// File: BRenderTask.cpp
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

#include "..\headers\BTask.hpp"
#include "..\headers\BtypeDef.hpp"
#include "..\headers\BRenderTask.hpp"
#include "..\headers\BWindowTask.hpp"
#include <Cube.hpp>
#include <Model.hpp>
#include <Light.hpp>
#include <Render_Node.hpp>

using namespace glt;

shared_ptr< BRenderTask > BRenderTask::instance = nullptr;

BRenderTask::BRenderTask(shared_ptr< BWindowTask > given_window) : BTask(TASKPRIORITY::RENDERGENERAL)
{
    window = given_window;

    BRenderTask::instance = shared_ptr< BRenderTask >(this);

    renderer.reset(new glt::Render_Node);

}

BRenderTask::~BRenderTask()
{
}

void BRenderTask::render()
{
    // Se ajusta el viewport por si el tamaño de la ventana ha cambiado:

    GLsizei width = GLsizei(window->getWidth());
    GLsizei height = GLsizei(window->getHeight());

    renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

    glViewport(0, 0, width, height);

    // Se renderiza la escena y se intercambian los buffers de la ventana para
    // hacer visible lo que se ha renderizado:

    window->clear();

    renderer->render();

    window->swapBuffers();
}

std::shared_ptr<glt::Render_Node> BRenderTask::getRenderer()
{
    return renderer;
}

shared_ptr<BWindowTask> BRenderTask::getWindow()
{
    return window;
}

bool BRenderTask::initialize()
{   

    return true;
}

bool BRenderTask::finalize()
{
    return true;
}

bool BRenderTask::execute(float time)
{
    auto renderer = instance->getRenderer();

    auto window = instance->getWindow();

    GLsizei width = GLsizei(window->getWidth());
    GLsizei height = GLsizei(window->getHeight());

    renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

    glViewport(0, 0, width, height);

    // Se rota el objeto:
    window->swapBuffers();

    // Se renderiza la escena y se intercambian los buffers de la ventana para
    // hacer visible lo que se ha renderizado:

    window->clear();

    renderer->render();

    return true;
}
