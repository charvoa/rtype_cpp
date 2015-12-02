#include "volume.h"

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
