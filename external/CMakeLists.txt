cmake_minimum_required(VERSION 3.10)

project(ExternalProjects)

include(ExternalProject)

externalproject_add(SimbodyExternalProject
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/simbody
    URL "https://github.com/simbody/simbody/archive/Simbody-3.7.tar.gz"
    URL_HASH SHA256=d371a92d440991400cb8e8e2473277a75307abb916e5aabc14194bea841b804a
    DOWNLOAD_NO_PROGRESS ON
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
        -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_INSTALL_PREFIX}
)
