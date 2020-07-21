workspace "Meaty"
    architecture "x64"
    startproject "sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["Glad"] = "Meaty/vendor/glad/include"
IncludeDir["GLFW"] = "Meaty/vendor/GLFW/include"
IncludeDir["ImGui"] = "Meaty/vendor/imgui"

include "Meaty/vendor/GLFW"
include "Meaty/vendor/glad"
include "Meaty/vendor/imgui"

project "Meaty"
    location "Meaty"
    kind "SharedLib"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("intermediate/" .. outputdir .. "/%{prj.name}")

    pchheader "mtpch.h"
    pchsource "Meaty/src/mtpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "Glad",
        "GLFW",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MT_WINDOWS_PLATFORM",
            "MT_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
        }

    filter "configurations:Debug"
        defines "MT_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "MT_RELEASE"
        buildoptions "/MD"
        optimize "On"
        
    filter "configurations:Dist"
        defines "MT_DIST"
        buildoptions "/MD"
        optimize "On"

project "sandbox"
    location "sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("intermediate/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Meaty/vendor/spdlog/include",
        "Meaty/src"
    }

    links 
    {
        "Meaty"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MT_WINDOWS_PLATFORM"
        }

    filter "configurations:Debug"
        defines "MT_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "MT_RELEASE"
        buildoptions "/MD"
        optimize "On"
        
    filter "configurations:Dist"
        defines "MT_DIST"
        buildoptions "/MD"
        optimize "On"

        
