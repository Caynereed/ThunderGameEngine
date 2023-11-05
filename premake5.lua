workspace "ThunderGameEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ThunderGameEngine"
	location "ThunderGameEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

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
			"TD_Platform_Windows",
			"TD_Build_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TD_Debug"
		symbols "On"

	filter "configurations:Release"
		defines "TD_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "TD_Dist"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{ 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp" 
	}

	includedirs
	{
		"ThunderGameEngine/vendor/spdlog/include",
		"ThunderGameEngine/src"
	}

	links
	{
		"ThunderGameEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TD_Platform_Windows"
		}

	filter "configurations:Debug"
		defines "TD_Debug"
		symbols "On"

	filter "configurations:Release"
		defines "TD_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "TD_Dist"
		optimize "On"