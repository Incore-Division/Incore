workspace "Solution"
    startproject "Runtime"
    architecture "x86_64"
    configuration { "Debug", "Release" }

    Bin = "%{wks.location}/Build/Bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    Obj = "%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
group "Dependencies"
group ""

include "Incore"
include "Runtime"