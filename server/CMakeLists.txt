project(server)

add_executable(
  ./server
  main.cpp
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
<<<<<<< HEAD
  Room/Room.cpp
  Room/RoomManager.cpp
  Player.cpp
  Client.cpp
=======
  Parameters.cpp
>>>>>>> 78e281cfa471320d44ffe9b29f97ef23327cfc41
)