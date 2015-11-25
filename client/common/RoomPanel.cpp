#include "RoomPanel.hh"

RoomPanel::RoomPanel(RenderWindow *parent) : APanel(parent)
{
}

RoomPanel::~RoomPanel() {}

void    RoomPanel::difficulty(Settings::Difficulty diff)
{
    _parent->getSettings->setDifficulty(diff);
}

void    RoomPanel::start()
{

}

void    RoomPanel::back()
{

}
