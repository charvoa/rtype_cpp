//
// Game.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:45:38 2015 Nicolas Charvoz
//

#include <Game.hh>
#include <Timer.hpp>
#include <Random.hpp>

Game::Game()
{
  _mutex = new Mutex();
}

Game::Game(const Parameters &params_, std::vector<Client *> &client_,
	   const std::string &id_, int port_) : _params(params_), _id(id_)
{
  srand(time(NULL));

  this->_clients = client_;
  this->_network = new Network();
  this->_network->init(port_ + 1, ANetwork::UDP_MODE);
  this->_network->bind();
  this->addClients(client_);
  _stage = 1;
  _nbDisplay = 0;

  _funcMap.insert(std::make_pair(C_HANDSHAKE_UDP, &Game::handleHandshakeUDP));
  _funcMap.insert(std::make_pair(C_MOVE, &Game::handleMove));

}

Game::~Game() {}

void Game::addClients(std::vector<Client *> &p)
{
  for (std::vector<Client *>::iterator it = p.begin();
       it != p.end() ; ++it)
    {
      _eM.createEntity(E_PLAYER, *(*it));
    }
}

void Game::setParameters(Parameters &p)
{
  _params = p;
}

Client *Game::getClientBySocket(ISocket *socket) const
{
  for (std::vector<Client*>::const_iterator it = _clients.begin();
       it != _clients.end(); ++it)
    {
      if ((*it)->getUDPSocket() == socket)
	{
	  return (*it);
	}
    }
  throw std::logic_error("Cannot find this client by socket");
}

Player *Game::getPlayerByClient(Client *client)
{
  std::vector<AEntity*> _players = _eM.getEntitiesByType(E_PLAYER);

  for (std::vector<AEntity*>::iterator it = _players.begin();
       it != _players.end();
       ++it)
    {
      if ((reinterpret_cast<Player*>(*it))->getClient().getUDPSocket()->getFd()
	   == client->getUDPSocket()->getFd())
	{
	  return reinterpret_cast<Player*>(*it);
	}
    }
  throw std::logic_error("Cannot find this player by client");
}

void Game::handleHandshakeUDP(void *data, Client *client)
{
  std::cout << "Game :: handleHandshakeUDP " << std::endl;
  std::vector<AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
  for (std::vector<AEntity *>::iterator it = _players.begin(); it != _players.end(); ++it)
    {
      if (dynamic_cast<Player*>((*it))->getClient().getSocket()->getFd() == std::atoi(((ANetwork::t_frame*)data)->data))
	{
	  std::cout << "JE RENTRE" << std::endl;
	  dynamic_cast<Player*>((*it))->getClient().setUDPSocket(client->getSocket());
	  std::cout << dynamic_cast<Player*>((*it))->getClient().getUDPSocket()->getFd() << std::endl;
	}
    }
  // for (std::vector<Client*>::iterator it = this->_clients.begin();
  //      it != this->_clients.end() ; ++it)
  //   {
  //     if ((*it)->getSocket()->getFd() == std::atoi(((ANetwork::t_frame*)data)->data))
  // 	{
  // 	  (*it)->setUDPSocket(client->getUDPSocket());
  // 	}
  //   }
}

void Game::handleMove(void *data, Client *client)
{
  // Game::dataThread *s = reinterpret_cast<Game::dataThread*>(sData);

  // Game *me = s->game;

  std::cout << "Game :: handleMove" << std::endl;
  try {
    Player *player = this->getPlayerByClient(client);

    std::stringstream ss;

    ComponentPosition *pPlayer =
      reinterpret_cast<ComponentPosition*>(player->getSystemManager()
				  ->getSystemByComponent(E_POSITION)
				  ->getComponent());
    //std::cout << "Player X : " << pPlayer->getX() << " " << "Player Y : "
      //	      << std::cout << pPlayer->getY();
    player->update(1, 1);

    ANetwork::t_frame frameToSend = CreateRequest::create((unsigned char)S_DISPLAY, CRC::calcCRC(ss.str().c_str()), 0, ss.str().c_str());
    client->getSocket()->write(reinterpret_cast<void*>(&frameToSend), sizeof(ANetwork::t_frame));
  } catch (const std::exception &e) {
    std::cout << "Cannot move" << std::endl;
  }

}

void Game::updateScore(Player *p, Game::scoreDef score)
{
  p->setScore(p->getScore() + score);
}

void Game::updateLife(Player *p, bool reset)
{
  ComponentHealth *hP =
    reinterpret_cast<ComponentHealth*>(p->getSystemManager()
				->getSystemByComponent(E_POSITION)
				->getComponent());
  if (!reset)
    p->update(hP->getLife() - 1);
  else
    p->update(3);
}

void Game::handleShoot(void *data, Client *client)
{
  char *weaponType =
    ((reinterpret_cast<ANetwork::t_frame*>(data))->data);


  Player *p = this->getPlayerByClient(client);
  //_eM.createEntity();
}

void Game::handleCommand(void *data, Client *client)
{
  std::cout << "Game :: handleCommand" << std::endl;
  std::cout << "ID Request: |" << ((ANetwork::t_frame*)data)->idRequest
	    << "|" << std::endl;

  E_Command commandType =
    static_cast<E_Command>((reinterpret_cast<ANetwork::t_frame*>(data))->idRequest);

  try {
    Func fp = _funcMap[commandType];
    (this->*fp)(data, client);
  } catch (const std::exception &e) {
    std::cout << "Cannot achieve this action" << std::endl;
  }

}

void *readThread(void *sData)
{
  Game::dataThread *s = reinterpret_cast<Game::dataThread*>(sData);

  ANetwork *n = s->network;
  Game *me = s->game;

  std::cout << "Game :: readThread" << std::endl;
  void *data;

  while (1)
    {
      std::cout << "Je suis bloqué avant le select .." << std::endl;
      Client *client = new Client(n->select());
      std::cout << "APres le select()" << std::endl;
      if (!(data = client->getSocket()->read(sizeof(ANetwork::t_frame))))
	{
	  n->unlistenSocket(client->getSocket());
	  continue;
	}
      me->handleCommand(data, client);
    }
}

int Game::getNumberEnemyMax()
{
  int	nbEnemy = 5 * _stage * _params.getDifficulty() * _eM.getEntitiesByType(E_PLAYER).size();
  return nbEnemy;
}

void Game::addMonster()
{
  if (_nbDisplay < getNumberEnemyMax())
    {
      std::cout << "Add Monster" << std::endl;
      _nbDisplay++;
    }
  else
    std::cout << "Monster Full for this Stage" << std::endl;
}

void Game::initPlayersPosition()
{
  int	x = 10;
  std::vector<AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
  std::vector<AEntity *>::iterator it;
  Random	rand(0,255);
  for (it = _players.begin(); it != _players.end(); ++it)
    {
      ComponentPosition *p = reinterpret_cast<ComponentPosition *>((*it)->getSystemManager()->getSystemByComponent(E_POSITION)->getComponent());
      (*it)->update(x, rand.generate<int>());
    }
}

void Game::sendGameData()
{
  std::vector<AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
  std::vector<AEntity *> _entities = _eM.getEntities();

  for (std::vector<AEntity *>::const_iterator it = _players.begin(); it != _players.end(); ++it)
    {
      for (std::vector<AEntity *>::iterator it2 = _entities.begin(); it2 != _entities.end(); ++it2)
	{
	  ComponentPosition *pPlayer = reinterpret_cast<ComponentPosition *>((*it2)->getSystemManager()->getSystemByComponent(E_POSITION)->getComponent());
	  //	  std::string sendData = (*it2)->getName() + ";" + std::to_string(pPlayer->getX()) + ";" + std::to_string(pPlayer->getY());
	  std::string sendData = (*it2)->getId() + ";" + std::to_string(pPlayer->getX()) + ";" + std::to_string(pPlayer->getY());
	  ANetwork::t_frame frameToSend = CreateRequest::create(S_DISPLAY, CRC::calcCRC(sendData), 0, sendData);
	  if (!(dynamic_cast<Player*>((*it))->getClient().getUDPSocket()))
	    std::cout << "NULL UDP" << std::endl;
	    else
	      {
		std::cout << "JE SEND" << std::endl;
		reinterpret_cast<Player*>((*it))->getClient().getUDPSocket()->write(reinterpret_cast<void*>(&frameToSend), sizeof(ANetwork::t_frame));
	      }
	}
    }
}

bool Game::run()
{
  Timer	timer(true);
  int	speed = 3;
  ThreadFactory *tF = new ThreadFactory;
  std::unique_ptr<AThread> t1(tF->createThread());

  Game::dataThread *dT = new Game::dataThread;

  dT->game = this;
  dT->network = this->_network;
  t1->attach(&readThread, reinterpret_cast<void*>(dT));

  t1->run();
  initPlayersPosition();
  while (true)
    {
      if (timer.elapsed().count() >= (speed/_stage))
	{
	  timer.reset();
	  addMonster();
	}
      sendGameData();
      //      std::cout << "nb of enemy = " << nbEnemy << std::endl;
      // nbEnemy = 5 * stage * nbEnemy;
    }


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
  _mutex->lock();
  _commandQueue.push(frame);
  _mutex->unlock();
}

const std::string &Game::getId() const
{
  return _id;
}
