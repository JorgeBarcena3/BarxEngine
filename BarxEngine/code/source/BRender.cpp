#include "..\headers\BRender.hpp"
#include <Cube.hpp>
#include <Model.hpp>
#include <Light.hpp>
#include <Render_Node.hpp>
#include "..///headers/BWindow.hpp"
#include "..//headers/BtypeDef.hpp"
#include "..//headers/BSystem.hpp"

using namespace glt;

shared_ptr< BRender > BRender::instance = nullptr;

BRender::BRender(shared_ptr< BWindow > given_window)
{
    window = given_window;

    BRender::instance = shared_ptr< BRender >(this);

    // Se crea el render node de OpenGL Toolkit:

    renderer.reset(new glt::Render_Node);

    // Se crean los elementos b�sicos necesarios para dibujar un cubo:

    shared_ptr< Camera > camera(new Camera(20.f, 1.f, 50.f, 1.f));
    shared_ptr< Light  > light(new Light);

    // Es necesario a�adir las mallas a los modelos antes de a�adir los modelos a la escena:


    // Se a�aden los nodos a la escena:

    renderer->add("camera", camera);
    renderer->add("light", light);

    // Se configuran algunas propiedades de transformaci�n:

    renderer->get("camera")->translate(Vector3(0.f, 0.f, 5.f));
    renderer->get("light")->translate(Vector3(10.f, 10.f, 10.f));
};

BRender::~BRender()
{
}

void BRender::render()
{
    // Se ajusta el viewport por si el tama�o de la ventana ha cambiado:

    GLsizei width = GLsizei(window->get_width());
    GLsizei height = GLsizei(window->get_height());

    renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

    glViewport(0, 0, width, height);

    // Se rota el objeto:

    auto cube = renderer->get("cube");

    cube->rotate_around_x(0.01f);
    cube->rotate_around_y(0.02f);
    cube->rotate_around_z(0.03f);

    // Se renderiza la escena y se intercambian los buffers de la ventana para
    // hacer visible lo que se ha renderizado:

    window->clear();

    renderer->render();

    window->swap_buffers();
}

std::shared_ptr<glt::Render_Node> BRender::getRenderer()
{
    return renderer;
}

shared_ptr<BWindow> BRender::getWindow()
{
    return window;
}

bool BRender::initialize()
{
    return false;
}

bool BRender::finalize()
{
    return false;
}

bool BRender::execute(float time)
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
