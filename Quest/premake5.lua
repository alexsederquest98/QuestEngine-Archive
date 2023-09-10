project "Quest"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "qepch.h"
    pchsource "src/qepch.cpp"

    files {
        "src/**.h",
        "src/**.cpp",

        "include/Quest.h",

        --"vendor/stb_image/**.h",
        --"vendor/stb_image/**.cpp",

        --"vendor/glm/glm/**.hpp",
        --"vendor/glm/glm/**.inl"
    }

    includedirs {
        "src",
        "%{Includes.spdlog}",
        --"%{IncludeDir.glad}",
        --"%{IncludeDir.imgui}",
        "$(VULKAN_SDK)/Include",
    }

    links {
        --"ImGui",
        "$(VULKAN_SDK)/Lib/vulkan-1.lib",
        "$(VULKAN_SDK)/Lib/shaderc_sharedd.lib",
        "$(VULKAN_SDK)/Lib/spirv-cross-cored.lib",
        "$(VULKAN_SDK)/Lib/spirv-cross-glsld.lib",
    }

    defines {
        --"GLFW_INCLUDE_NONE",
        --"_CRT_SECURE_NO_WARNINGS"
    }

    filter "system:windows"
        systemversion "latest"

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"),
        }

    filter "configurations:Debug"
        defines "QE_DEBUG"
        runtime "Debug"
        --buildoptions "/MDd"
        symbols "on"

    filter "configurations:Release"
        defines "QE_RELEASE"
        runtime "Release"
        --buildoptions "/MD"
        optimize "on"

    filter "configurations:Distribution"
        defines "QE_DIST"
        runtime "Release"
        --buildoptions "/MD"
        optimize "on"