cmake_minimum_required(VERSION 3.25)
project(01hello C)

set(CMAKE_C_STANDARD 11)

add_executable(01hello main.c)

# libevent.a: 不能写lib前缀
target_link_libraries(01hello event)

