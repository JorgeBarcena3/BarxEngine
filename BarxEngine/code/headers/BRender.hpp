#include "BtypeDef.hpp"
#include "BSystem.hpp"

class BWindow;

class BRender : public BSystem
{  

    // Se crea un puntero a Render_Node porque al usar una declaración adelantada
    // para no exportar dependencias con esta cabecera, solo se pueden definir
    // punteros o referencias a los tipos declarados de modo adelantado.
    shared_ptr< glt::Render_Node > renderer;

    shared_ptr< BWindow> window;

public:

    static shared_ptr< BRender > instance;

    BRender(shared_ptr< BWindow > given_window);

    /** En este caso es necesario definir explícitamente el destructor en el archivo
      * de implementación (CPP) para que el compilador pueda destruir el Render_Node.
      * Si se deja que el compilador cree un destructor por defecto en el programa
      * que use el engine, como solo tendrá una declaración adelantada, no sabrá cómo
      * destruirlo y ello dará lugar a un error de compilación.
      */
    ~BRender();

    void render();

    shared_ptr< glt::Render_Node > getRenderer();

    shared_ptr< BWindow> getWindow();

    virtual bool initialize() override;

    virtual bool finalize() override;

    virtual bool execute(float time) override;

};