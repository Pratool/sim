cmake_minimum_required(VERSION 3.10)

project(ExternalProjects)

include(ExternalProject)

set(SIM_EXTERNAL_UNSAFE_RPATH 0 CACHE BOOL
    "Use relative RPATHs that may reference libraries outside install tree"
)
if(SIM_EXTERNAL_UNSAFE_RPATH)
    # Relative RPATHs permit relocatable external library installations.
    set(SIM_EXTERNAL_RPATH "$ORIGIN/../lib;$ORIGIN/../../lib")
else()
    # Absolute RPATHs provide greater assurance that an unintended library is not dynamically loaded.
    set(SIM_EXTERNAL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
endif()

externalproject_add(SimbodyExternalProject
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/simbody
    URL "https://github.com/simbody/simbody/archive/Simbody-3.7.tar.gz"
    URL_HASH SHA256=d371a92d440991400cb8e8e2473277a75307abb916e5aabc14194bea841b804a
    DOWNLOAD_NO_PROGRESS ON
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
        -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_INSTALL_PREFIX}
        -DCMAKE_INSTALL_RPATH:PATH=${SIM_EXTERNAL_RPATH}
)
