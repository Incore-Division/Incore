workspace "Solution"
    startproject "Runtime"
    architecture "x86_64"
    configurations { "Debug", "Release" }

    Bin = "%{wks.location}/Build/Bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    Obj = "%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeList = {}
IncludeList["GLFW"] = "%{wks.location}/Thirdparty/glfw/include"

group "Dependencies"
include "Thirdparty/premake5_glfw.lua"
group ""

include "Incore"
include "Runtime"