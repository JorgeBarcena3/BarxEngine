#pragma once
#include "BtypeDef.hpp"
#include "BComponent.hpp"

class BEntity;

enum COLLIDERTYPE {
    SPHERE = 0,
    BOX = 1
};

class BColliderComponent : public BComponent
{
    
protected:

    COLLIDERTYPE type;

public:

    BColliderComponent(shared_ptr <BEntity> parent);

    void setFunction(std::function<void(shared_ptr<BEntity>, shared_ptr<BEntity>)> myFunction);

    virtual bool initialize() = 0;

    virtual bool parse_property(const string& name, const string& value) = 0;

    virtual shared_ptr<BEntity> checkCollisions(shared_ptr<BEntity> other) = 0;

    COLLIDERTYPE getType() {
        return type;
    }
   
};
