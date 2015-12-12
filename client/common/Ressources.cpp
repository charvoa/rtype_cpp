//
// Ressources.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Thu Dec 10 13:16:46 2015 Serge Heitzler
// Last update Sat Dec 12 10:48:38 2015 Serge Heitzler
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
  _panelIntroUp = new Texture();
  _panelIntroDown = new Texture();
  _earth = new Texture();
  _logo = new Texture();
  _cockpit = new Texture();
  
  _backgroundStartPanel->loadFromFile("../common/misc/background.png");
  _backgroundRoomPanel->loadFromFile("../common/misc/room_background.png");
  _backgroundSettingsPanel->loadFromFile("../common/misc/settings_background.png");
  _backgroundBlack->loadFromFile("../common/misc/black_background.png");
  _panelIntroUp->loadFromFile("../common/misc/panel_up.png");
  _panelIntroDown->loadFromFile("../common/misc/panel_down.png");
  _earth->loadFromFile("../common/misc/planet_earth_background.png");
  _logo->loadFromFile("../common/misc/rtype_logo.png");
  _cockpit->loadFromFile("../common/misc/cockpit.png");

  _hud = new Texture();
  _heart = new Texture();
  _riffle = new Texture();
  _rocket = new Texture();
  _rocketBlack = new Texture();
  _laser = new Texture();
  _laserBlack = new Texture();

  _hud->loadFromFile("../common/misc/hud.png");
  _heart->loadFromFile("../common/misc/heart.png");
  _riffle->loadFromFile("../common/misc/riffle.png");
  _rocket->loadFromFile("../common/misc/rocket.png");
  _rocketBlack->loadFromFile("../common/misc/rocket_black.png");
  _laser->loadFromFile("../common/misc/laser.png");
  _laserBlack->loadFromFile("../common/misc/laser_black.png");

  _planetEarth = new Texture();
  _planetExodus = new Texture();
  _planetJupiter = new Texture();
  _planetMars = new Texture();
  _planetMoon = new Texture();
  _planetNeptune = new Texture();
  _planetSaturne = new Texture();

  _planetEarth->loadFromFile("../common/misc/planet_earth.png");
  _planetExodus->loadFromFile("../common/misc/planet_exodus.png");
  _planetJupiter->loadFromFile("../common/misc/planet_jupiter.png");
  _planetMars->loadFromFile("../common/misc/planet_mars.png");
  _planetMoon->loadFromFile("../common/misc/planet_moon.png");
  _planetNeptune->loadFromFile("../common/misc/planet_neptune.png");
  _planetSaturne->loadFromFile("../common/misc/planet_saturne.png");

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

