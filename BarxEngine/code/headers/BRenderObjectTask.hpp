#include "BtypeDef.hpp"

class BTask;
class BRenderTask;
class BTransformComponent;

class BRenderObjectTask : public BTask
{

public:

    BRenderObjectTask(string id, shared_ptr< BRenderTask > instance, shared_ptr< BTransformComponent > transformComponent);

private:


    shared_ptr< BRenderTask > instance;

    shared_ptr< BTransformComponent > transform;

    bool initialize();

    bool finalize();

    bool execute(float time);

};
