/**
 * \file sim/main.cpp
 *
 * Starts the main application.
 *
 **/

// external library headers
#include <OgreImage.h>

// standard template library headers
#include <iostream>


int main(int argc, char** argv)
{
    std::cout << "OGRE-based simulator" << std::endl;
    std::cout << "  number of command-line arguments: " << argc;
    for (int i = 0; i < argc; ++i)
    {
        std::cout << " - " << argv[i] << std::endl;
    }

    std::cout << "Quick test to determine if libOGRE linked properly." << std::endl;

    Ogre::Box a{2, 3, 4, 5};
    std::cout << "depth: " << a.getDepth() << std::endl;
    std::cout << "height: " << a.getHeight() << std::endl;
    std::cout << "width: " << a.getWidth() << std::endl;

    return 0;
}
