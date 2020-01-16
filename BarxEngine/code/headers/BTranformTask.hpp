#pragma once
#include "BtypeDef.hpp"

class BTask;
class BTransformComponent;

class BTransformTask : public BTask
{

public:

    BTransformTask(string id, shared_ptr< BTransformComponent > transformComponent);

private:

    shared_ptr< BTransformComponent > transform;

    bool initialize();

    bool finalize();

    bool execute(float time);

};