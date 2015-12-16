//
// Ressources.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Thu Dec 10 13:16:46 2015 Serge Heitzler
// Last update Wed Dec 16 06:22:08 2015 Serge Heitzler
//

#include "Ressources.hh"

Ressources::Ressources()
{
  _buttonNormal = new Texture();
  _buttonHighlight = new Texture();
  _buttonSelect = new Texture();
  _keyButtonNormal = new Texture();
  _keyButtonHighlight = new Texture();
  _slide = new Texture();
  _sliderNormal = new Texture();

  _buttonNormal->loadFromFile("../common/misc/button_normal.png");
  _buttonHighlight->loadFromFile("../common/misc/button_highlight.png");
  //  _buttonSelect->loadFromFile("../common/misc/button_normal.png");
  _slide->loadFromFile("../common/misc/slider.png");
  _sliderNormal->loadFromFile("../common/misc/slideButton.png");
  _keyButtonNormal->loadFromFile("../common/misc/keyButton_normal.png");
  _keyButtonHighlight->loadFromFile("../common/misc/keyButton_selected.png");

  _backgroundStartPanel = new Texture();
  _backgroundRoomPanel = new Texture();
  _backgroundSettingsPanel = new Texture();
  _backgroundBlack = new Texture();
  _backgroundGame1 = new Texture();
  _backgroundGame2 = new Texture();
  _backgroundGame3 = new Texture();
  _panelIntroUp = new Texture();
  _panelIntroDown = new Texture();
  _earth = new Texture();
  _logo = new Texture();
  _cockpit = new Texture();
  _greyPanel = new Texture();
  _keyboard = new Texture();
  _controller = new Texture();
  
  _backgroundStartPanel->loadFromFile("../common/misc/background.png");
  _backgroundRoomPanel->loadFromFile("../common/misc/room_background.png");
  _backgroundSettingsPanel->loadFromFile("../common/misc/settings_background.png");
  _backgroundGame1->loadFromFile("../common/misc/background_in_game.png");
  _backgroundGame2->loadFromFile("../common/misc/background_in_game_2.png");
  _backgroundGame3->loadFromFile("../common/misc/background_in_game_3.png");
  _backgroundBlack->loadFromFile("../common/misc/black_background.png");
  _panelIntroUp->loadFromFile("../common/misc/panel_up.png");
  _panelIntroDown->loadFromFile("../common/misc/panel_down.png");
  _earth->loadFromFile("../common/misc/planet_earth_background.png");
  _logo->loadFromFile("../common/misc/rtype_logo.png");
  _cockpit->loadFromFile("../common/misc/cockpit.png");
  _greyPanel->loadFromFile("../common/misc/grey_panel.png");
  _keyboard->loadFromFile("../common/misc/keyboard.png");
  _controller->loadFromFile("../common/misc/controller.png");

  _hud = new Texture();
  _header = new Texture();
  _bottomGame = new Texture();
  _topGame = new Texture();
  _heart = new Texture();
  _reactor = new Texture();
  _riffle = new Texture();
  _riffleHUD = new Texture();
  _rocket = new Texture();
  _rocketBlack = new Texture();
  _laserBlackLittle = new Texture();
  _laserBlueLittle = new Texture();
  _laserBlueBig = new Texture();
  _laserRedLittle = new Texture();
  _laserRedBig = new Texture();
  _laserGreenLittle = new Texture();
  _laserGreenBig = new Texture();
  _laserYellowLittle = new Texture();
  _laserYellowBig = new Texture();

  _hud->loadFromFile("../common/misc/hud.png");
  _header->loadFromFile("../common/misc/header.png");
  _bottomGame->loadFromFile("../common/misc/bottomGame.png");
  _topGame->loadFromFile("../common/misc/topGame.png");
  _heart->loadFromFile("../common/misc/heart.png");
  _reactor->loadFromFile("../common/misc/reactor.png");
  _riffle->loadFromFile("../common/misc/riffle_ammo.png");
  _riffleHUD->loadFromFile("../common/misc/riffle_infinite.png");
  _rocket->loadFromFile("../common/misc/rocket.png");
  _rocketBlack->loadFromFile("../common/misc/rocket_black.png");

  _laserBlackLittle->loadFromFile("../common/misc/laser_black_little.png");
  _laserBlueLittle->loadFromFile("../common/misc/laser_blue_little.png");
  _laserBlueBig->loadFromFile("../common/misc/laser_blue_big.png");
  _laserRedLittle->loadFromFile("../common/misc/laser_red_little.png");
  _laserRedBig->loadFromFile("../common/misc/laser_red_big.png");
  _laserGreenLittle->loadFromFile("../common/misc/laser_green_little.png");
  _laserGreenBig->loadFromFile("../common/misc/laser_green_big.png");
  _laserYellowLittle->loadFromFile("../common/misc/laser_yellow_little.png");
  _laserYellowBig->loadFromFile("../common/misc/laser_yellow_big.png");

  _planetEarth = new Texture();
  _planetExodus = new Texture();
  _planetJupiter = new Texture();
  _planetMars = new Texture();
  _planetMoon = new Texture();
  _planetNeptune = new Texture();
  _planetSaturne = new Texture();
  _deathStar = new Texture();

  _planetEarth->loadFromFile("../common/misc/planet_earth.png");
  _planetExodus->loadFromFile("../common/misc/planet_exodus.png");
  _planetJupiter->loadFromFile("../common/misc/planet_jupiter.png");
  _planetMars->loadFromFile("../common/misc/planet_mars.png");
  _planetMoon->loadFromFile("../common/misc/planet_moon.png");
  _planetNeptune->loadFromFile("../common/misc/planet_neptune.png");
  _planetSaturne->loadFromFile("../common/misc/planet_saturn.png");
  _deathStar->loadFromFile("../common/misc/death_star.png");

  _blackShip = new Texture();
  _blueShip = new Texture();
  _redShip = new Texture();
  _greenShip = new Texture();
  _yellowShip = new Texture();

  _blueShipGame = new Texture();
  _redShipGame = new Texture();
  _greenShipGame = new Texture();
  _yellowShipGame = new Texture();

  _blackShip->loadFromFile("../common/misc/player_black.png");
  _blueShip->loadFromFile("../common/misc/player_blue.png");
  _redShip->loadFromFile("../common/misc/player_red.png");
  _greenShip->loadFromFile("../common/misc/player_green.png");
  _yellowShip->loadFromFile("../common/misc/player_yellow.png");

  _blueShipGame->loadFromFile("../common/misc/player_blue_game.png");
  _redShipGame->loadFromFile("../common/misc/player_red_game.png");
  _greenShipGame->loadFromFile("../common/misc/player_green_game.png");
  _yellowShipGame->loadFromFile("../common/misc/player_yellow_game.png");

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

