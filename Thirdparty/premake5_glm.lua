project "GLM"
    kind "None"
    language "C++"
    cppdialect "C++11"

    targetdir(Bin)
    objdir(Obj)

    files
    {
        "glm/glm/**.h",
        "glm/glm/**.hpp"
    }

    includedirs
    {
        "glm"
    }

    filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"