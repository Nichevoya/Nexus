# Configuration
set(CORE "${CMAKE_SOURCE_DIR}/Core")
set(FACTORY "./Factory")
set(ENTITY "./Factory/Entity")
set(COMPONENTS "./Factory/Components")
set(SYSTEM "./Factory/System")
set(ENGINE "${CMAKE_SOURCE_DIR}/Core/Engine")

# Output
add_library(hunter SHARED 
    hunter.hpp
    hunter.cpp
    ${ENGINE}/component.hpp
    ${ENGINE}/coordinator.hpp
    ${ENGINE}/entity.hpp
    ${ENGINE}/system.hpp
    ${FACTORY}/abstract.hpp
    ${FACTORY}/construct.hpp
    ${ENTITY}/type.hpp
    ${ENTITY}/target.hpp
    ${COMPONENTS}/force.hpp
    ${COMPONENTS}/position.hpp
    ${COMPONENTS}/transform.hpp
    ${SYSTEM}/movable.hpp
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
    ${ENGINE}/
    ${FACTORY}/
    ${ENTITY}/
    ${COMPONENTS}/
    ${SYSTEM}/
)

# Install project
install(TARGETS hunter ARCHIVE DESTINATION Plugin)
