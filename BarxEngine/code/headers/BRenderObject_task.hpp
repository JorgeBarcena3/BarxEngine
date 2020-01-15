#include "BtypeDef.hpp"

class BTask;
class BRenderTask;
class BTransform_Component;

class BRenderObject_Task : public BTask
{

public:

    BRenderObject_Task(string id, shared_ptr< BRenderTask > instance, shared_ptr< BTransform_Component > transformComponent);

private:


    shared_ptr< BRenderTask > instance;

    shared_ptr< BTransform_Component > transform;

    bool initialize();

    bool finalize();

    bool execute(float time);

};
