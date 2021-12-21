workspace "Solution"
    startproject "Runtime"
    architecture "x86_64"
    configurations { "Debug", "Release" }

    Bin = "%{wks.location}/Build/Bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    Obj = "%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeList = {}
IncludeList["VULKANSDK"] = "%{VULKAN_SDK}/Include"
IncludeList["SPDLOG"] = "%{wks.location}/Thirdparty/spdlog/include"
IncludeList["GLFW"] = "%{wks.location}/Thirdparty/glfw/include"

LibraryList = {}
LibraryList["VULKANSDK"] = "%{VULKAN_SDK}/Lib"

group "Dependencies"
include "Thirdparty/premake5_spdlog.lua"
include "Thirdparty/premake5_glfw.lua"
group ""

include "Incore"
include "Runtime"