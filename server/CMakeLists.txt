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

include_directories(. ../common Room)

add_executable( server_rtype
  main.cpp
  Server.hh
  Server.cpp
  Network.hh
  Network.cpp
  ISocket.hpp
  Socket.cpp
  Socket.hh
  E_Component.hh
  AComponent.hpp
  Health.cpp
  Health.hh
  Missile.cpp
  Laser.cpp
  Laser.hh
  Rifle.cpp
  Rifle.hh
  Position.cpp
  Position.hh
  ASystem.hh
  SystemHealth.cpp
  SystemHealth.hh
  SystemPos.cpp
  SystemPos.hh
  SystemGun.cpp
  SystemGun.hh
  SystemManager.cpp
  SystemManager.hh
  E_EntityType.hh
  AEntity.cpp
  AEntity.hh
  EntityManager.cpp
  EntityManager.hh
  EntityFactory.cpp
  EntityFactory.hh
  E_Command.hh
  CommandManager.cpp
  CommandManager.hpp
  Room/Room.cpp
  Room/Room.hh
  Room/RoomManager.cpp
  Room/RoomManager.hh
  PlayerFactory.hh
  PlayerFactory.cpp
  Player.cpp
  Player.hh
  Client.cpp
  Client.hh
  ../common/Thread/ThreadFactory.cpp
  Parameters.cpp
  ANetwork.hpp
  Network.cpp
  GameManager.cpp
  GameManager.hh
  Game.cpp
  Game.hh
  ClientManager.cpp
  ClientManager.hh
  ../common/E_Difficulty.hh
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package (Threads)

target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_THREAD_LIBS_INIT})
