# Configuration
set(CORE ${CMAKE_SOURCE_DIR}/Core)

# Output
add_library(raylibs SHARED 
    raylib.hpp
    raylib.cpp
)

# Project compilation flags
target_compile_options(raylibs PRIVATE -Wall -Wextra -Werror -Wpedantic -g)

# Project library linking flag
target_link_libraries(
    raylibs
    -lraylib
)

target_include_directories(raylibs PRIVATE 
    ${CORE}/App/
    ${CORE}/Interface/
)

# Install project
install(TARGETS raylibs ARCHIVE DESTINATION Plugin)
