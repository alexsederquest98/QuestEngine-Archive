set_property(TARGET PROPERTY USE_FOLDERS ON)

set (TARGET_NAME Quest)
set(QUEST_LIBRARY_TYPE STATIC)

# Vendor subdirectories (that need compiled)
add_subdirectory(${QUEST_ROOT}/Quest/vendor/glfw)
#add_subdirectory(QUEST_ROOT/Quest/vendor/glad)
#add_subdirectory(QUEST_ROOT/Quest/vendor/imgui)
#add_subdirectory(QUEST_ROOT/Quest/vendor/ImGuizmo)
#add_subdirectory(QUEST_ROOT/Quest/vendor/yaml-cpp)

set (QUEST_STATIC_LIBS
    glfw
)

message(STATUS "Building Quest Engine static library...")

file (GLOB_RECURSE SOURCES src/*.cpp src/*.h)
#file (GLOB_RECURSE HEADERS include/Quest.h src/*.h)
set (HEADERS
    "include/"
    src/    
)

# vendor includes
set(VENDOR_INCLUDES 
    vendor/spdlog/include/
    vendor/glfw/include/
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})
#source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HEADERS})
#set (SOURCES "src/TestLib.cpp")
#set (HEADERS "src/TestLib.h")

add_library(${TARGET_NAME} ${QUEST_LIBRARY_TYPE} ${SOURCES})

target_link_libraries(${TARGET_NAME} PUBLIC ${QUEST_STATIC_LIBS})

target_include_directories(${TARGET_NAME} PUBLIC ${HEADERS} ${VENDOR_INCLUDES})

target_precompile_headers(${TARGET_NAME} PRIVATE src/qepch.cpp)