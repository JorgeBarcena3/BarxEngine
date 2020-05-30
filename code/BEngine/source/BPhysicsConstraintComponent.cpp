#include "..\headers\BPhysicsConstraintComponent.hpp"
#include "..\headers\BMainPhysicsComponent.hpp"
#include "..\headers\BPhysicsComponent.hpp"
#include "..\headers\BEntity.hpp"
#include "..\headers\BScene.hpp"
#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>


BPhysicsConstraintComponent::BPhysicsConstraintComponent(shared_ptr<BEntity> parent) : BComponent(parent, COMPONENT_INITIALIZATION::CONSTRAINT_PHYSICS_COMPONENT)
{
}

bool BPhysicsConstraintComponent::initialize()
{

    initialiced = !(A == nullptr || B == nullptr);

    if (initialiced)
    {
        const btVector3 btPivotA(pivotA[0], pivotA[1], pivotA[2]);
        const btVector3 btPivotB(pivotB[0], pivotB[1], pivotB[2]);
        btVector3 btAxisA(axisA[0], axisA[1], axisA[2]);
        btVector3 btAxisB(axisB[0], axisB[1], axisB[2]);

        physicsHingeConstraint = shared_ptr<btHingeConstraint>(new btHingeConstraint(
            *A->getPhysicalBody(),
            *B->getPhysicalBody(),
            btPivotA,
            btPivotB,
            btAxisA,
            btAxisB,
            false
        ));

        physicsHingeConstraint->setLimit(-SIMD_PI * 0.25f, SIMD_PI * 0.25f);
        //physicsHingeConstraint->
        //eneableMotor(false);
        eneableAngularMotor(false);
        setVelocity(0);

        BMainPhysicsComponent::instance->dynamicsWorld->addConstraint(physicsHingeConstraint.get(), false);

        BMainPhysicsComponent::instance->constraints.push_back(physicsHingeConstraint);

    }

    return true;
}

bool BPhysicsConstraintComponent::parse_property(const string& name, const string& value)
{
    if (name == "A")
    {
        auto entity = parent->getScene()->getEntity(value);

        if (entity)
        {
            A = entity->getComponent<BPhysicsCompmponent>();
        }
    }
    if (name == "B")
    {
        auto entity = parent->getScene()->getEntity(value);

        if (entity)
        {
            B = entity->getComponent<BPhysicsCompmponent>();
        }
    }
    if (name == "AxisA")
    {
        std::stringstream test(value);
        std::string segment;
        std::vector<std::string> seglist;

        while (std::getline(test, segment, ','))
        {
            seglist.push_back(segment);
        }

        axisA = vec3<float>((float)atof(seglist[0].c_str()), (float)atof(seglist[1].c_str()), (float)atof(seglist[2].c_str()));
    }
    if (name == "AxisB")
    {
        std::stringstream test(value);
        std::string segment;
        std::vector<std::string> seglist;

        while (std::getline(test, segment, ','))
        {
            seglist.push_back(segment);
        }

        axisB = vec3<float>((float)atof(seglist[0].c_str()), (float)atof(seglist[1].c_str()), (float)atof(seglist[2].c_str()));
    }
    if (name == "PivotA")
    {
        std::stringstream test(value);
        std::string segment;
        std::vector<std::string> seglist;

        while (std::getline(test, segment, ','))
        {
            seglist.push_back(segment);
        }

        pivotA = vec3<float>((float)atof(seglist[0].c_str()), (float)atof(seglist[1].c_str()), (float)atof(seglist[2].c_str()));
    }
    if (name == "PivotB")
    {
        std::stringstream test(value);
        std::string segment;
        std::vector<std::string> seglist;

        while (std::getline(test, segment, ','))
        {
            seglist.push_back(segment);
        }

        pivotB = vec3<float>((float)atof(seglist[0].c_str()), (float)atof(seglist[1].c_str()), (float)atof(seglist[2].c_str()));
    }

    return true;
}

void BPhysicsConstraintComponent::eneableMotor(bool eneable)
{
    if (initialiced)
    {
        physicsHingeConstraint->enableMotor(eneable);
    }
}

void BPhysicsConstraintComponent::eneableAngularMotor(bool eneable)
{
    physicsHingeConstraint->enableAngularMotor(eneable, 500.f, 1000.f);
}

void BPhysicsConstraintComponent::setVelocity(float speed)
{
    physicsHingeConstraint->setMotorTargetVelocity(speed);
}
