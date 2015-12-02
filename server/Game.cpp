//
// Game.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:45:38 2015 Nicolas Charvoz
// Last update Wed Dec  2 11:32:23 2015 Nicolas Charvoz
//

#include "Game.hh"

Game::Game(const Parameters &params_, const Client &client_, int id_)
  : _params(params_), _client(client_), _id(id_)
{
}

Game::~Game() {}

void Game::addClients(std::vector<Client> &p)
{
}

void Game::setParameters(Parameters &p)
{
  _params = p;
}

bool Game::run() {}

void Game::addCommandToQueue(ANetwork::t_frame frame) {}
