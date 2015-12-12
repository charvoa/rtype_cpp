//
// Ressources.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Thu Dec 10 13:16:51 2015 Serge Heitzler
// Last update Sun Dec 13 06:49:35 2015 Serge Heitzler
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

  Texture		*_buttonNormal;
  Texture		*_buttonHighlight;
  Texture		*_buttonSelect;

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
  
  Texture		*_hud;
  Texture		*_header;
  Texture		*_heart;
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

  
  Texture		*_blackShip;
  Texture		*_blueShip;
  Texture		*_redShip;
  Texture		*_greenShip;
  Texture		*_yellowShip;
  
  SFont			*_fontFirst;
  SFont			*_fontSecond;
  SFont			*_fontThird;
  
private:

};

#endif /* !RESSOURCES_HH_ */
