#include "Slider.hh"
#include "SettingsPanel.hh"
#include "Client.hh"
#include "Ressources.hh"
#include <CRC.hpp>
#include <E_Difficulty.hh>

Slider::Slider(std::string const& title)
{
  _title = title;
  _locked = true;
}


Slider::~Slider()
{
}

void		Slider::setPosX(float x)
{
  _sprite->setPosition(x, getPosY());
}

void		Slider::setTitle(std::string const& title)
{
  _title = title;
}

void		Slider::setValue(int val)
{
  _value = val;
}

void			Slider::setState(Button::StateButton state)
{
  _state = state;
}

std::string		Slider::getTitle() const
{
  return _title;
}

int				Slider::getValue() const
{
  return _value;
}

void			Slider::render()
{

}

void			Slider::setLimit(float xmin, float xmax)
{
  _minX = xmin;
  _maxX = xmax;
}

float			Slider::getPosX()
{
  return _sprite->getPosX();
}

float			Slider::getPosY()
{
  return _sprite->getPosY();
}

void			Slider::updateOnMove(std::pair<unsigned int, unsigned int> pair)
{
  std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>> rect = this->getSprite().getGlobalBounds();

  if (_title == "difficulty")
    {
      difficultyUpdateOnMove(pair);
      return;
    }
  if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
    {
      if (_locked == false)
	{
	  if (pair.first <= _maxX && pair.first >= _minX)
	    this->getSprite().setPosition(pair.first, getPosY());
	}
    }
}

bool			Slider::updateOnPress(std::pair<unsigned int, unsigned int> pair)
{
  RenderWindow	*window = RenderWindow::getInstance();
  std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>> rect = this->getSprite().getGlobalBounds();

  if (_title == "difficulty")
    return difficultyUpdateOnPress(pair);

  if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
    {
      _locked = false;
    }
  else if (pair.first <= _maxX && pair.first >= _minX && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
    {
      this->setValue((pair.first - _minX) / 7);
      this->getSprite().setPosition(pair.first, getPosY());
      if (_title == "global")
	{
	  dynamic_cast<SettingsPanel*>(window->getPanels().top())->setGlobalVolume(_value);
	  Client::getSound()->setEffectsVolume(_value);
	  Client::getSound()->setMusicVolume(_value);
	}
      else if (_title == "effects")
	{
	  dynamic_cast<SettingsPanel*>(window->getPanels().top())->setEffectsVolume(_value);
	  Client::getSound()->setEffectsVolume(_value);
	}
      else if (_title == "music")
	{
	  dynamic_cast<SettingsPanel*>(window->getPanels().top())->setMusicVolume(_value);
	  Client::getSound()->setMusicVolume(_value);
	}
    }
  return false;
}

void			Slider::updateOnRelease(std::pair<unsigned int, unsigned int> pair)
{
  RenderWindow	*window = RenderWindow::getInstance();

  if (_title == "difficulty")
    {
      difficultyUpdateOnRelease(pair);
      return;
    }

  if (_locked == true)
    return;
  if (pair.first > _maxX)
    this->setValue(100);
  if (pair.first < _minX)
    this->setValue(0);
  else
    this->setValue((pair.first - _minX) / 7);
  if (_title == "global")
    {
      dynamic_cast<SettingsPanel*>(window->getPanels().top())->setGlobalVolume(_value);
      Client::getSound()->setEffectsVolume(_value);
      Client::getSound()->setMusicVolume(_value);
    }
  else if (_title == "effects")
    {
      dynamic_cast<SettingsPanel*>(window->getPanels().top())->setEffectsVolume(_value);
      Client::getSound()->setEffectsVolume(_value);
    }
  else if (_title == "music")
    {
      dynamic_cast<SettingsPanel*>(window->getPanels().top())->setMusicVolume(_value);
      Client::getSound()->setMusicVolume(_value);
    }
  Client::getSound()->setMusicVolume(_value);
  Client::getSound()->setEffectsVolume(_value);
  _locked = true;
}

void			Slider::difficultyUpdateOnMove(std::pair<unsigned int, unsigned int> pair)
{
  std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>> rect = this->getSprite().getGlobalBounds();
  RenderWindow *window = RenderWindow::getInstance();

  float origin = (window->getSize()._x / 2) - (window->_ressources->_slide->getSize()._x / 2);
  float cursor = pair.first - _minX;

  if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
    {
      if (_locked == false)
	{
	  if (pair.first <= _maxX && pair.first >= _minX)
	    {
	      if (cursor <= window->_ressources->_slide->getSize()._x / 3)
		{
		  this->setValue(1);
		  this->getSprite().setPosition(origin + window->_ressources->_sliderNormal->getSize()._x / 3, getPosY());
		}
	      else if (cursor <= 2 * window->_ressources->_slide->getSize()._x / 3)
		{
		  this->setValue(2);
		  this->getSprite().setPosition(origin + window->_ressources->_slide->getSize()._x / 2, getPosY());
		}
	      else
		{
		  this->setValue(3);
		  this->getSprite().setPosition(origin + window->_ressources->_slide->getSize()._x - window->_ressources->_sliderNormal->getSize()._x / 3, getPosY());
		}
	    }
	}
    }
}

bool			Slider::difficultyUpdateOnPress(std::pair<unsigned int, unsigned int> pair)
{
  RenderWindow	*window = RenderWindow::getInstance();
  std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>> rect = this->getSprite().getGlobalBounds();
  float origin = (window->getSize()._x / 2) - (window->_ressources->_slide->getSize()._x / 2);
  ANetwork *net = Client::getNetwork();
  ANetwork::t_frame sender;
  std::string diff;

  if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
    {
      _locked = false;
    }
  else if (pair.first <= _maxX && pair.first >= _minX && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
    {
      pair.first -= _minX;
      if (pair.first <= window->_ressources->_slide->getSize()._x / 3)
	{
	  diff = std::to_string(E_EASY);
	  this->setValue(1);
	  this->getSprite().setPosition(origin + window->_ressources->_sliderNormal->getSize()._x / 3, getPosY());
	}
      else if (pair.first <= 2 * window->_ressources->_slide->getSize()._x / 3)
	{
	  diff = std::to_string(E_MEDIUM);
	  this->setValue(2);
	  this->getSprite().setPosition(origin + window->_ressources->_slide->getSize()._x / 2, getPosY());
	}
      else
	{
	  diff = std::to_string(E_HARD);
	  this->setValue(3);
	  this->getSprite().setPosition(origin + window->_ressources->_slide->getSize()._x - window->_ressources->_sliderNormal->getSize()._x / 3, getPosY());
	}
      std::cout << "SENDING DATA ::" << diff << std::endl;
      sender = CreateRequest::create((unsigned char)C_CHANGE_SETTINGS, CRC::calcCRC(diff), 0, diff);
      net->write(sender);
    }
  return false;
}

void			Slider::difficultyUpdateOnRelease(std::pair<unsigned int, unsigned int> pair)
{
  RenderWindow	*window = RenderWindow::getInstance();
  ANetwork *net = Client::getNetwork();
  ANetwork::t_frame sender;
  std::string diff = "";

  (void)pair;
  _locked = true;
  switch (_value)
    {
    case 1:
      {
	diff = std::to_string(E_EASY);
	window->getSettings()->setDifficulty(Settings::EASY_MODE);
	break;
      }
    case 2:
      {
	diff = std::to_string(E_MEDIUM);
	window->getSettings()->setDifficulty(Settings::MEDIUM_MODE);
	break;
      }
    case 3:
      {
	diff = std::to_string(E_HARD);
	window->getSettings()->setDifficulty(Settings::HARD_MODE);
	break;
      }
    default:
      {
	diff = std::to_string(E_MEDIUM);
	window->getSettings()->setDifficulty(Settings::MEDIUM_MODE);
	break;
      }
    }
  std::cout << "SENDING DATA ::" << diff << std::endl;
  sender = CreateRequest::create((unsigned char)C_CHANGE_SETTINGS, CRC::calcCRC(diff), 0, diff);
  net->write(sender);
}
