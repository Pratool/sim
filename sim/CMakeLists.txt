cmake_minimum_required(VERSION 3.2)

find_package(OGRE 1.12 REQUIRED COMPONENTS Bites Overlay RTShaderSystem)

add_executable(simulator
    main.cpp)

target_link_libraries(simulator
        OgreBites
        OgreMain
        OgreOverlay
        OgreRTShaderSystem)

install(TARGETS simulator
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
