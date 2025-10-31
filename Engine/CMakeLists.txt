project(Engine LANGUAGES CXX)

if(NOT TARGET Engine)
    file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
        src/*.cpp
        include/*.h
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
        glad
        imgui
    )

    foreach(SUB_PROJECT IN LISTS SUB_PROJECTS)
        if(NOT TARGET ${SUB_PROJECT})
            get_filename_component(SUBPROJECT_NAME ${SUB_PROJECT} NAME)
            add_subdirectory(${SUB_PROJECT} ${CMAKE_BINARY_DIR}/${SUBPROJECT_NAME})
        endif()
    endforeach()

    set(GLAD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad")
    file(GLOB GLAD_SOURCES "${GLAD_DIR}/src/*.c")
    add_library(glad STATIC ${GLAD_SOURCES})
    target_include_directories(glad PUBLIC "${GLAD_DIR}/include")

    set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui")
    file(GLOB IMGUI_SOURCES "${IMGUI_DIR}/*.cpp")
    add_library(imgui STATIC ${IMGUI_SOURCES})
    target_include_directories(imgui PUBLIC ${IMGUI_DIR})
    target_link_libraries(imgui PRIVATE glfw)

    function(force_msvc_runtime target)
        if (MSVC)
            set_property(TARGET ${target} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
        endif()
    endfunction()

    force_msvc_runtime(spdlog)
    force_msvc_runtime(glfw)
    force_msvc_runtime(glad)
    force_msvc_runtime(imgui)

    set(PROJECT_TYPE STATIC CACHE STRING "Library type (SHARED/STATIC)")
    add_library(${PROJECT_NAME} ${PROJECT_TYPE} ${SOURCE_FILES})
    target_precompile_headers(${PROJECT_NAME} PRIVATE include/gepch.h)
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        _CRT_SECURE_NO_WARNINGS
        GLFW_INCLUDE_NONE
    )
    if(WIN32)
        target_compile_definitions(${PROJECT_NAME} PRIVATE GE_PLATFORM_WINDOWS)
    endif()
    if(${PROJECT_TYPE} STREQUAL "SHARED")
        target_compile_definitions(${PROJECT_NAME} PRIVATE GE_BUILD_DLL)
    endif()
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:GE_DEBUG>
        $<$<CONFIG:Release>:GE_RELEASE>
    )
    target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})
    add_dependencies(${PROJECT_NAME} ${LIB_NAMES})
    target_link_libraries(${PROJECT_NAME} ${LIB_NAMES})
endif()
