#include "..\headers\BComponent.hpp"
#include "..\headers\BCameraComponent.hpp"
#include "..\headers\BRenderTask.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTransformComponent.hpp"
#include <Camera.hpp>
#include <Render_Node.hpp>

BCameraComponent::BCameraComponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
    fov = 20.f;
    near = 1.f;
    far = 50.f;
    aspectRatio = 1.f;
}

bool BCameraComponent::initialize()
{

     camera = shared_ptr< glt::Camera >(new glt::Camera(fov, near,far, aspectRatio));

    BRenderTask::instance->getRenderer()->add(parent->getId(), camera);
    BRenderTask::instance->getRenderer()->get(parent->getId())->translate(Vector3(
        parent->getTransform()->position.x,
        parent->getTransform()->position.y,
        parent->getTransform()->position.z
    ));

    return true;
}
