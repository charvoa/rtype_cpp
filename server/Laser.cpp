//
// Laser.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sun Dec 13 05:07:55 2015 Louis Audibert
// Last update Sun Dec 20 16:37:58 2015 Nicolas Charvoz
//

#include <Laser.hh>

Laser::Laser(int id) : AEntity(id)
{
  addSystem(C_POSITION);
  addSystem(C_HITBOX);
  _launchTime = std::chrono::system_clock::now();
}

Laser::~Laser()
{

}

std::chrono::time_point<std::chrono::system_clock> Laser::getLaunchTime() const {
  return _launchTime;
}
