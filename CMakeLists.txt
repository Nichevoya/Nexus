# CMake dependencies
cmake_minimum_required(VERSION 3.20.5)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configuration
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# Modules
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules/)

project(Nexus)

# System lib
include(InstallRequiredSystemLibraries)
set(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP TRUE)
install(PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION libsys)

# Project dependencies
find_package(X11 REQUIRED)
find_package(udev REQUIRED)
find_package(vorbis REQUIRED)
find_package(sfml REQUIRED)
find_package(raylib REQUIRED)

# Sources
add_subdirectory("./Library/")
add_subdirectory("./Core/")
add_subdirectory("./Module/Graphic/")
add_subdirectory("./Module/Game/")

# CPack config
set(CPACK_PACKAGE_NAME "Nexus")
set(CPACK_PACKAGE_VENDOR "CMake.org")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Nexus - CPack Component Installation")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "CPack Component")

# CPack
include(CPack)
