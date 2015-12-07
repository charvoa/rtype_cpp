//
// Game.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:45:38 2015 Nicolas Charvoz
// Last update Mon Dec  7 15:21:01 2015 Nicolas Charvoz
//

#include <Game.hh>

Game::Game() {}

Game::Game(const Parameters &params_, std::vector<Client> &client_,
	   const std::string &id_) : _params(params_), _id(id_)
{
  this->addClients(client_);
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

bool Game::run()
{

  return true;
}

void Game::addCommandToQueue(ANetwork::t_frame frame)
{
  _commandQueue.push((E_COMMAND)frame.idRequest);
}

const std::string &Game::getId() const
{
  return _id;
}
