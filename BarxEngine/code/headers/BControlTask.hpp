#include "BtypeDef.hpp"
#include "BTask.hpp"

class BEntity;

class BControlTask : public BTask
{

public:

    BControlTask(shared_ptr<BEntity> entityReference);

    shared_ptr<BEntity> entityReference;

    std::function<void(float, shared_ptr<BEntity>)> myFunction;


private:

    bool initialize();

    bool finalize();

    bool execute(float time);

};
