//
// Game.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:45:38 2015 Nicolas Charvoz
// Last update Wed Dec  2 09:24:07 2015 Nicolas Charvoz
//

#include "Game.hh"

Game::Game() {}

Game::~Game() {}

void Game::addPlayers(std::vector<Player> &) {}

void Game::setParameters(Parameters &p)
{
  _params = p;
}

bool Game::run() {}

void Game::addCommandToQueue(ANetwork::t_frame frame) {}
