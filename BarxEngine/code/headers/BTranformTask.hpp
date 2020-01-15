#pragma once
#include "BtypeDef.hpp"

class BTask;
class BTransform_Component;

class BTransform_task : public BTask
{

public:

    BTransform_task(string id, shared_ptr< BTransform_Component > transformComponent);

private:

    shared_ptr< BTransform_Component > transform;

    bool initialize();

    bool finalize();

    bool execute(float time);

};