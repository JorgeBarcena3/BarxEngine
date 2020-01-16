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

BRenderTask::BRenderTask(shared_ptr< BWindowTask > given_window)
{
    window = given_window;

    BRenderTask::instance = shared_ptr< BRenderTask >(this);

    // Se crea el render node de OpenGL Toolkit:

    renderer.reset(new glt::Render_Node);

    // Se crean los elementos básicos necesarios para dibujar un cubo:

    shared_ptr< Camera > camera(new Camera(20.f, 1.f, 50.f, 1.f));
    shared_ptr< Light  > light(new Light);

    // Es necesario añadir las mallas a los modelos antes de añadir los modelos a la escena:


    // Se añaden los nodos a la escena:

    renderer->add("camera", camera);
    renderer->add("light", light);

    // Se configuran algunas propiedades de transformación:

    renderer->get("camera")->translate(Vector3(0.f, 1.f, 5.f));
    //renderer->get("camera")->rotate_around_x(-0.8);
    renderer->get("light")->translate(Vector3(10.f, 10.f, 10.f));
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
