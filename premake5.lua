workspace "GameEngine"
    architecture "x86_64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}-%{_ACTION}"

    group "Dependencies"
        include "vendor/premake/dependencies"
        include "vendor/premake/glfw"
    group ""

    group "Engine"
        include "vendor/premake/Engine"
    group ""

    group "Applications"
        include "vendor/premake/Sandbox"
    group ""
