# BarxEngine

BarxEngine is a 3D videgoames engine, programmed from scratch in **C++**. I have used the libraries **SDL** and **SLD_Mixer** to create a window and manage the audio. Also I use **OpenGL** to render all the graphics.

# How to use the engine

In order to use the BarxEngine engine, some files must be included in the project configuration. All the files necessary for the use of the library will be found in the “binaries” folder, included in the downloaded package. 

## Instructions to use the engine in Visual Studio 2019

 1. An application project will be created in visual Studio. We will choose the configuration that best suits our project. It is recommended to create an **empty project**.
 
 2. We will create a **.cpp** file (For the project to be configured with the C ++ options), and we will include the files located in “binaries/static libraries/barx-engine/headers/” in the section of “Project properties --> C ++ --> General --> Additional includes directories ”.
 
 3. Now we will include the folder where the **static library** (.lib) of the engine is located, located in “binaries/static libraries/barx-engine/lib/x64 /” in the section of  “Project properties --> Linker --> General --> Additional libraries directories ”.
 
 4. Finally, we must include the .lib file, found in “binaries/librerias estaticas/barx-engine/lib/x64/” in the section of “Project properties --> Linker --> General --> Additional libraries directories”. In this step we will see that there are two files in the “x64” folder, each of these files is precompiled depending on the configuration that will work. The file with the suffix "-d" is compiled in **debug** configuration, and the file with the suffix "-r" is compiled in **release** configuration.
 
5. In order for the project to be executed, the files contained in the **“binaries/librerias dinámicas”** folder must be copied in the directory where the solution of our project is located.

# How to load a scene from a XML
To load a scene we must create an .xml file where the entities that will appear in the scene and the components that each will have will be created. Once this file is loaded, we can execute the scenes by calling the **run()** method of the scene type object. There are some special considerations that we have to consider before a XML file. 

 - All entities must have as a first component a TransformComponent,
                 which will determine in which position of the scene said entity
                 is located.
                 
[Here you can see an example of using a XML file](https://github.com/JorgeBarcena3/BarxEngine/blob/master/binaries/assets/scene/scene.xml)

# Special Components

There are a number of components which we can use from the project we create. Below, we detail what these components are and how we can access them and use them correctly.

## BControlComponent

This component allows to execute a function that we have previously created in our project, during the game update. To assign the function that we want to be executed in the update, we must do it as follows:

    scene->getEntity(Id)->getComponent<BControlComponent>()->setFunction(MyFunction);

In this case, the **“MyFunction”** function must have two parameters:

 - **float time:** Time that has passed since the previous frame.
 - **shared_ptr <BEntity> Entity:** Entity to which that function is
   assigned.

## BColliderComponent
This component allows to execute a function that we have previously created in our project, when the entity that contains it collides with another entity. To assign the function that we want to be executed, we must do it as follows:

    scene->getEntity(Id)->getComponent<BColliderComponent>()->setFunction(MyFunction);

In this case, the “MyFunction” function must have two parameters:

 - **shared_ptr <BEntity> A:** Entity that contains the function
 - **shared_ptr <BEntity> B:** Entity with which the collision was
   generated.
   
# The demo project

In the package there is a demo, which consists of the following features:
1. A scene with a floor and 4 walls is created.
2. A controllable character with the **CharacterControllerComponent**.
3. 4 enemies located in the corners that with the **BControlComponent component**, look for the player and follow him.
4. When a collision is generated between two entities, a warning sound sounds.
5. The camera follows the player all the time.
