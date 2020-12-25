cmake_minimum_required(VERSION 3.2)

find_package(Simbody REQUIRED)

add_executable(simulator
    main.cpp
)

target_link_libraries(simulator
    ${Simbody_LIBRARIES}
)

set_target_properties(simulator PROPERTIES
    INSTALL_RPATH "${SIM_RPATH}"
    #INSTALL_RPATH "$ORIGIN/../lib;${SIM_EXTERNAL_RPATH}"
    #INSTALL_RPATH "${SIM_EXTERNAL_RPATH}"
)

install(TARGETS simulator
    EXPORT SimTargets
    RUNTIME DESTINATION bin
)
