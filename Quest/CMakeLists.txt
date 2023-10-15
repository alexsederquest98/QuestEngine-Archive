set_property(TARGET PROPERTY USE_FOLDERS ON)

set (TARGET_NAME Quest)
set(QUEST_LIBRARY_TYPE STATIC)

# vulkan
find_package(Vulkan REQUIRED COMPONENTS glslc glslang SPIRV-Tools shaderc_combined)

if (NOT Vulkan_FOUND)
    message(STATUS "Vulkan not found. Please install it.")
    return()
endif()

if (NOT Vulkan_SPIRV-Tools_FOUND)
    message(STATUS "Vulkan SPIRV-Tools not found. Please install it.")
    return()
endif()

if (NOT Vulkan_shaderc_combined_FOUND)
    message(STATUS "Vulkan shaderc not found. Please install it.")
    return()
endif()



# Vendor subdirectories (that need compiled)
message("Building glfw...")
add_subdirectory(${QUEST_ROOT}/Quest/vendor/glfw)
message("Done building glfw")
message("Building fmt...")
add_subdirectory(${QUEST_ROOT}/Quest/vendor/fmt EXCLUDE_FROM_ALL)
message("Done building fmt")
#add_subdirectory(QUEST_ROOT/Quest/vendor/glad)
#message("Building imgui...")
#add_subdirectory(${QUEST_ROOT}/Quest/vendor/imgui)
#message("Done building imgui")
#add_subdirectory(QUEST_ROOT/Quest/vendor/ImGuizmo)
#add_subdirectory(QUEST_ROOT/Quest/vendor/yaml-cpp)

set (QUEST_STATIC_LIBS
    glfw
    fmt
)

message(STATUS "Building Quest Engine static library...")

file (GLOB_RECURSE SOURCES src/*.cpp src/*.h include/Quest.h include/QuestEntrypoint.h)
#file (GLOB_RECURSE HEADERS include/Quest.h src/*.h)
set (HEADERS
    src/    
)

# vendor includes
set(VENDOR_INCLUDES 
    vendor/glfw/include/
    vendor/fmt/include/
    vendor/imgui/
)

set(VULKAN_LIBRARIES
    ${Vulkan_LIBRARY}
    ${Vulkan_glslang_LIBRARY}
    ${Vulkan_shaderc_combined_LIBRARY}
    ${Vulkan_SPIRV-Tools_LIBRARY}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})
#source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HEADERS})
#set (SOURCES "src/TestLib.cpp")
#set (HEADERS "src/TestLib.h")


add_library(${TARGET_NAME} ${QUEST_LIBRARY_TYPE} ${SOURCES})

target_precompile_headers(${TARGET_NAME} PRIVATE src/qepch.h)

target_link_libraries(${TARGET_NAME} PRIVATE ${Vulkan_LIBRARIES} ${QUEST_STATIC_LIBS})

target_include_directories(${TARGET_NAME} PUBLIC ${HEADERS} ${Vulkan_INCLUDE_DIR} ${VENDOR_INCLUDES})

