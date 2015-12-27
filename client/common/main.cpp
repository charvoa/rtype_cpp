//
// main.cpp for rtype in /home/nicolas/rendu/rtype_cpp/client
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  1 11:41:24 2015 Nicolas Girardot
// Last update Sun Dec 27 08:08:42 2015 Serge Heitzler
//

#include <SFML/Audio.hpp>
#include <Client.hh>
#ifdef _WIN32
#else
#include <X11/Xlib.h>
#endif

int main()
{
#ifdef _WIN32
#else
  XInitThreads();
#endif
  Client *cli = new Client(3);
  cli->Start();
}
