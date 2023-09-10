project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "%{wks.location}/Quest/include",
        "%{Includes.spdlog}",
    }

    links {
        "Quest"
    }

    filter "system:windows"
        systemversion "latest"
        
    filter "configurations:Debug"
        defines "QE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "QE_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Distribution"
        defines "QE_DIST"
        runtime "Release"
        optimize "on"