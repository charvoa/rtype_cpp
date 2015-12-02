project(RTYPE_SERVER)

set(EXECUTABLE_NAME "server_rtype")

cmake_minimum_required(VERSION 2.6)

#SET(CMAKE_CXX_COMPILER	"g++-5")

if(CMAKE_COMPILER_IS_GNUCC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Woverloaded-virtual -Wfloat-equal")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow -Wredundant-decls -Wdouble-promotion -Winit-self")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wundef -Winline")
endif(CMAKE_COMPILER_IS_GNUCC)

add_executable( server_rtype
  main.cpp
  Server.cpp
  Network.cpp
  Socket.cpp
  Health.cpp
  Missile.cpp
  Laser.cpp
  Rifle.cpp
  Position.cpp
  SystemHealth.cpp
  SystemPos.cpp
  SystemGun.cpp
  SystemManager.cpp
  Server.cpp
  AEntity.cpp
  EntityManager.cpp
  EntityFactory.cpp
  CommandManager.cpp
  Room/Room.cpp
  Room/RoomManager.cpp
  PlayerFactory.cpp
  Player.cpp
  Client.cpp
  ../common/Thread/ThreadFactory.cpp
  Parameters.cpp
  Network.cpp
  GameManager.cpp
  Game.cpp
  ClientManager.cpp
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package (Threads)

target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_THREAD_LIBS_INIT})
