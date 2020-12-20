cmake_minimum_required(VERSION 3.2)

add_executable(simulator
    main.cpp)

install(TARGETS simulator
    EXPORT SimTargets
    RUNTIME DESTINATION bin)
