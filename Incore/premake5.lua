project "Incore"
    kind "StaticLib"
    language "C++"
    cppdialect "C++11"

    targetdir(Bin)
    objdir(Obj)

    pchheader "ipch.h"
    pchsource "Source/ipch.cpp"

    files
    {
        "Source/**.h",
        "Source/**.c",
        "Source/**.hpp",
        "Source/**.cpp"
    }

    includedirs
    {
        "Source",
        "%{IncludeList.VULKANSDK}",
        "%{IncludeList.SPDLOG}",
        "%{IncludeList.GLFW}",
        "%{IncludeList.GLM}"
    }

    links
    {
        "SPDLOG",
        "GLFW",
        "%{LibraryList.VULKANSDK}/vulkan-1.lib"
    }

    defines
    {
        "ENABLE_LOGGING",
        "ENABLE_ASSERTS",
        --
        "GLFW_INCLUDE_NONE"
    }

    filter "configurations:Debug"
        defines { "INCORE_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "INCORE_RELEASE" }
        runtime "Release"
        optimize "On"

    filter "system:windows"
        disablewarnings { "6285", "26812", "26437", "26451", "26498", "26800" }