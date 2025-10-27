cmake_minimum_required(VERSION 3.22)
project(Engine LANGUAGES CXX)

if (NOT WIN32)
    message(FATAL_ERROR "This project is only supported on Windows.")
endif()

# Compile Once
if(NOT TARGET Engine)
    set(SOURCE_FILES
        src/Core/Application.cpp
        src/Core/Log.cpp
        src/Platform/Windows/WindowsWindow.cpp
        src/Core/Layer.cpp
        src/Core/LayerStack.cpp
    )

    set(INCLUDE_DIRS
        include
    )

    set(SUB_PROJECTS
        vendor/spdlog
        vendor/glfw
    )

    set(LIB_NAMES
        spdlog
        glfw
        opengl32
    )

    # Compile Project
    message(STATUS "Creating Project '${PROJECT_NAME}'")

    # Options : SHARED , STATIC
    set(PROJECT_TYPE SHARED CACHE STRING "Library type (SHARED/STATIC)")

    message(STATUS "Compiling source files '${SOURCE_FILES}' in '${PROJECT_NAME}'")
    add_library(${PROJECT_NAME} ${PROJECT_TYPE} ${SOURCE_FILES})

    # Precompiled Headers
    message(STATUS "Setting up precompiled header 'gepch.h' for '${PROJECT_NAME}'")
    target_precompile_headers(${PROJECT_NAME} PRIVATE include/gepch.h)

    if(WIN32)
        target_compile_definitions(${PROJECT_NAME} PRIVATE GE_PLATFORM_WINDOWS)
    endif()
    
    if(${PROJECT_TYPE} STREQUAL "SHARED")
        target_compile_definitions(${PROJECT_NAME} PRIVATE GE_BUILD_DLL)
    endif()

    target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:GE_ENABLE_ASSERTS>)

    # Include Directories
    message(STATUS "Including directories '${INCLUDE_DIRS}' in '${PROJECT_NAME}'")
    target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})

    # Add Dependencies
    foreach(PROJECT IN LISTS SUB_PROJECTS)
        if(NOT TARGET ${PROJECT})
            get_filename_component(SUBPROJECT_NAME ${PROJECT} NAME)
            message(STATUS "Adding subproject '${SUBPROJECT_NAME}' to '${PROJECT_NAME}'")
            add_subdirectory(${PROJECT} ${CMAKE_BINARY_DIR}/${SUBPROJECT_NAME})
        endif()
    endforeach()

    # Link Libraries
    message(STATUS "Linking libraries '${LIB_NAMES}' to '${PROJECT_NAME}'")
    target_link_libraries(${PROJECT_NAME} ${LIB_NAMES})
endif()
