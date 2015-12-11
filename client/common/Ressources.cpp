//
// Ressources.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Thu Dec 10 13:16:46 2015 Serge Heitzler
// Last update Thu Dec 10 15:06:15 2015 Serge Heitzler
//

#include "Ressources.hh"

Ressources::Ressources()
{
  _buttonNormal = new Texture();
  _buttonHighlight = new Texture();
  _buttonSelect = new Texture();


  _buttonNormal->loadFromFile("../common/misc/button_normal.png");
  _buttonHighlight->loadFromFile("../common/misc/button_highlight.png");
  //  _buttonSelect->loadFromFile("../common/misc/button_normal.png");
  
  _backgroundStartPanel = new Texture();
  _backgroundRoomPanel = new Texture();
  _backgroundSettingsPanel = new Texture();
  _backgroundBlack = new Texture();
  _earth = new Texture();
  _logo = new Texture();
  _cockpit = new Texture();

  _backgroundStartPanel->loadFromFile("../common/misc/background.png");
  _backgroundRoomPanel->loadFromFile("../common/misc/room_background.png");
  _backgroundSettingsPanel->loadFromFile("../common/misc/settings_background.png");
  _backgroundBlack->loadFromFile("../common/misc/black_background.png");
  _earth->loadFromFile("../common/misc/planet_earth_background.png");
  _logo->loadFromFile("../common/misc/rtype_logo.png");
  _cockpit->loadFromFile("../common/misc/cockpit.png");


  _blackShip = new Texture();
  _blueShip = new Texture();
  _redShip = new Texture();
  _greenShip = new Texture();
  _yellowShip = new Texture();
  
  _blackShip->loadFromFile("../common/misc/player_black.png");
  _blueShip->loadFromFile("../common/misc/player_blue.png");
  _redShip->loadFromFile("../common/misc/player_red.png");
  _greenShip->loadFromFile("../common/misc/player_green.png");
  _yellowShip->loadFromFile("../common/misc/player_yellow.png");

  _fontFirst = new SFont();
  _fontSecond = new SFont();
  _fontThird = new SFont();

  _fontFirst->loadFromFile("../common/misc/fonts/nasalization.ttf");
  _fontSecond->loadFromFile("../common/misc/fonts/prototype.ttf");
  _fontThird->loadFromFile("../common/misc/fonts/fifa_welcome.ttf");
}

Ressources::~Ressources()
{

}

