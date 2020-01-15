#include "BtypeDef.hpp"
#include "BTask.hpp"

class BWindowTask;

class BRenderTask : public BTask
{  

    // Se crea un puntero a Render_Node porque al usar una declaraci�n adelantada
    // para no exportar dependencias con esta cabecera, solo se pueden definir
    // punteros o referencias a los tipos declarados de modo adelantado.
    shared_ptr< glt::Render_Node > renderer;

    shared_ptr< BWindowTask> window;

public:

    static shared_ptr< BRenderTask > instance;

    BRenderTask(shared_ptr< BWindowTask > given_window);

    /** En este caso es necesario definir expl�citamente el destructor en el archivo
      * de implementaci�n (CPP) para que el compilador pueda destruir el Render_Node.
      * Si se deja que el compilador cree un destructor por defecto en el programa
      * que use el engine, como solo tendr� una declaraci�n adelantada, no sabr� c�mo
      * destruirlo y ello dar� lugar a un error de compilaci�n.
      */
    ~BRenderTask();

    void render();

    shared_ptr< glt::Render_Node > getRenderer();

    shared_ptr< BWindowTask> getWindow();

    virtual bool initialize();

    virtual bool finalize();

    virtual bool execute(float time);



};