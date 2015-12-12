//
// Ressources.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Thu Dec 10 13:16:51 2015 Serge Heitzler
// Last update Sat Dec 12 10:07:00 2015 Serge Heitzler
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
  Texture		*_earth;
  Texture		*_logo;
  Texture		*_cockpit;

  
  Texture		*_hud;
  Texture		*_heart;
  Texture		*_riffle;
  Texture		*_rocket;
  Texture		*_rocketBlack;
  Texture		*_laser;
  Texture		*_laserBlack;

  
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
