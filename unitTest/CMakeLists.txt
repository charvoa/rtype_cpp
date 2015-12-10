project(test_rtype)

set(EXECUTABLE_NAME "test_rtype")

cmake_minimum_required(VERSION 2.6)

#SET(CMAKE_CXX_COMPILER	"clang++")

if(CMAKE_COMPILER_IS_GNUCC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Woverloaded-virtual -Wfloat-equal")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow -Wredundant-decls -Wdouble-promotion -Winit-self")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wundef -Winline")
endif(CMAKE_COMPILER_IS_GNUCC)

include_directories(. ../common Room ../common/Thread)

add_executable(test_rtype
  main.cpp
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package (Threads)

target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_THREAD_LIBS_INIT})