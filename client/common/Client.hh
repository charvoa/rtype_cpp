//
// Client.hh for R-Type in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Sat Dec  5 10:16:19 2015 Nicolas Girardot
// Last update Mon Dec 14 15:20:05 2015 Nicolas Charvoz
//

#ifndef CLIENT_HH_
#define CLIENT_HH_

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ANetwork.hpp>
#include <RenderWindow.hh>
#include <Texture.hh>
#include <Sprite.hh>
#include <StartPanel.hh>
#include <RoomPanel.hh>
#include <InputManager.hh>
#include <PanelFactory.hh>
#include <SoundManager.hh>

#define IP_ADRESS "10.16.253.178"
#define PORT 4242
/
/#define IP_ADRESS "0"
//#define IP_ADRESS "51.254.139.53"
//#define IP_ADRESS "10.16.253.178"
//#define IP_ADRESS "10.16.252.249"
//#define PORT 4253

class	Client
{

public:
  Client();
  ~Client();
  void	Start();
  static ANetwork	*getNetwork();
  static ANetwork	*getUDPNetwork();
  static Sound		*getSound();

private:

  static ANetwork	*_network;
  static ANetwork	*_UDPnetwork;
  static Sound		*_sound;
};

#endif /* !CLIENT_HH_ */
