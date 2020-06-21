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

project "Meaty"
    location "Meaty"
    kind "SharedLib"
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
        "%{prj.name}/vendor/spdlog/include"
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
        symbols "On"

    filter "configurations:Release"
        defines "MT_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "MT_DIST"
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
        symbols "On"

    filter "configurations:Release"
        defines "MT_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "MT_DIST"
        optimize "On"

        
