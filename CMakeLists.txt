cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(VulkanTest)

set(CMAKE_CXX_STANDARD 17)
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set(
    CMAKE_CXX_FLAGS_DEBUG
    "${CMAKE_CXX_FLAGS_DEBUG} /JMC"
  )
else()
  set(
    CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror -Wno-unused-parameter -Wno-implicit-fallthrough"
  )
endif()

file(GLOB sources
  *.cpp
  *.h
*.c
*.spv
)

add_executable(
  VulkanTest
  ${sources} 
)

set_property(TARGET VulkanTest PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

configure_file(${CMAKE_SOURCE_DIR}/shaders/frag.spv Debug/shaders/frag.spv COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/shaders/vert.spv Debug/shaders/vert.spv COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/textures/wheel.png Debug/textures/wheel.png COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/models/big_wheel.obj Debug/models/big_wheel.obj COPYONLY)

set(includes 
"${CMAKE_SOURCE_DIR}/Libraries/glfw-3.3.7.bin.WIN64/include"
"${CMAKE_SOURCE_DIR}/Libraries/VulkanSDK/1.3.216.0/Include"
"${CMAKE_SOURCE_DIR}/Libraries/glm"
"${CMAKE_SOURCE_DIR}/Libraries/stb"
"${CMAKE_SOURCE_DIR}/Libraries/tinyobjloader"
)

include_directories(${includes})

SET_TARGET_PROPERTIES(VulkanTest PROPERTIES LINK_FLAGS "/NODEFAULTLIB:\"MSVCRT\"")

target_link_libraries(VulkanTest "${CMAKE_SOURCE_DIR}/Libraries/VulkanSDK/1.3.216.0/Lib/vulkan-1.lib" )

target_link_libraries(VulkanTest "${CMAKE_SOURCE_DIR}/Libraries/glfw-3.3.7.bin.WIN64/lib-vc2022/glfw3.lib")

