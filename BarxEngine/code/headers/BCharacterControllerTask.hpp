#include "BtypeDef.hpp"
#include "BTask.hpp"

class BEntity;
class BScene;
class BTransformComponent;
class BCharacterControllerComponent;
class BKeyboardComponent;

class BCharacterControllerTask : public BTask
{

public:

    BCharacterControllerTask(shared_ptr<BEntity> transfom, shared_ptr<BCharacterControllerComponent> component);
   
private:

    shared_ptr<BTransformComponent> transform;

    shared_ptr<BCharacterControllerComponent> component;

    shared_ptr<BKeyboardComponent> InputManager;

    bool initialize();

    bool finalize();

    bool execute(float time);

};
