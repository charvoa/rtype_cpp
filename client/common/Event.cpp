//
// Event.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Dec  2 02:33:15 2015 Serge Heitzler
// Last update Wed Dec  9 13:55:10 2015 Nicolas Girardot
//

#include <Event.hh>

Event::Event()
{

}

Event::~Event()
{

}

sf::Event		getEvent()
{
  return _event;
}
