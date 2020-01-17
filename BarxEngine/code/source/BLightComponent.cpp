#include "..\headers\BtypeDef.hpp"
#include "..\headers\BComponent.hpp"
#include "..\headers\BLightComponent.hpp"
#include "..\headers\BRenderTask.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BTransformComponent.hpp"
#include <Camera.hpp>
#include <Render_Node.hpp>
#include <Light.hpp>

BLightComponent::BLightComponent(shared_ptr<BEntity> parent) : BComponent(parent)
{
}

bool BLightComponent::initialize()
{
    // Se crean los elementos básicos necesarios para dibujar un cubo:

    light = shared_ptr< glt::Light >(new glt::Light);

    //shared_ptr< Light  > light(new Light);

    BRenderTask::instance->getRenderer()->add(parent->getId(), light);
    BRenderTask::instance->getRenderer()->get(parent->getId())->translate(Vector3(
        parent->getTransform()->position.x,
        parent->getTransform()->position.y,
        parent->getTransform()->position.z
    ));

    return false;
}
