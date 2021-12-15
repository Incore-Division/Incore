project "SPDLOG"
    kind "StaticLib"
    language "C++"
    cppdialect "C++11"

    targetdir(Bin)
    objdir(Obj)

    files
    {
        "spdlog/include/**.h",
        "spdlog/include/**.hpp",
        "spdlog/src/**.c",
        "spdlog/src/**.cpp"
    }

    includedirs
    {
        "spdlog/include"
    }

    defines
    {
        "SPDLOG_COMPILED_LIB"
    }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"