set_property(TARGET PROPERTY USE_FOLDERS ON)

file (GLOB_RECURSE SOURCES src/*.cpp src/*.h)
#file (GLOB_RECURSE HEADERS src/*.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})
#source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HEADERS})
#set (CPP_SOURCES 
#	"src/SandboxText.cpp")


add_executable(Sandbox ${SOURCES})
target_include_directories(Sandbox PRIVATE ${QUEST_ROOT}/Quest/include ${QUEST_ROOT}/Quest/vendor/spdlog/include)
target_link_libraries(Sandbox Quest)