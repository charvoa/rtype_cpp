//
// Slider.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Sun Dec 27 08:04:03 2015 Serge Heitzler
// Last update Sun Dec 27 08:04:23 2015 Serge Heitzler
//

#pragma once

#include <AMenuElement.hh>
#include <RenderWindow.hh>
#include <Button.hh>

class Slider :	public AMenuElement
{
public:
Slider(std::string const&);
~Slider();

std::string	getTitle() const;
int			getValue() const;

void		setTitle(std::string const&);
void		setValue(int);
void		render();
void		setState(Button::StateButton state);
bool		updateOnPress(std::pair<unsigned int, unsigned int>);
void		updateOnRelease(std::pair<unsigned int, unsigned int>);
void		updateOnMove(std::pair<unsigned int, unsigned int>);
float		getPosY();
float		getPosX();
void		setLimit(float, float);
bool		difficultyUpdateOnPress(std::pair<unsigned int, unsigned int>);
void		difficultyUpdateOnRelease(std::pair<unsigned int, unsigned int>);
void		difficultyUpdateOnMove(std::pair<unsigned int, unsigned int>);

private:
float		_minX;
float		_maxX;
bool		_locked;
Button::StateButton	_state;
std::string	_title;
int			_value;
};
