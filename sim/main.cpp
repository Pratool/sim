#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "OGRE-based simulator" << std::endl;
    std::cout << "  number of command-line arguments: " << argc;
    for (int i = 0; i < argc; ++i)
    {
        std::cout << " - " << argv[i] << std::endl;
    }

    return 0;
}
