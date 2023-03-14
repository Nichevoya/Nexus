# Configuration
set(CORE ${CMAKE_SOURCE_DIR}/Core)

# Output
add_library(hunter SHARED 
    hunter.hpp
    hunter.cpp
)

# Project compilation flags
target_compile_options(hunter PRIVATE -Wall -Wextra -Werror -Wpedantic -g)

# Project library linking flag
target_link_libraries(
    hunter
)

target_include_directories(hunter PRIVATE 
    ${CORE}/App/
    ${CORE}/Interface/
)

# Install project
install(TARGETS hunter ARCHIVE DESTINATION Plugin)
