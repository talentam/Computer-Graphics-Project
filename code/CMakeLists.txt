cmake_minimum_required(VERSION 3.17)
project(project)

include_directories(include)
link_directories(lib/x64)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(project main.cpp monitor.cpp monitor.h keyboard.cpp keyboard.h main.h desk.cpp desk.h room.cpp room.h Texture.cpp Texture.h animation.cpp animation.h)

target_link_libraries(project libopengl32.a  libfreeglut.a  glew32.lib  glew32s.lib libglu32.a)