#include "BtypeDef.hpp"

class BTask;
class BRender;
class BTransform_Component;

class BRender_Task : public BTask
{

public:

    BRender_Task(string id, shared_ptr< BRender > instance, shared_ptr< BTransform_Component > transformComponent);

private:


    shared_ptr< BRender > instance;

    shared_ptr< BTransform_Component > transform;

    bool initialize();

    bool finalize();

    bool run(float time);

};