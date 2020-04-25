cmake_minimum_required(VERSION 3.2)

find_package(OGRE 2.1 REQUIRED)

add_executable(simulator
    main.cpp)

target_link_libraries(simulator
    PUBLIC
        ${OGRE_LIBRARIES})

install(TARGETS simulator
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
