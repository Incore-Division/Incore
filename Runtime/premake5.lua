project "Runtime"
    kind "ConsoleApp"
    language "C++"
    cdialect "C++11"

    targetdir(Bin)
    objdir(Obj)

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
        "%{wks.location}/Incore/Source"
    }

    links
    {
        "Incore"
    }

    defines
    {
        "ENABLE_MESSAGES",
        "ENABLE_ASSERTIONS"
    }

    filter "configurations:Debug"
        defines { "RUNTIME_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "RUNTIME_RELEASE" }
        runtime "Release"
        optimize "On"