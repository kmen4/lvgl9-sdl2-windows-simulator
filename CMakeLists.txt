# Minimum CMake version required for this project
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(lvgl_sim_940 C)

# Use C99 for the simulator
set(CMAKE_C_STANDARD 99)

# Add LVGL as a subdirectory so it builds as part of this project.
# LVGL generates its own Visual Studio project (lvgl.vcxproj).
add_subdirectory(lvgl)

# Path to the precompiled SDL2 development package (Visual Studio version)
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/SDL2-devel-2.32.10-VC/SDL2-2.32.10")

# Make SDL2 headers available to *this* project (sim).
# Note: LVGL ignores external include paths and uses its own internal include tree.
include_directories(
    ${SDL2_DIR}/include
)

# Link directory for SDL2 libraries (SDL2.lib, SDL2main.lib)
link_directories(
    ${SDL2_DIR}/lib/x64
)

# Build the simulator executable
add_executable(sim
    main.c
)

# Link the simulator against LVGL and SDL2
target_link_libraries(sim
    lvgl
    SDL2
    SDL2main
)

# After building, copy SDL2.dll next to sim.exe so it can run without manual steps
add_custom_command(TARGET sim POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_DIR}/lib/x64/SDL2.dll"
        $<TARGET_FILE_DIR:sim>
)
