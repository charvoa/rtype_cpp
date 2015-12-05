//
// Client.hh for R-Type in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Sat Dec  5 10:16:19 2015 Nicolas Girardot
// Last update Sat Dec  5 05:36:52 2015 Serge Heitzler
//

#ifndef CLIENT_HH_
#define CLIENT_HH_

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "RenderWindow.hh"
#include "Texture.hh"
#include "Sprite.hh"
#include "StartPanel.hh"
#include "InputManager.hh"
#include "PanelFactory.hh"

class	Client
{
public:
  Client();
  ~Client();
  void	Start();
};

#endif
