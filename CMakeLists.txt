cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)

# Set to use solution folders for organization
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if (WIN32)
    add_compile_definitions(QE_PLATFORM_WINDOWS)
ENDIF()


# Set project
project(QuestEngine)

# Set QUEST_ROOT from environment var
set(QUEST_ROOT $ENV{QUEST_ENGINE_ROOT})

# Engine directory
add_subdirectory(${QUEST_ROOT}/Quest)

# Editor directory
#add_subdirectory(%{QUEST_ROOT}/Quest-Editor)

# Sandbox directory
add_subdirectory(${QUEST_ROOT}/Sandbox)

# Set startup project to Sandbox
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)