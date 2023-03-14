# Configuration
set(CORE ${CMAKE_SOURCE_DIR}/Core)

# Output
add_library(sfml SHARED 
    sfml.hpp
    sfml.cpp
)

# Project compilation flags
target_compile_options(sfml PRIVATE -Wall -Wextra -Werror -Wpedantic -g)

# Project library linking flag
target_link_libraries(
    sfml
    -lsfml-graphics
    -lsfml-window
    -lsfml-system
    -lsfml-audio 
)

target_include_directories(sfml PRIVATE 
    ${CORE}/App/
    ${CORE}/Interface/
)

# Install project
install(TARGETS sfml ARCHIVE DESTINATION Plugin)
