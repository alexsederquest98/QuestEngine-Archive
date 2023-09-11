toolset "clang"

include "ProjectDependencies.lua"

workspace "QuestEngine"
    architecture "x64"
    startproject "Sandbox"
    configurations {
        "Debug", "Release", "Distribution"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
group "Dependencies"
    --include "Quest/vendor/glad"
    --include "Quest/vendor/imgui"
group ""
include "Quest/vendor/glfw"
--include "Quest/vendor/yaml-cpp"
--include "Quest/vendor/ImGuizmo"
group "Core"
    include "Quest"
    include "Sandbox"
group ""