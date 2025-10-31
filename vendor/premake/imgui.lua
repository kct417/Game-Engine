project "imgui"
	kind "StaticLib"
	language "C++"
    cppdialect "C++latest"
    staticruntime "On"

    location "%{wks.location}/build"
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/build/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{SrcDir.imgui}/imgui.cpp",
		"%{SrcDir.imgui}/imgui_demo.cpp",
		"%{SrcDir.imgui}/imgui_draw.cpp",
		"%{SrcDir.imgui}/imgui_tables.cpp",
		"%{SrcDir.imgui}/imgui_widgets.cpp",
		"%{IncludeDir.imgui}/imconfig.h",
		"%{IncludeDir.imgui}/imgui.h",
		"%{IncludeDir.imgui}/imgui_internal.h",
		"%{IncludeDir.imgui}/imstb_rectpack.h",
		"%{IncludeDir.imgui}/imstb_textedit.h",
		"%{IncludeDir.imgui}/imstb_truetype.h"
	}

	filter "action:vs*"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
