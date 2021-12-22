project "GLFW"
    kind "StaticLib"
    language "C"
    cdialect "C11"

    targetdir(Bin)
    objdir(Obj)

    files
    {
        "glfw/include/**.h",
		"glfw/src/glfw_config.h",
		"glfw/src/context.c",
		"glfw/src/init.c",
		"glfw/src/input.c",
		"glfw/src/monitor.c",
		"glfw/src/vulkan.c",
		"glfw/src/window.c"
    }

    includedirs
    {
        "include"
    }

    filter "system:windows"
        files
		{
			"glfw/src/win32_init.c",
			"glfw/src/win32_joystick.c",
			"glfw/src/win32_monitor.c",
			"glfw/src/win32_time.c",
			"glfw/src/win32_thread.c",
			"glfw/src/win32_window.c",
			"glfw/src/wgl_context.c",
			"glfw/src/egl_context.c",
			"glfw/src/osmesa_context.c"
		}

    filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"

    filter "system:windows" -- this needs to be defined for every platform
        defines { "_GLFW_WIN32", "_CRT_SECURE_NO_WARNINGS" }
        disablewarnings { "5105" }