project "Engine"
    kind "SharedLib"
    language "C++"
    dependson { "glfw" }

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/build/" .. outputdir .. "/%{prj.name}")

    pchheader "gepch.h"
    pchsource "%{SrcDir.Engine}/gepch.cpp"

    files
    {
        "%{IncludeDir.Engine}/**.h",
        "%{SrcDir.Engine}/**.cpp"
    }

    includedirs
    {
        "%{IncludeDir.Engine}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.glfw}"
    }

    links
    {
        "GLFW",
        "opengl32"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
        systemversion "latest"

        defines
        {
            "GE_PLATFORM_WINDOWS",
            "GE_BUILD_DLL"
        }

        links
        {
            "gdi32"
        }

    filter "action:vs*"
        buildoptions {"/utf-8", "/wd4251"}

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        defines "GE_DEBUG"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        symbols "Off"
        defines "GE_RELEASE"

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"
        symbols "Off"
        defines "GE_DIST"
