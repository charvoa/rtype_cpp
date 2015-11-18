project(server)

SET(CMAKE_CXX_COMPILER	"clang++")

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
)