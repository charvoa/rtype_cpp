//
// Volume.cpp for Volume in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:52:07 2015 Viveka BARNEAUD
// Last update Mon Nov 30 09:52:08 2015 Viveka BARNEAUD
//

#include "Volume.hh"

Volume::Volume(int global, int effects, int music)
{
    _global = global;
    _effects = effects;
    _music = music;
}

Volume::~Volume(){}

int     Volume::getGlobal() const
{
    return _global;
}

int     Volume::getEffects() const
{
    return _effects;
}

int     Volume::getMusic() const
{
    return _music;
}

void    Volume::setGlobal(int global)
{
    _global = global;
}

void    Volume::setEffects(int effects)
{
    _effects = effects;
}

void    Volume::setMusic(int music)
{
    _music = music;
}
