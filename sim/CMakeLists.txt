cmake_minimum_required(VERSION 3.2)

add_executable(simulator
    main.cpp)

target_link_libraries(simulator
    PUBLIC
        OGRE::OGRE)

install(TARGETS simulator
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
