# CMake dependencies
cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configuration
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules/)

# System lib
# include(InstallRequiredSystemLibraries)
# set(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP TRUE)
# install(PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION mydir)

# find_package(X11 REQUIRED)
find_package(udev REQUIRED)
find_package(sfml REQUIRED)
find_package(vorbis REQUIRED)

project(Nexus)

add_library(nexus STATIC main.cpp)

add_executable(nexus.app main.cpp)
target_link_libraries(nexus.app nexus sfml-graphics)

# Install project
install(TARGETS nexus)
install(TARGETS nexus.app RUNTIME DESTINATION bin)
install(TARGETS nexus ARCHIVE DESTINATION lib)
install(FILES main.hpp DESTINATION include)

# CPack config
set(CPACK_PACKAGE_NAME "Nexus")
set(CPACK_PACKAGE_VENDOR "CMake.org")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Nexus - CPack Component Installation Example")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "CPack Component Example")

# CPack
include(CPack)
