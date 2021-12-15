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
        "%{IncludeList.SPDLOG}",
        "%{IncludeList.GLFW}"
    }

    links
    {
        "SPDLOG",
        "GLFW"
    }

    defines
    {
        "ENABLE_LOGGING",
        "ENABLE_ASSERTS"
    }

    filter "configurations:Debug"
        defines { "INCORE_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "INCORE_RELEASE" }
        runtime "Release"
        optimize "On"