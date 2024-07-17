cmake_minimum_required(VERSION 3.22.1)
project(robot-arm)

# find_package(Boost REQUIRED)

#set compiler flags
set(CMAKE_CXX_FLAGS "-std=c++17 ${CMAKE_CXX_FLAGS}")

#find header and src files
file(GLOB_RECURSE ALL_HDRS "./include/*.hpp" "./include/*h" 
                            "./include/Eigen/*.h" "./include/glad/*.h" 
                            "./include/KHR/*.h" "./include/glm/*.hpp")
file(GLOB_RECURSE ALL_SRCS "./source/*.cpp" "./source/*.c")

#glfw:
find_package(OpenGL REQUIRED)
set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW lib only")
set( GLAD_GL "" )
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Build Wayland support" FORCE)
set(GLFW_BUILD_X11 ON CACHE BOOL "Build X11 support" FORCE)

# assimp
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "Assimp build tests" FORCE)
set(ASSIMP_INSTALL OFF CACHE BOOL "Assimp install" FORCE)
set(ASSIMP_INJECT_DEBUG_POSTFIX OFF CACHE BOOL "Postfix debugger injection" FORCE)

#include directories
include_directories(DIRECTORY
  include/${PROJECT_NAME}  
  include
  ./glfw-3.4/include
  ./assimp/include
)

add_subdirectory(./glfw-3.4)
add_subdirectory(./assimp)
# TARGET_LINK_LIBRARIES(robot-arm glfw)
# TARGET_LINK_LIBRARIES(robot-arm OpenGL::GL)
option( GLFW-CMAKE-STARTER-USE-GLFW-GLAD "Use GLAD from GLFW" ON )

link_directories()

add_library(${PROJECT_NAME} SHARED
  ${ALL_SRCS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw OpenGL::GL assimp)

set(test_cpp_dir "test/")
set(test_cpp_files "")
file(GLOB_RECURSE test_cpp_files "${test_cpp_dir}/*.cpp")
foreach(test_cpp_file ${test_cpp_files})
  get_filename_component(test_cpp_name ${test_cpp_file} NAME_WE)
  #ADD_EXECUTABLE(${test_cpp_name} ${ALL_SRCS} ${test_cpp_dir}/${test_cpp_name}.cpp)
  ADD_EXECUTABLE(${test_cpp_name} ${test_cpp_dir}/${test_cpp_name}.cpp)
  TARGET_LINK_LIBRARIES(${test_cpp_name}
    ${PROJECT_NAME}
    # pthread ## this is for linux systems
    glfw
    OpenGL::GL
    assimp
    m
    pthread
    dl
  )
endforeach(test_cpp_file ${test_cpp_files})
