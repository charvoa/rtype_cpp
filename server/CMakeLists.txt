project(server)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

SET(CMAKE_CXX_COMPILER	"g++")

add_executable(
  ./server
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
  Player.cpp
  PlayerManager.cpp
  Client.cpp
  Parameters.cpp
  Network.cpp
)