cmake_minimum_required(VERSION 3.22)
project(GameEngine LANGUAGES CXX)

# Set OS Bitness
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OS_BITNESS 64)
else()
    set(OS_BITNESS 32)
endif()

# Set Default Build Type
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type (Debug, Release, RelWithDebInfo, MinSizeRel)" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo" "MinSizeRel")
endif()

# Set Output Directories
macro(set_output_directories BUILD_TYPE FOLDER_NAME)
    set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin/${FOLDER_NAME}-${CMAKE_SYSTEM_NAME}-${OS_BITNESS}-${CMAKE_CXX_COMPILER_ID}")
    message(STATUS "Setting output directory for ${BUILD_TYPE} to ${OUTPUT_DIR}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${BUILD_TYPE} "${OUTPUT_DIR}/${PROJECT_NAME}/lib")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${BUILD_TYPE} "${OUTPUT_DIR}/${PROJECT_NAME}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${BUILD_TYPE} "${OUTPUT_DIR}/${PROJECT_NAME}")
endmacro()

set_output_directories(DEBUG Debug)
set_output_directories(RELEASE Release)
set_output_directories(RELWITHDEBINFO RelWithDebInfo)
set_output_directories(MINSIZEREL MinSizeRel)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler Options
add_compile_options(
    "$<$<CXX_COMPILER_ID:MSVC>:/W4>"
    "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>"
    "$<$<CXX_COMPILER_ID:MSVC>:/wd4251>"
    "$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall>"
    "$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wextra>"
)

# Compile Projects
add_subdirectory(Sandbox)

# Set Startup Project for Visual Studio
set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)
