project "glfw"
    kind "StaticLib"
    language "C"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/build/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{IncludeDir.glfw}/glfw/glfw3.h",
        "%{IncludeDir.glfw}/glfw/glfw3native.h",
        "%{SrcDir.glfw}/internal.h",
        "%{SrcDir.glfw}/platform.h",
        "%{SrcDir.glfw}/mappings.h",
        "%{SrcDir.glfw}/context.c",
        "%{SrcDir.glfw}/init.c",
        "%{SrcDir.glfw}/input.c",
        "%{SrcDir.glfw}/monitor.c",
        "%{SrcDir.glfw}/platform.c",
        "%{SrcDir.glfw}/vulkan.c",
        "%{SrcDir.glfw}/window.c",
        "%{SrcDir.glfw}/egl_context.c",
        "%{SrcDir.glfw}/osmesa_context.c",
        "%{SrcDir.glfw}/null_platform.h",
        "%{SrcDir.glfw}/null_joystick.h",
        "%{SrcDir.glfw}/null_init.c",

        "%{SrcDir.glfw}/null_monitor.c",
        "%{SrcDir.glfw}/null_window.c",
        "%{SrcDir.glfw}/null_joystick.c",

    }
    filter "system:linux"
        pic "On"
        systemversion "latest"
        staticruntime "Off"

        files
        {
            "%{SrcDir.glfw}/x11_init.c",
            "%{SrcDir.glfw}/x11_monitor.c",
            "%{SrcDir.glfw}/x11_window.c",
            "%{SrcDir.glfw}/xkb_unicode.c",
            "%{SrcDir.glfw}/posix_time.c",
            "%{SrcDir.glfw}/posix_thread.c",
            "%{SrcDir.glfw}/glx_context.c",
            "%{SrcDir.glfw}/egl_context.c",
            "%{SrcDir.glfw}/osmesa_context.c",
            "%{SrcDir.glfw}/linux_joystick.c"
        }

        defines
        {
            "_GLFW_X11"
            
        }

    filter "system:windows"
        systemversion "latest"
        staticruntime "Off"

        files
        {
            "%{SrcDir.glfw}/win32_init.c",
            "%{SrcDir.glfw}/win32_module.c",
            "%{SrcDir.glfw}/win32_joystick.c",
            "%{SrcDir.glfw}/win32_monitor.c",
            "%{SrcDir.glfw}/win32_time.h",
            "%{SrcDir.glfw}/win32_time.c",
            "%{SrcDir.glfw}/win32_thread.h",
            "%{SrcDir.glfw}/win32_thread.c",
            "%{SrcDir.glfw}/win32_window.c",
            "%{SrcDir.glfw}/wgl_context.c",
            "%{SrcDir.glfw}/egl_context.c",
            "%{SrcDir.glfw}/osmesa_context.c"
        }

        defines 
        { 
            "_GLFW_WIN32",
            "_CRT_SECURE_NO_WARNINGS"

        }

    filter "configurations:Debug"
        symbols "On"

    filter "configurations:Release"
        optimize "On"
        symbols "Off"

    filter "configurations:Dist"
        optimize "On"
        symbols "Off"
