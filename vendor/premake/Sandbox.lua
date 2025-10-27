project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    dependson { "Engine" }

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/build/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{SrcDir.Sandbox}/**.h",
        "%{SrcDir.Sandbox}/**.cpp"
    }

    includedirs
    {
        "%{IncludeDir.Engine}",
        "%{IncludeDir.spdlog}"
    }

    links
    {
        "Engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
        systemversion "latest"

        defines
        {
            "GE_PLATFORM_WINDOWS"
        }

        postbuildcommands
        {
            '{COPYFILE} "%{wks.location}/bin/' .. outputdir .. '/Engine/Engine.dll" "%{wks.location}/bin/' .. outputdir .. '/%{prj.name}"'
        }

    filter "action:vs*"
        buildoptions {"/utf-8", "/wd4251"}

    filter "configurations:Debug"
        defines "GE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "GE_RELEASE"
        optimize "On"
        symbols "Off"

    filter "configurations:Dist"
        defines "GE_DIST"
        optimize "On"
        symbols "Off"
