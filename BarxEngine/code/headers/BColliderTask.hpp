#include "BtypeDef.hpp"
#include "BTask.hpp"

class BEntity;
class BScene;

class BColliderTask : public BTask
{

public:

    BColliderTask(shared_ptr<BEntity> transfom, shared_ptr<BScene> scene);

    shared_ptr<BEntity> entity;

    shared_ptr<BScene> scene;

    std::function<void(shared_ptr<BEntity>, shared_ptr<BEntity>)> onCollision;


private:

    shared_ptr<BTransform_Component> transform;

    list < shared_ptr<BEntity> > colliderEntites;

    bool initialize();

    bool finalize();

    bool execute(float time);

};
