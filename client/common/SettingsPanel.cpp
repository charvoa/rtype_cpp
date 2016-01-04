//
// SettingsPanel.cpp for SettingsPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:50:13 2015 Viveka BARNEAUD
// Last update Thu Dec  3 14:01:46 2015 Serge Heitzler
//

#include "Client.hh"
#include "SettingsLoader.hh"
#include "RenderWindow.hh"
#include "PanelFactory.hh"
#include "SettingsPanel.hh"
#include "ButtonFactory.hh"

SettingsPanel::SettingsPanel()
{
	_type = PanelFactory::SETTINGS_PANEL;
	_tmp = new Settings(std::string("../config/PersonalConfig.ini"));
}

SettingsPanel::~SettingsPanel()
{
    delete _tmp;
}

void	SettingsPanel::setUserInterface()
{
	RenderWindow *window = RenderWindow::getInstance();
	getInputManager().setInputType(InputType::SETTINGS_INPUT);


	Sprite *slideGlobal = new Sprite;
	Sprite *slideEffects = new Sprite;
	Sprite *slideMusic = new Sprite;
	Sprite *backgroundSpace = new Sprite;
	Sprite *earth = new Sprite;
	Sprite *cockpit = new Sprite;
	Sprite *logo = new Sprite;
	Sprite *black = new Sprite;

	earth->setOrigin((window)->_ressources->_earth->getSize()._x / 2, (window)->_ressources->_earth->getSize()._y / 2);
	logo->setOrigin((window)->_ressources->_logo->getSize()._x / 2, (window)->_ressources->_logo->getSize()._y / 2);

	slideGlobal->setTexture(*((window)->_ressources->_slide));
	slideEffects->setTexture(*((window)->_ressources->_slide));
	slideMusic->setTexture(*((window)->_ressources->_slide));
	backgroundSpace->setTexture(*((window)->_ressources->_backgroundStartPanel));
	earth->setTexture(*((window)->_ressources->_earth));
	cockpit->setTexture(*((window)->_ressources->_cockpit));
	logo->setTexture(*((window)->_ressources->_logo));
	black->setTexture(*((window)->_ressources->_backgroundBlack));

	slideGlobal->setPosition((window->getSize()._x * 0.05), window->getSize()._y * 0.25 - window->_ressources->_sliderNormal->getSize()._y / 2);
	slideEffects->setPosition((window->getSize()._x * 0.05), window->getSize()._y * 0.35 - window->_ressources->_sliderNormal->getSize()._y / 2);
	slideMusic->setPosition((window->getSize()._x * 0.05), window->getSize()._y * 0.45 - window->_ressources->_sliderNormal->getSize()._y / 2);
	backgroundSpace->setPosition(0, 0);
	earth->setPosition(window->getSize()._x + (window)->_ressources->_earth->getSize()._x / 6, window->getSize()._y + (window)->_ressources->_earth->getSize()._y / 6);
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
	_backgrounds.push_back(*slideGlobal);
	_backgrounds.push_back(*slideEffects);
	_backgrounds.push_back(*slideMusic);

	std::string name = "SAVE";
	ButtonFactory::create(Vector2(window->getSize()._x * 0.25, window->getSize()._y * 0.9), name);
	name = "DEFAULT";
	ButtonFactory::create(Vector2(window->getSize()._x * 0.5, window->getSize()._y * 0.9), name);
	name = "BACK";
	ButtonFactory::create(Vector2(window->getSize()._x * 0.75, window->getSize()._y * 0.9), name);

	_functions.push_back((APanel::funcs)&SettingsPanel::save);
	_functions.push_back((APanel::funcs)&SettingsPanel::defaultSettings);
	_functions.push_back((APanel::funcs)&SettingsPanel::back);

	std::vector<Bind*> binds = _tmp->getBinds();
	std::vector<Bind*>::const_iterator it = binds.begin();
	std::vector<Bind*>::const_iterator end = binds.end();
	SettingsLoader *loader = new SettingsLoader(false);
	int	layout = 0;
	int id = window->getPanels().top()->getLabels().size();

	while (it != end)
	{
		name = loader->keyToString((*it)->getKey());
		ButtonFactory::createKeyButton(Vector2(window->getSize()._x * 0.7, window->getSize()._y * 0.25 + layout), name, id++);
		name = loader->joystickToString((*it)->getJoystick());
		ButtonFactory::createKeyButton(Vector2(window->getSize()._x * 0.7 + 130, window->getSize()._y * 0.25 + layout), name, id++);
		layout += 70;
		++it;
	}

	name = "global";
	_global = ButtonFactory::createSlider(Vector2((window->getSize()._x * 0.05) + _tmp->getVolume().getGlobal() * 7, window->getSize()._y * 0.25), name, (window->getSize()._x * 0.05), (window->getSize()._x * 0.05) + window->_ressources->_slide->getSize()._x);
	name = "effects";
	_effects = ButtonFactory::createSlider(Vector2((window->getSize()._x * 0.05) + _tmp->getVolume().getEffects() * 7, window->getSize()._y * 0.35), name, (window->getSize()._x * 0.05), (window->getSize()._x * 0.05) + window->_ressources->_slide->getSize()._x);
	name = "music";
	_music = ButtonFactory::createSlider(Vector2((window->getSize()._x * 0.05) + _tmp->getVolume().getMusic()* 7, window->getSize()._y * 0.45), name, (window->getSize()._x * 0.05), (window->getSize()._x * 0.05) + window->_ressources->_slide->getSize()._x);

	Text		       	*title = new Text();

	title->setString("SETTINGS");
	title->setSize(80);
	title->setStyle(1);
	title->setOrigin(title->getText().getGlobalBounds().width / 2, title->getText().getGlobalBounds().height / 2);
	title->setPosition(Vector2(window->getSize()._x * 0.5, window->getSize()._y * 0.05));
	title->setColor(Color::WHITE);
	_labels.push_back(*title);

	Text			*volume = new Text();
	volume->setString("VOLUME");
	volume->setSize(40);
	volume->setStyle(1);
	volume->setOrigin(volume->getText().getGlobalBounds().width / 2, volume->getText().getGlobalBounds().height / 2);
	volume->setPosition(Vector2(window->getSize()._x * 0.2, window->getSize()._y * 0.15));
	volume->setColor(Color::WHITE);
	_labels.push_back(*volume);

	Text			*global = new Text();
	global->setString("GLOBAL");
	global->setSize(15);
	global->setStyle(1);
	global->setOrigin(global->getText().getGlobalBounds().width / 2, global->getText().getGlobalBounds().height / 2);
	global->setPosition(Vector2(window->getSize()._x * 0.45, window->getSize()._y * 0.25));
	global->setColor(Color::WHITE);
	_labels.push_back(*global);

	Text			*effects = new Text();
	effects->setString("EFFECTS");
	effects->setSize(15);
	effects->setStyle(1);
	effects->setOrigin(effects->getText().getGlobalBounds().width / 2, effects->getText().getGlobalBounds().height / 2);
	effects->setPosition(Vector2(window->getSize()._x * 0.45, window->getSize()._y * 0.35));
	effects->setColor(Color::WHITE);
	_labels.push_back(*effects);

	Text			*music = new Text();
	music->setString("MUSIC");
	music->setSize(15);
	music->setStyle(1);
	music->setOrigin(music->getText().getGlobalBounds().width / 2, music->getText().getGlobalBounds().height / 2);
	music->setPosition(Vector2(window->getSize()._x * 0.45, window->getSize()._y * 0.45));
	music->setColor(Color::WHITE);
	_labels.push_back(*music);

	Text			*keyboard = new Text();
	keyboard->setString("KEYBOARD");
	keyboard->setSize(20);
	keyboard->setStyle(1);
	keyboard->setOrigin(keyboard->getText().getGlobalBounds().width / 2, keyboard->getText().getGlobalBounds().height / 2);
	keyboard->setPosition(Vector2(window->getSize()._x * 0.68, window->getSize()._y * 0.15));
	keyboard->setColor(Color::WHITE);
	_labels.push_back(*keyboard);

	Text			*joystick = new Text();
	joystick->setString("JOYSTICK");
	joystick->setSize(20);
	joystick->setStyle(1);
	joystick->setOrigin(joystick->getText().getGlobalBounds().width / 2, joystick->getText().getGlobalBounds().height / 2);
	joystick->setPosition(Vector2(window->getSize()._x * 0.77, window->getSize()._y * 0.15));
	joystick->setColor(Color::WHITE);
	_labels.push_back(*joystick);

	Text			*moveUp = new Text();
	moveUp->setString("MOVE UP");
	moveUp->setSize(15);
	moveUp->setStyle(1);
	moveUp->setOrigin(moveUp->getText().getGlobalBounds().width / 2, moveUp->getText().getGlobalBounds().height / 2);
	moveUp->setPosition(Vector2(window->getSize()._x * 0.64, window->getSize()._y * 0.25));
	moveUp->setColor(Color::WHITE);
	_labels.push_back(*moveUp);

	Text			*moveDown = new Text();
	moveDown->setString("MOVE DOWN");
	moveDown->setSize(15);
	moveDown->setStyle(1);
	moveDown->setOrigin(moveDown->getText().getGlobalBounds().width / 2, moveDown->getText().getGlobalBounds().height / 2);
	moveDown->setPosition(Vector2(window->getSize()._x * 0.64, window->getSize()._y * 0.31));
	moveDown->setColor(Color::WHITE);
	_labels.push_back(*moveDown);

	Text			*moveLeft = new Text();
	moveLeft->setString("MOVE LEFT");
	moveLeft->setSize(15);
	moveLeft->setStyle(1);
	moveLeft->setOrigin(moveLeft->getText().getGlobalBounds().width / 2, moveLeft->getText().getGlobalBounds().height / 2);
	moveLeft->setPosition(Vector2(window->getSize()._x * 0.64, window->getSize()._y * 0.38));
	moveLeft->setColor(Color::WHITE);
	_labels.push_back(*moveLeft);

	Text			*moveRight = new Text();
	moveRight->setString("MOVE RIGHT");
	moveRight->setSize(15);
	moveRight->setStyle(1);
	moveRight->setOrigin(moveRight->getText().getGlobalBounds().width / 2, moveRight->getText().getGlobalBounds().height / 2);
	moveRight->setPosition(Vector2(window->getSize()._x * 0.64, window->getSize()._y * 0.45));
	moveRight->setColor(Color::WHITE);
	_labels.push_back(*moveRight);

	Text			*shoot = new Text();
	shoot->setString("SHOOT");
	shoot->setSize(15);
	shoot->setStyle(1);
	shoot->setOrigin(shoot->getText().getGlobalBounds().width / 2, shoot->getText().getGlobalBounds().height / 2);
	shoot->setPosition(Vector2(window->getSize()._x * 0.64, window->getSize()._y * 0.51));
	shoot->setColor(Color::WHITE);
	_labels.push_back(*shoot);

	Text			*weapon1 = new Text();
	weapon1->setString("WEAPON 1");
	weapon1->setSize(15);
	weapon1->setStyle(1);
	weapon1->setOrigin(weapon1->getText().getGlobalBounds().width / 2, weapon1->getText().getGlobalBounds().height / 2);
	weapon1->setPosition(Vector2(window->getSize()._x * 0.64, window->getSize()._y * 0.57));
	weapon1->setColor(Color::WHITE);
	_labels.push_back(*weapon1);

	Text			*weapon2 = new Text();
	weapon2->setString("WEAPON 2");
	weapon2->setSize(15);
	weapon2->setStyle(1);
	weapon2->setOrigin(weapon2->getText().getGlobalBounds().width / 2, weapon2->getText().getGlobalBounds().height / 2);
	weapon2->setPosition(Vector2(window->getSize()._x * 0.64, window->getSize()._y * 0.63));
	weapon2->setColor(Color::WHITE);
	_labels.push_back(*weapon2);

	Text			*weapon3 = new Text();
	weapon3->setString("WEAPON 3");
	weapon3->setSize(15);
	weapon3->setStyle(1);
	weapon3->setOrigin(weapon3->getText().getGlobalBounds().width / 2, weapon3->getText().getGlobalBounds().height / 2);
	weapon3->setPosition(Vector2(window->getSize()._x * 0.64, window->getSize()._y * 0.7));
	weapon3->setColor(Color::WHITE);
	_labels.push_back(*weapon3);

	Text			*leaveGame = new Text();
	leaveGame->setString("LEAVE GAME");
	leaveGame->setSize(15);
	leaveGame->setStyle(1);
	leaveGame->setOrigin(leaveGame->getText().getGlobalBounds().width / 2, leaveGame->getText().getGlobalBounds().height / 2);
	leaveGame->setPosition(Vector2(window->getSize()._x * 0.64, window->getSize()._y * 0.76));
	leaveGame->setColor(Color::WHITE);
	_labels.push_back(*leaveGame);

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
    _tmp->setBind(&bind);
}

void    SettingsPanel::defaultSettings()
{
	RenderWindow	*window = RenderWindow::getInstance();
	SettingsLoader *loader = new SettingsLoader(false);
	std::vector<Bind*> binds = loader->createDefaultBinds();
	std::vector<Bind*>::const_iterator it = binds.begin();
	std::vector<Bind*>::const_iterator end = binds.end();
	int id = 3;

	while (it != end)
	{
		(window->getPanels().top()->getLabels().at(id)).setString(loader->keyToString((*it)->getKey()));
		(window->getPanels().top()->getLabels().at(id)).setOrigin((window->getPanels().top()->getLabels().at(id)).getText().getGlobalBounds().width / 2, (window->getPanels().top()->getLabels().at(id)).getText().getGlobalBounds().height / 2);
		id++;
		(window->getPanels().top()->getLabels().at(id)).setString(loader->joystickToString((*it)->getJoystick()));
		(window->getPanels().top()->getLabels().at(id)).setOrigin((window->getPanels().top()->getLabels().at(id)).getText().getGlobalBounds().width / 2, (window->getPanels().top()->getLabels().at(id)).getText().getGlobalBounds().height / 2);
		id++;
		it++;
	}

	_tmp->resetDefault();
	_global->getSprite().setPosition(window->getSize()._x * 0.05 + _tmp->getVolume().getGlobal() * 7, window->getSize()._y * 0.25);
	_effects->getSprite().setPosition(window->getSize()._x * 0.05 + _tmp->getVolume().getEffects() * 7, window->getSize()._y * 0.35);
	_music->getSprite().setPosition(window->getSize()._x * 0.05 + _tmp->getVolume().getMusic() * 7, window->getSize()._y * 0.45);
	_global->setValue(_tmp->getVolume().getGlobal());
	_effects->setValue(_tmp->getVolume().getEffects());
	_music->setValue(_tmp->getVolume().getMusic());
}

void    SettingsPanel::back()
{
	RenderWindow	*window = RenderWindow::getInstance();
	int				global = window->getSettings()->getVolume().getGlobal();
	int				effects = window->getSettings()->getVolume().getEffects();
	int				music = window->getSettings()->getVolume().getMusic();

	Client::getSound()->setEffectsVolume((global * effects) / 100);
	Client::getSound()->setEffectsVolume((global * music) / 100);
	window->back();
}

int		SettingsPanel::getType()
{
	return _type;
}

void    SettingsPanel::save()
{
	SettingsLoader *loader = new SettingsLoader(true);
	loader->saveSettings(_tmp);
	RenderWindow::getInstance()->setSettings(_tmp);
}

Settings	*SettingsPanel::getTemporarySettings() const
{
	return _tmp;
}
