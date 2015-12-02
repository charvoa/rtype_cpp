project(RTYPE_SERVER)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# SET(CMAKE_CXX_COMPILER	"clang++")

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
  Player.cpp
  PlayerManager.cpp
  Client.cpp
  Parameters.cpp
  Network.cpp
  GameManager.cpp
  Game.cpp
  ../common/Thread/ThreadUnix.cpp
)

target_link_libraries(server_rtype pthread)