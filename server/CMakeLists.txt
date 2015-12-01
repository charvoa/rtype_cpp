project(server)

add_executable(
  ./server
  main.cpp
  Server.cpp
  Network.cpp
  Health.cpp
  Missile.cpp
  Laser.cpp
  Rifle.cpp
  Position.cpp
  SystemHealth.cpp
  SystemPos.cpp
  SystemGun.cpp
  SystemManager.cpp
)