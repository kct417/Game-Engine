project "Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++latest"
    staticruntime "On"
    dependson { "glfw", "glad", "imgui" }

    location "%{wks.location}/build"
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/build/" .. outputdir .. "/%{prj.name}")

    pchheader "gepch.h"
    pchsource "%{SrcDir.Engine}/gepch.cpp"

    files
    {
        "%{SrcDir.Engine}/**.cpp",
        "%{IncludeDir.Engine}/**.h"
    }

    includedirs
    {
        "%{IncludeDir.Engine}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.imgui}"
    }

    links
    {
        "glfw",
        "glad",
        "imgui"
    }

    defines { "_CRT_SECURE_NO_WARNINGS", "GLFW_INCLUDE_NONE" }

    filter "system:windows"
        defines "GE_PLATFORM_WINDOWS"
        links "gdi32"

    filter "action:vs*"
        systemversion "latest"
        warnings "Extra"
        buildoptions { "/utf-8", "/wd4251" }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        defines "GE_DEBUG"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        symbols "Off"

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"
        symbols "Off"
