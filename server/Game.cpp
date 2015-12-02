//
// Game.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:45:38 2015 Nicolas Charvoz
// Last update Wed Dec  2 17:18:38 2015 Nicolas Charvoz
//

#include "Game.hh"

Game::Game() {}

Game::Game(const Parameters &params_, const Client &client_, int id_)
  : _params(params_), _id(id_), _client(client_)
{
}

Game::~Game() {}

void Game::addClients(std::vector<Client> &p)
{
  for (std::vector<Client>::iterator it = p.begin();
       it != p.end() ; ++it)
    {
      _eM.createEntity(E_PLAYER, (*it));
    }
}

void Game::setParameters(Parameters &p)
{
  _params = p;
}

bool Game::run() {
  return true;
}

void Game::addCommandToQueue(ANetwork::t_frame frame) {
  _commandQueue.push((E_COMMAND)frame._idRequest);
}
