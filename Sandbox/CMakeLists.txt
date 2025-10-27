cmake_minimum_required(VERSION 3.22)
project(Sandbox LANGUAGES CXX)

if(NOT TARGET Sandbox)
    set(ENGINE_DIR "${CMAKE_SOURCE_DIR}/Engine")

    set(SOURCE_FILES
        src/Sandbox.cpp
    )

    set(INCLUDE_DIRS
        include
    )

    set(SUB_PROJECTS
        ${ENGINE_DIR}
    )

    set(LIB_NAMES
        Engine
    )

    # Compile Project
    message(STATUS "Creating Project '${PROJECT_NAME}'")

    message(STATUS "Compiling source files '${SOURCE_FILES}' in '${PROJECT_NAME}'")
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})

    if(WIN32)
        target_compile_definitions(${PROJECT_NAME} PRIVATE GE_PLATFORM_WINDOWS)
    endif()

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

    message(STATUS "Linking libraries '${LIB_NAMES}' to '${PROJECT_NAME}'")
    add_dependencies(${PROJECT_NAME} ${LIB_NAMES})
    target_link_libraries(${PROJECT_NAME} ${LIB_NAMES})

    # Copy Engine Library to Output Directory
    if(BUILD_SHARED_LIBS OR PROJECT_TYPE STREQUAL "SHARED")
        add_custom_command(
            TARGET ${PROJECT_NAME}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "$<TARGET_FILE:Engine>"
                    "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
            COMMENT "Copying Engine library to '${PROJECT_NAME}'"
        )
    endif()
endif()