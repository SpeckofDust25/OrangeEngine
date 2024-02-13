workspace "OrangeEngine"
    architecture "x64"
    startproject "Sandbox"
    configurations {"Debug", "Release", "Dist"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"  --Create a macro
--Creates a "Debug/Windows/x64" folder strcuture 

project "OrangeEngine"      --Adding a Project
    location "OrangeEngine" --Where is the project located
    kind "SharedLib"        --Specify that it's a .dll library
    language "C++"

    --Project Output Directory
    targetdir ("bin/" ..outputdir.. "/%{prj.name}") 
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs { 
	"%{prj.name}/src",
	"OrangeEngine/vendor/spdlog/include"
	}

    filter "system:windows" 
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines { 
            "ORANGE_PLATFORM_WINDOWS",
            "ORANGE_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "ORANGE_DEGBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "ORANGE_RELEASE"
        symbols "On"
    
    filter "configurations:Dist"
        defines "ORANGE_DIST"
        symbols "On"


project "Sandbox"
    location "Sandbox" --Where is the project located
    kind "ConsoleApp"  --Specify that it's a .dll library
    language "C++"

    --Project Output Directory
    targetdir ("bin/" ..outputdir.. "/%{prj.name}") 
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs { 
        "OrangeEngine/vendor/spdlog/include",
        "OrangeEngine/src"
    }

    links {
        "OrangeEngine"
    }

    filter "system:windows" 
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines { 
            "ORANGE_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "ORANGE_DEGBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ORANGE_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "ORANGE_DIST"
        symbols "On"
        