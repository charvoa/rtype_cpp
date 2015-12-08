//
// Game.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:45:38 2015 Nicolas Charvoz
// Last update Tue Dec  8 15:44:09 2015 Nicolas Charvoz
//

#include <Game.hh>

Game::Game() {}

Game::Game(const Parameters &params_, std::vector<Client> &client_,
	   const std::string &id_) : _params(params_), _id(id_)
{
  //  srand(time(NULL));


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
  //CREATE NB OF BASE ENEMY

  // CREATE ENEMY

  // WHILE !GAME_OVER
  //---WHILE ENEMY > 0
  // POP RANDOM TYPE ENEMY

  // CHECK ENEMY
  // MOVE ENEMY
  // CHECK IF ENEMY HAS GONE THROUGH MAP = DEAD
  // ENEMY = 5 * STAGE * DIFF
  // CHECK IF STAGE % 5 -> POP BOSS (LIFE *= DIFFICULTY)
  // RANDOM BONUS POP
  // --- IF DESTROYED BONUS GOT


  return true;
}

void Game::addCommandToQueue(ANetwork::t_frame frame)
{
  _commandQueue.push(frame);
}

const std::string &Game::getId() const
{
  return _id;
}
