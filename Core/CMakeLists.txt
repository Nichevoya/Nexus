# Configuration
set(APP "./App")
set(COMMAND "./Components/Command")
set(ENVIRONMENT "./Components/Environment")
set(INTERFACE "./Interface")
set(PLUGIN_LOADER "./Components/Plugin Loader")
set(DYNAMIC_LIBRARY_LOADER "${CMAKE_SOURCE_DIR}/Library/Dynamic Library Loader")

# Source
set(HEADER
    ${APP}/ressource.hpp
    ${APP}/nexus.hpp
    ${COMMAND}/command.hpp
    ${ENVIRONMENT}/environment.hpp
    ${INTERFACE}/graphic.hpp
    ${INTERFACE}/logic.hpp
    ${PLUGIN_LOADER}/plugin.hpp
)

set(SOURCE
    ${APP}/ressource.cpp
    ${APP}/main.cpp
    ${APP}/nexus.cpp
    ${COMMAND}/command.cpp
    ${ENVIRONMENT}/environment.cpp
    ${PLUGIN_LOADER}/plugin.cpp
)

# Output
add_library(nexus STATIC SHARED 
    ${HEADER}
    ${SOURCE}
)

target_link_libraries(nexus 
    ${CMAKE_DL_LIBS}
    "${CMAKE_SOURCE_DIR}/build/Library/Dynamic Library Loader/libdynamic_library_loader.a"
)

add_executable(nexus.app 
    ${HEADER}
    ${SOURCE}
)

target_link_libraries(nexus.app nexus)

target_include_directories(nexus PRIVATE 
    ${APP} 
    ${COMMAND}
    ${ENVIRONMENT}
    ${INTERFACE} 
    ${PLUGIN_LOADER}
    ${DYNAMIC_LIBRARY_LOADER}
)

target_include_directories(nexus.app PRIVATE 
    ${APP} 
    ${COMMAND}
    ${ENVIRONMENT}
    ${INTERFACE} 
    ${PLUGIN_LOADER}
    ${DYNAMIC_LIBRARY_LOADER}
)

# Install project
install(FILES ${HEADER} DESTINATION include)
install(TARGETS nexus ARCHIVE DESTINATION lib)
install(TARGETS nexus.app RUNTIME DESTINATION bin)
