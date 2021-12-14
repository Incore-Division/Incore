project "Incore"
    kind "SharedLib"
    language "C++"
    cdialect "C++11"

    targetdir(Bin)
    objdir(Obj)

    pchheader "ipch.hpp"
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
        "Source"
    }

    links
    {

    }

    defines
    {
        "ENABLE_MESSAGES",
        "ENABLE_ASSERTIONS"
    }

    filter "configurations:Debug"
        defines { "INCORE_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "INCORE_RELEASE" }
        runtime "Release"
        optimize "On"