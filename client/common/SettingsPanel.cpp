//
// SettingsPanel.cpp for SettingsPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:50:13 2015 Viveka BARNEAUD
// Last update Thu Dec  3 14:01:46 2015 Serge Heitzler
//

#include "SettingsLoader.hh"
#include "RenderWindow.hh"
#include "PanelFactory.hh"
#include "SettingsPanel.hh"
#include "ButtonFactory.hh"

SettingsPanel::SettingsPanel()
{
	_tmp = new Settings(std::string("../config/PersonnalConfig.ini"));
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

	// Button

	std::string name = "SAVE";
	ButtonFactory::create(Vector2(window->getSize()._x * 0.25, window->getSize()._y * 0.8), name);
	name = "DEFAULT";
	ButtonFactory::create(Vector2(window->getSize()._x * 0.5, window->getSize()._y * 0.8), name);
	name = "BACK";
	ButtonFactory::create(Vector2(window->getSize()._x * 0.75, window->getSize()._y * 0.8), name);

	_functions.push_back((APanel::funcs)&SettingsPanel::save);
	_functions.push_back((APanel::funcs)&SettingsPanel::defaultSettings);
	_functions.push_back((APanel::funcs)&SettingsPanel::back);

	std::vector<Bind*> binds = _tmp->getBinds();
	std::vector<Bind*>::const_iterator it = binds.begin();
	std::vector<Bind*>::const_iterator end = binds.end();
	SettingsLoader *loader = new SettingsLoader();
	int	layout = 0;
	int id = window->getPanels().top()->getLabels().size();

	while (it != end)
	{
		name = loader->keyToString((*it)->getKey());
		ButtonFactory::createKeyButton(Vector2(window->getSize()._x * 0.7, window->getSize()._y * 0.2 + layout), name, id++);
		name = loader->joystickToString((*it)->getJoystick());
		ButtonFactory::createKeyButton(Vector2(window->getSize()._x * 0.7 + (window)->_ressources->_buttonNormal->getSize()._x / 2, window->getSize()._y * 0.2 + layout), name, id++);
		layout += (window)->_ressources->_buttonNormal->getSize()._y / 2;
		++it;
	}

	name = "global";
	_global = ButtonFactory::createSlider(Vector2((window->getSize()._x * 0.05) + _tmp->getVolume().getGlobal() * 7, window->getSize()._y * 0.25), name, (window->getSize()._x * 0.05), (window->getSize()._x * 0.05) + 700);
	name = "effects";
	_effects = ButtonFactory::createSlider(Vector2((window->getSize()._x * 0.05) + _tmp->getVolume().getEffects() * 7, window->getSize()._y * 0.35), name, (window->getSize()._x * 0.05), (window->getSize()._x * 0.05) + 700);
	name = "music";
	_music = ButtonFactory::createSlider(Vector2((window->getSize()._x * 0.05) + _tmp->getVolume().getMusic()* 7, window->getSize()._y * 0.45), name, (window->getSize()._x * 0.05), (window->getSize()._x * 0.05) + 700);

	Text		       	*title = new Text();

	title->setString("SETTINGS");
	title->setSize(80);
	title->setStyle(1);
	title->setOrigin(title->getText().getGlobalBounds().width / 2, title->getText().getGlobalBounds().height / 2);
	title->setPosition(Vector2(window->getSize()._x * 0.5, window->getSize()._y * 0.05));
	title->setColor(Color::WHITE);
	_labels.push_back(*title);
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
	std::vector<Bind*> binds = _tmp->getBinds();
	std::vector<Bind*>::const_iterator it = binds.begin();
	std::vector<Bind*>::const_iterator end = binds.end();
	SettingsLoader *loader = new SettingsLoader();
	int id = 3;

	while (it != end)
	{
		(window->getPanels().top()->getLabels().at(id)).setString(loader->keyToString((*it)->getKey()));
		id++;
		(window->getPanels().top()->getLabels().at(id)).setString(loader->joystickToString((*it)->getJoystick()));
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
	RenderWindow::getInstance()->back();
}

void    SettingsPanel::save()
{
	SettingsLoader *loader = new SettingsLoader();
	loader->saveSettings(_tmp);
	RenderWindow::getInstance()->setSettings(_tmp);
}
