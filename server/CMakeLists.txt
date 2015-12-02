project(RTYPE_SERVER)

set(EXECUTABLE_NAME "server_rtype")

cmake_minimum_required(VERSION 2.6)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

SET(CMAKE_CXX_COMPILER	"clang++")

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
  Parameters.cpp
  Network.cpp
  GameManager.cpp
  Game.cpp
  ../common/Thread/ThreadUnix.cpp
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package (Threads)

target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_THREAD_LIBS_INIT})
