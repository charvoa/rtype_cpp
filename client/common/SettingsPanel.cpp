//
// SettingsPanel.cpp for SettingsPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:50:13 2015 Viveka BARNEAUD
// Last update Thu Dec  3 14:01:46 2015 Serge Heitzler
//

#include "RenderWindow.hh"
#include "PanelFactory.hh"
#include "SettingsPanel.hh"
#include "ButtonFactory.hh"

SettingsPanel::SettingsPanel()
{
    _tmp = new Settings(*(RenderWindow::getInstance())->getSettings());
}

SettingsPanel::~SettingsPanel()
{
    delete _tmp;
}

void	SettingsPanel::setUserInterface()
{
	RenderWindow *window = RenderWindow::getInstance();
	getInputManager().setInputType(InputType::SETTINGS_INPUT);

	Sprite *backgroundSpace = new Sprite;
	Sprite *earth = new Sprite;
	Sprite *cockpit = new Sprite;
	Sprite *logo = new Sprite;
	Sprite *black = new Sprite;

	earth->setOrigin((RenderWindow::getInstance())->_ressources->_earth->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_earth->getSize()._y / 2);
	logo->setOrigin((RenderWindow::getInstance())->_ressources->_logo->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_logo->getSize()._y / 2);

	backgroundSpace->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundStartPanel));
	earth->setTexture(*((RenderWindow::getInstance())->_ressources->_earth));
	cockpit->setTexture(*((RenderWindow::getInstance())->_ressources->_cockpit));
	logo->setTexture(*((RenderWindow::getInstance())->_ressources->_logo));
	black->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundBlack));

	backgroundSpace->setPosition(0, 0);
	earth->setPosition(window->getSize()._x + (RenderWindow::getInstance())->_ressources->_earth->getSize()._x / 6, window->getSize()._y + (RenderWindow::getInstance())->_ressources->_earth->getSize()._y / 6);
	cockpit->setPosition(0, 0);
	black->setPosition(0, 0);
	logo->setPosition(window->getSize()._x / 2, window->getSize()._y / 6);
	logo->scale(0.5);

	backgroundSpace->scale(1.1);

	_backgrounds.push_back(*backgroundSpace);
	_backgrounds.push_back(*earth);
	_backgrounds.push_back(*cockpit);
	_backgrounds.push_back(*logo);
	_backgrounds.push_back(*black);

	// Button

	std::string name = "BACK";
	ButtonFactory::create(Vector2(window->getSize()._x * 0.25, window->getSize()._y * 0.7), name);
	name = "ACCESS";
	ButtonFactory::create(Vector2(window->getSize()._x * 0.75, window->getSize()._y * 0.7), name);


	Text		       	*id = new Text();

	id->setString("");
	id->setSize(50);
	id->setStyle(1);
	id->setOrigin(id->getText().getGlobalBounds().width / 2, id->getText().getGlobalBounds().height / 2);
	id->setPosition(Vector2(window->getSize()._x * 0.5, window->getSize()._y * 0.5));
	id->setColor(Color::WHITE);
	_labels.push_back(*id);

	Text		       	*text = new Text();

	text->setString("ENTER ROOM ID TO JOIN :");
	text->setSize(80);
	text->setStyle(1);
	text->setOrigin(text->getText().getGlobalBounds().width / 2, text->getText().getGlobalBounds().height / 2);
	text->setPosition(Vector2(window->getSize()._x * 0.5, window->getSize()._y * 0.3));
	text->setColor(Color::WHITE);
	_labels.push_back(*text);
}

void    SettingsPanel::setGlobalVolume(int global)
{
    Volume vol = _tmp->getVolume();

    vol.setGlobal(global);
    _tmp->setVolume(vol);
}

void    SettingsPanel::setEffectsVolume(int effects)
{
   Volume vol = _tmp->getVolume();

    vol.setEffects(effects);
   _tmp->setVolume(vol);
}

void    SettingsPanel::setMusicVolume(int music)
{
    Volume vol = _tmp->getVolume();

    vol.setMusic(music);
    _tmp->setVolume(vol);
}  

void    SettingsPanel::setBind(Bind bind)
{
    _tmp->setBind(bind);
}

void    SettingsPanel::defaultSettings()
{
    _tmp->resetDefault();
}

void    SettingsPanel::back()
{
	(RenderWindow::getInstance())->back();
}

void    SettingsPanel::save()
{
	(RenderWindow::getInstance())->setSettings(_tmp);
}
