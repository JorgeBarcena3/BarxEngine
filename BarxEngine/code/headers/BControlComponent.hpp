#pragma once
#include "BtypeDef.hpp"

class BControlComponent : public BComponent
{
   

public:

    BControlComponent(shared_ptr <BEntity> parent);

    void setFunction(std::function<void(float, shared_ptr<BEntity>)> myFunction);

    // Inherited via BComponent
    virtual bool initialize() override;

    virtual bool parse_property(const string& name, const string& value) override;

};
