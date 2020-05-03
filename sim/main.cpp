/**
 * \file sim/main.cpp
 *
 * Starts the main application.
 *
 **/

// external library headers
#include <Ogre.h>
#include <Bites/OgreApplicationContext.h>

// standard template library headers
#include <iostream>


// Taken from the OGRE tutorials page.
// https://ogrecave.github.io/ogre/api/1.12/setup.html
class TestApp : public OgreBites::ApplicationContext, public OgreBites::InputListener
{
public:
    TestApp();
    void setup();
    bool keyPressed(const OgreBites::KeyboardEvent &evt);

private:

};


TestApp::TestApp() : OgreBites::ApplicationContext("OgreTutorialApp")
{
}

bool TestApp::keyPressed(const OgreBites::KeyboardEvent& evt)
{
    if (evt.keysym.sym == OgreBites::SDLK_ESCAPE)
    {
        getRoot()->queueEndRendering();
    }
    return true;
}

void TestApp::setup()
{
    // do not forget to call the base first
    OgreBites::ApplicationContext::setup();

    // register for input events
    addInputListener(this);

    // get a pointer to the already created root
    Ogre::Root* root = getRoot();
    Ogre::SceneManager* scnMgr = root->createSceneManager();

    // register our scene with the RTSS
    Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(scnMgr);

    // without light we would just get a black screen
    Ogre::Light* light = scnMgr->createLight("MainLight");
    Ogre::SceneNode* lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    lightNode->setPosition(0, 10, 15);
    lightNode->attachObject(light);

    // also need to tell where we are
    Ogre::SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    camNode->setPosition(0, 0, 15);
    camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

    // create the camera
    Ogre::Camera* cam = scnMgr->createCamera("myCam");
    cam->setNearClipDistance(5); // specific to this sample
    cam->setAutoAspectRatio(true);
    camNode->attachObject(cam);

    // and tell it to render into the main window
    getRenderWindow()->addViewport(cam);

    // finally something to render
    Ogre::Entity* ent = scnMgr->createEntity("Sinbad.mesh");
    Ogre::SceneNode* node = scnMgr->getRootSceneNode()->createChildSceneNode();
    node->attachObject(ent);
}


int main(int argc, char** argv)
{
    std::cout << "OGRE-based simulator" << std::endl;

    // Use argc and argv to prevent compiler warnings.
    // Will need them later.
    std::cout << "  number of command-line arguments: " << argc;
    for (int i = 0; i < argc; ++i)
    {
        std::cout << " - " << argv[i] << std::endl;
    }

    TestApp app;
    app.initApp();
    app.getRoot()->startRendering();
    app.closeApp();

    return 0;
}
