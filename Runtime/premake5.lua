project "Runtime"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++11"

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
        "%{wks.location}/Incore/Source",
        "%{IncludeList.SPDLOG}"
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

    filter "system:windows"
        disablewarnings { "6285", "26812", "26437", "26451", "26498", "26800" }