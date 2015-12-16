//
// Ressources.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Thu Dec 10 13:16:51 2015 Serge Heitzler
// Last update Wed Dec 16 17:54:10 2015 Nicolas Girardot
//

#ifndef RESSOURCES_HH_
#define RESSOURCES_HH_

#include <map>
#include <string>
#include <Button.hh>
#include <Settings.hh>
#include <APanel.hh>
#include <Player.hh>

class Ressources : public APanel
{
public:

  Ressources();
  ~Ressources();

  Texture		*_explosion_blue;
  Texture		*_explosion_green;
  Texture		*_explosion_red;
  Texture		*_explosion_yellow;

  Texture		*_buttonNormal;
  Texture		*_buttonHighlight;
  Texture		*_buttonSelect;

  Texture		*_sliderNormal;
  Texture		*_slide;

  Texture		*_keyButtonNormal;
  Texture		*_keyButtonHighlight;

  Texture		*_panelIntroUp;
  Texture		*_panelIntroDown;

  Texture		*_backgroundStartPanel;
  Texture		*_backgroundRoomPanel;
  Texture		*_backgroundBlack;
  Texture		*_backgroundSettingsPanel;
  Texture		*_backgroundGame1;
  Texture		*_backgroundGame2;
  Texture		*_backgroundGame3;
  Texture		*_earth;
  Texture		*_logo;
  Texture		*_cockpit;
  Texture		*_greyPanel;
  Texture		*_keyboard;
  Texture		*_controller;

  Texture		*_hud;
  Texture		*_header;
  Texture		*_topGame;
  Texture		*_bottomGame;
  Texture		*_heart;
  Texture		*_reactor;
  Texture		*_riffle;
  Texture		*_riffleHUD;
  Texture		*_rocket;
  Texture		*_rocketBlack;

  Texture		*_laserBlackLittle;
  Texture		*_laserBlueLittle;
  Texture		*_laserBlueBig;
  Texture		*_laserRedLittle;
  Texture		*_laserRedBig;
  Texture		*_laserGreenLittle;
  Texture		*_laserGreenBig;
  Texture		*_laserYellowLittle;
  Texture		*_laserYellowBig;


  Texture		*_planetEarth;
  Texture		*_planetExodus;
  Texture		*_planetJupiter;
  Texture		*_planetMars;
  Texture		*_planetMoon;
  Texture		*_planetNeptune;
  Texture		*_planetSaturne;
  Texture		*_deathStar;


  Texture		*_blackShip;
  Texture		*_blueShip;
  Texture		*_redShip;
  Texture		*_greenShip;
  Texture		*_yellowShip;

  Texture		*_blueShipGame;
  Texture		*_redShipGame;
  Texture		*_greenShipGame;
  Texture		*_yellowShipGame;

  SFont			*_fontFirst;
  SFont			*_fontSecond;
  SFont			*_fontThird;

private:

};

#endif /* !RESSOURCES_HH_ */
