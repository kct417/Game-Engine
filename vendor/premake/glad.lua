project "glad"
    kind "StaticLib"
    language "C"
    staticruntime "On"

    location "%{wks.location}/build"
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/build/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{SrcDir.glad}/gl.c",
        "%{IncludeDir.glad}/glad/gl.h",
        "%{IncludeDir.glad}/KHR/khrplatform.h"
    }

    includedirs
    {
        "%{IncludeDir.glad}"
    }

    filter "action:vs*"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        symbols "Off"

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"
        symbols "Off"
