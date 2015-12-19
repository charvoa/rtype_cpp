project(RTYPE_SERVER)

set(EXECUTABLE_NAME "server_rtype")

cmake_minimum_required(VERSION 2.6)

#SET(CMAKE_CXX_COMPILER	"clang++")

if(CMAKE_COMPILER_IS_GNUCC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -g3")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Woverloaded-virtual -Wfloat-equal")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow -Wredundant-decls -Wdouble-promotion -Winit-self")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wundef -Winline")
endif(CMAKE_COMPILER_IS_GNUCC)

include_directories(. ../common Room ../common/Thread)

add_executable(server_rtype
  main.cpp
  Server.cpp
  ComponentHealth.cpp
  ComponentMissile.cpp
  ComponentLaser.cpp
  ComponentRiffle.cpp
  ComponentPosition.cpp
  ComponentHitbox.cpp
  Missile.cpp
  Riffle.cpp
  Laser.cpp
  SystemHealth.cpp
  SystemPos.cpp
  SystemGun.cpp
  SystemHitbox.cpp
  SystemManager.cpp
  AEntity.cpp
  EntityManager.cpp
  EntityFactory.cpp
  CommandManager.cpp
  Room/Room.cpp
  Room/RoomManager.cpp
  PlayerFactory.cpp
  Player.cpp
  Monitoring.cpp
  Client.cpp
  ../common/Thread/ThreadFactory.cpp
  Parameters.cpp
  GameManager.cpp
  Game.cpp
  ClientManager.cpp
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package (Threads)

target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_THREAD_LIBS_INIT} "-ldl")