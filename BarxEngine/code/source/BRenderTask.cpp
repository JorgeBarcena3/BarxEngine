#include "..//headers/BTask.hpp"
#include <Cube.hpp>
#include <Model.hpp>
#include <Light.hpp>
#include <Render_Node.hpp>
#include "..//headers/BtypeDef.hpp"
#include "..//headers/BSystem.hpp"
#include "../headers/BRenderTask.hpp"
#include "../headers/BWindowTask.hpp"

using namespace glt;

shared_ptr< BRenderTask > BRenderTask::instance = nullptr;

BRenderTask::BRenderTask(shared_ptr< BWindowTask > given_window) : BTask(TASKPRIORITY::RENDERGENERAL)
{
    window = given_window;

    BRenderTask::instance = shared_ptr< BRenderTask >(this);

    // Se crea el render node de OpenGL Toolkit:

    renderer.reset(new glt::Render_Node);

};

BRenderTask::~BRenderTask()
{
}

void BRenderTask::render()
{
    // Se ajusta el viewport por si el tamaño de la ventana ha cambiado:

    GLsizei width = GLsizei(window->get_width());
    GLsizei height = GLsizei(window->get_height());

    renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

    glViewport(0, 0, width, height);

    // Se renderiza la escena y se intercambian los buffers de la ventana para
    // hacer visible lo que se ha renderizado:

    window->clear();

    renderer->render();

    window->swap_buffers();
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

    GLsizei width = GLsizei(window->get_width());
    GLsizei height = GLsizei(window->get_height());

    renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

    glViewport(0, 0, width, height);

    // Se rota el objeto:
    window->swap_buffers();

    // Se renderiza la escena y se intercambian los buffers de la ventana para
    // hacer visible lo que se ha renderizado:

    window->clear();

    renderer->render();

    return true;
}
