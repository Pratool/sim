cmake_minimum_required(VERSION 3.2)

find_package(OGRE 2.1 REQUIRED)

# OGRE does not use target-based CMake, so let's make one.
add_library(OGRE::OGRE INTERFACE IMPORTED GLOBAL)
target_include_directories(OGRE::OGRE INTERFACE ${OGRE_INCLUDE_DIRS})

# Assume OGRE is built in Release mode unless otherwise specified.
option(OGRE_DEBUG_MODE "Indicates if OGRE was compiled in debug mode." OFF)
set_target_properties(OGRE::OGRE PROPERTIES
    INTERFACE_COMPILE_OPTIONS "-DOGRE_DEBUG_MODE=${OGRE_DEBUG_MODE}")
