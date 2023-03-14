# Output
add_library(dynamic_library_loader STATIC 
    dynamic_library_loader.hpp 
    dynamic_library_loader.cpp
)

# Project compilation flags
target_compile_options(dynamic_library_loader PRIVATE -Wall -Wextra -Werror -Wpedantic -g -fPIC)

# Project dependencies
target_include_directories(dynamic_library_loader PRIVATE ../../Core/App/)

# Install lib
install(TARGETS dynamic_library_loader ARCHIVE DESTINATION lib)
