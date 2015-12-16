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
}

Game::Game(const Parameters &params_, std::list<Client *> &client_,
	   const std::string &id_, int port_, std::list<Bot*> botList_)
  : _params(params_), _id(id_), _botList(botList_)
{
  srand(time(NULL));

  _mutex = new Mutex();
  this->_clients = client_;
  this->_network = new Network();
  this->_network->init(port_ + 1, ANetwork::UDP_MODE);
  this->_network->bind();
  this->addClients(client_);
  _stage = 1;
  _nbDisplay = 0;

  _funcMap.insert(std::make_pair(C_HANDSHAKE_UDP, &Game::handleHandshakeUDP));
  _funcMap.insert(std::make_pair(C_MOVE, &Game::handleMove));
  _funcMap.insert(std::make_pair(C_SHOOT, &Game::handleShoot));
}

Game::~Game() {}

void Game::addClients(std::list<Client *> &p)
{
  for (std::list<Client *>::iterator it = p.begin();
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
  for (std::list<Client*>::const_iterator it = _clients.begin();
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
  std::list<AEntity*> _players = _eM.getEntitiesByType(E_PLAYER);

  for (std::list<AEntity*>::iterator it = _players.begin();
       it != _players.end();
       ++it)
    {
      Player *ptmp = reinterpret_cast<Player*>(*it);
      if (ptmp->getClient().getUDPSocket()->isEqualTo(client->getSocket()))
	return (ptmp);
    }

  throw std::logic_error("Cannot find this player by client");

}

void Game::handleHandshakeUDP(void *data, Client *client)
{
  std::cout << "Game :: handleHandshakeUDP " << std::endl;

  std::list<AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
  for (std::list<AEntity *>::iterator it = _players.begin(); it != _players.end(); ++it)
    {
      if (dynamic_cast<Player*>((*it))->getClient().getSocket()->getFd() == std::atoi(((ANetwork::t_frame*)data)->data))
	{
	  printf("Entre dans le if dans HandShake UDP\n");
	  dynamic_cast<Player*>((*it))->getClient().setUDPSocket(client->getSocket());
	  printf("Apres le setUDPSocket\n");
	}
    }

}

std::pair<int, int> Game::getDirections(const std::string &dir)
{
  std::pair<int, int> final;

  if (dir == "1")
    final = std::make_pair(0, -1);
  else if (dir == "3")
    final = std::make_pair(1, -1);
  else if (dir == "2")
    final = std::make_pair(1, 0);
  else if (dir == "6")
    final = std::make_pair(1, 1);
  else if (dir == "4")
    final = std::make_pair(0, 1);
  else if (dir == "12")
    final = std::make_pair(-1, 1);
  else if (dir == "8")
    final = std::make_pair(-1, 0);
  else if (dir == "9")
    final = std::make_pair(-1, -1);
  else
    final = std::make_pair(0, 0);
  return final;
}

bool Game::checkMove(int x, int y)
{
  if (x < 0 || x > 110)
    return false;
  else if (y < 0 || y > 50)
    return false;
  return true;
}

void Game::checkWall(Player *player)
{
  ComponentPosition *pPlayer;


  pPlayer =
    reinterpret_cast<ComponentPosition*>(player->getSystemManager()
					 ->getSystemByComponent(C_POSITION)
					 ->getComponent());
  if (pPlayer->getY() <= 1 || pPlayer->getY() >= 49)
    {
      this->updateLife(player, 2);
    }
}

void Game::handleMove(void *data, Client *client)
{
  std::cout << "Game :: handleMove" << std::endl;
  ComponentPosition *pPlayer;
  try {
    Player *player = this->getPlayerByClient(client);

    std::stringstream ss;

    //if (reinterpret_cast<Mutex*>(_mutex)->try_lock()) {
    pPlayer =
      reinterpret_cast<ComponentPosition*>(player->getSystemManager()
					   ->getSystemByComponent(C_POSITION)
					   ->getComponent());
    //
    auto newMove = this->getDirections((reinterpret_cast<ANetwork::t_frame*>(data))->data);

    // std::cout << "Position of player before move : " << pPlayer->getX() << " | " << pPlayer->getY() << std::endl;
    // std::cout << "Position of player before move : " << pPlayer->getX() + newMove.first  << " | " << pPlayer->getY() + newMove.second << std::endl;
    if (this->checkMove(pPlayer->getX() + newMove.first, pPlayer->getY() + newMove.second))
      {
	this->checkWall(player);
	//	if (reinterpret_cast<Mutex*>(_mutex)->try_lock()) {
	player->update(pPlayer->getX() + newMove.first, pPlayer->getY() + newMove.second);
	//      	} reinterpret_cast<Mutex*>(_mutex)->unlock();
      }
  } catch (const std::exception &e) {
    std::cout << "Cannot move : " << e.what() << std::endl;
  }

}

void Game::updateScore(Player *p, Game::scoreDef score)
{
  std::list <AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
  p->setScore(p->getScore() + score);
  std::string sendData = p->getName() + ";" + std::to_string(p->getScore());
  ANetwork::t_frame frame = CreateRequest::create(S_SCORE, CRC::calcCRC(sendData), sendData.size(), sendData);
  for (std::list<AEntity *>::iterator it = _players.begin(); it != _players.end() ; ++it)
    {
      dynamic_cast<Player*>((*it))->getClient().getUDPSocket()->write(reinterpret_cast<void*>(&frame), sizeof(ANetwork::t_frame));
    }

}

void Game::updateLife(Player *p, int reset)
{

  std::cout << "UPDATE LIFE " << std::endl;
  ComponentHealth *hP =
    reinterpret_cast<ComponentHealth*>(p->getSystemManager()
				       ->getSystemByComponent(C_HEALTH)
				       ->getComponent());
  if (reset == 0)
    p->update(hP->getLife() - 1);
  else if (reset == 1)
    p->update(3);
  else if (reset == 2)
    p->update(0);

  std::stringstream health;

  health << p->getName() << ";" << hP->getLife();
  ANetwork::t_frame frameHealth = CreateRequest::create(S_LIFE, CRC::calcCRC(health.str().c_str()), health.str().size(), health.str().c_str());
  ANetwork::t_frame frameDie;
  if (hP->getLife() == 0){
    std::string sendData = std::to_string(p->getId());
    frameDie = CreateRequest::create(S_DIE, CRC::calcCRC(sendData), sendData.size(), sendData);
  }
  std::list <AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
  for (std::list<AEntity *>::iterator it = _players.begin(); it != _players.end() ; ++it)
    {
      if (hP->getLife() == 0)
	dynamic_cast<Player*>((*it))->getClient().getUDPSocket()->write(reinterpret_cast<void*>(&frameDie), sizeof(ANetwork::t_frame));
      dynamic_cast<Player*>((*it))->getClient().getUDPSocket()->write(reinterpret_cast<void*>(&frameHealth), sizeof(ANetwork::t_frame));
    }

}

void Game::sendNewEntity(int type, int id)
{
  std::list<AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
  ANetwork::t_frame	frame;
  std::string	sendData = std::to_string(type) + ";" + std::to_string(id);

  frame = CreateRequest::create(S_NEW_ENTITY, CRC::calcCRC(sendData), sendData.size(),sendData);
  for (std::list<AEntity*>::iterator it = _players.begin(); it != _players.end(); ++it)
    {
      dynamic_cast<Player*>((*it))->getClient().getUDPSocket()->write(reinterpret_cast<void*>(&frame), sizeof(ANetwork::t_frame));
    }

}

void Game::handleShoot(void *data, Client *client)
{
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
    (std::chrono::system_clock::now() - _start);

  if (duration.count() % 8 == 0)
    {

      std::cout << "Game :: handleShoot" << std::endl;
      std::string weaponType =
	((reinterpret_cast<ANetwork::t_frame*>(data))->data);

      Player *p = this->getPlayerByClient(client);
      E_EntityType type = E_INVALID;
      int	id;

      if (weaponType == "E_RIFLE")
	type = E_RIFLE;
      else if (weaponType == "E_MISSILE")
	type = E_MISSILE;
      else if (weaponType == "E_LASER")
	type = E_LASER;

      if (type != E_INVALID)
	id = _eM.createEntity(type, p);

      std::cout << "After create entity " << std::endl;
      sendNewEntity(type, id); // Send  Bullet created

      AEntity *bullet = _eM.getEntityById(id);
      ComponentPosition *pPos = dynamic_cast<ComponentPosition *>(p->getSystemManager()->getSystemByComponent(C_POSITION)->getComponent());
      bullet->update(pPos->getX(), pPos->getY()); // Position Bullet to Player position

      std::stringstream ss;
      ss << type;

      ANetwork::t_frame frameHealth = CreateRequest::create(S_SHOOT, CRC::calcCRC(ss.str().c_str()), ss.str().size(), ss.str().c_str());
      std::list <AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
      for (std::list<AEntity *>::iterator it = _players.begin(); it != _players.end() ; ++it)
	{
	  dynamic_cast<Player*>((*it))->getClient().getUDPSocket()->write(reinterpret_cast<void*>(&frameHealth), sizeof(ANetwork::t_frame));
	}

    }
}

void Game::handleCommand(void *data, Client *client)
{
  E_Command commandType =
    static_cast<E_Command>((reinterpret_cast<ANetwork::t_frame*>(data))->idRequest);

  //  std::cout << "CommandType : " << commandType << std::endl;

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
  void *data;

  while (1)
    {
      Client *client = new Client(n->select());
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
      for (std::list<Bot*>::iterator it = _botList.begin();
	   it != _botList.end();
	   ++it)
	{
	  std::cout << "Je add un monstre" << std::endl;
	}
      _nbDisplay++;
    }
  else
    std::cout << "Monster Full for this Stage" << std::endl;
}

void Game::initPlayersPosition()
{

  int	x = 10;
  std::list<AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
  std::list<AEntity *>::iterator it;
  Random	rand(2, 48);
  for (it = _players.begin(); it != _players.end(); ++it)
    {
      (*it)->update(x, rand.generate<int>());
    }

}

void Game::deleteEntity(AEntity *entity)
{
  std::string	sendData = std::to_string(entity->getId());

  ANetwork::t_frame frame = CreateRequest::create(S_DELETE_ENTITY, CRC::calcCRC(sendData), sendData.size(), sendData);
  std::list<AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
  for (std::list<AEntity*>::iterator it = _players.begin(); it != _players.end(); ++it)
    {
      dynamic_cast<Player*>((*it))->getClient().getUDPSocket()->write(reinterpret_cast<void*>(&frame), sizeof(ANetwork::t_frame));
    }
  _eM.removeEntity(entity);
}

void Game::updateAmmo()
{
  std::list<AEntity*> _vec = _eM.getAmmoEntities();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
    (std::chrono::system_clock::now() - _start);

  for (std::list<AEntity *>::iterator it = _vec.begin(); it != _vec.end() ; ++it)
    {
      if (Riffle *rifle = dynamic_cast<Riffle*>(*it))
	{
	  ComponentPosition *p = reinterpret_cast<ComponentPosition *>((rifle)->getSystemManager()->getSystemByComponent(C_POSITION)->getComponent());
	  if (duration.count() % 30 == 0)
	    {
	      rifle->update(p->getX() + 1, p->getY());
	    }
	  if (p->getX() >= 119){
	    std::cout << "DELETE ENTITY" << std::endl;
	    deleteEntity(rifle);
	  }
	  // TIME RIFLE UPDATE
	}
      else if (Missile *missile = dynamic_cast<Missile *>(*it))
	{
	  //TIME MISSILE UPDATE
	}
      else if (Laser *laser = dynamic_cast<Laser *>(*it))
	{
	  //TIME LASER UPDATE
	}
    }

}

void Game::sendGameData()
{
  std::list<AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
  std::list<AEntity *> _entities = _eM.getEntities();

  for (std::list<AEntity *>::const_iterator it = _players.begin(); it != _players.end(); ++it)
    {
      for (std::list<AEntity *>::iterator it2 = _entities.begin(); it2 != _entities.end(); ++it2)
	{
	  //std::cout << "SS in data : " << (*it2)->getName()  << std::endl;

	  ComponentPosition *pPlayer = reinterpret_cast<ComponentPosition *>((*it2)->getSystemManager()->getSystemByComponent(C_POSITION)->getComponent());

	  std::stringstream ss;
	  ss << (*it2)->getId() << ";" << std::to_string(pPlayer->getX()) << ";" << std::to_string(pPlayer->getY());
	  //std::cout << "SS in data : " << ss.str().c_str() << std::endl;

	  ANetwork::t_frame frameToSend = CreateRequest::create(S_DISPLAY, CRC::calcCRC(ss.str().c_str()), ss.str().size(), ss.str().c_str());

	  if (!(dynamic_cast<Player*>((*it))->getClient().getUDPSocket()))
	    std::cout << "NULL UDP" << std::endl;
	  else
	    {
	      reinterpret_cast<Player*>((*it))->getClient().getUDPSocket()->write(reinterpret_cast<void*>(&frameToSend), sizeof(ANetwork::t_frame));
	    }
	}
    }

}

void Game::updateRiffle()
{
  std::list<AEntity *> rifles = _eM.getEntitiesByType(E_RIFLE);
  for (std::list<AEntity *>::iterator it = rifles.begin(); it != rifles.end(); ++it)
    {
      ComponentPosition *p = reinterpret_cast<ComponentPosition *>((*it)->getSystemManager()->getSystemByComponent(C_POSITION)->getComponent());
      (*it)->update(p->getX() + 1, p->getY());
    }
}

bool Game::run()
{
  bool past = true;
  Timer	timerMonster(true);
  Timer timerRiffle(true);
  int	speed = 3;
  ThreadFactory *tF = new ThreadFactory;
  std::unique_ptr<AThread> t1(tF->createThread());

  Game::dataThread *dT = new Game::dataThread;

  dT->game = this;
  dT->network = this->_network;
  t1->attach(&readThread, reinterpret_cast<void*>(dT));

  t1->run();
  initPlayersPosition();

  _start = std::chrono::system_clock::now();

  while (true)
    {
      if (timerMonster.elapsed().count()>= (speed/_stage))
	{
	  //this->updateAmmo();
	  timerMonster.reset();
	  //addMonster();
	}
      if (timerRiffle.elapsedMilli().count() >= 0.5 )
      {
	  this->updateRiffle();
	  timerRiffle.reset();
      }
      auto currentTime = std::chrono::system_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
	(currentTime - _start);
      _start = currentTime;
      auto start_time = std::chrono::steady_clock::now();
      auto end_time = start_time + frame_duration(4);
      if (duration.count() % 16 == 0)
	{
	  if (past == true)
	    {
	      std::this_thread::sleep_until(end_time);
	      past = false;
	    }
	  this->sendGameData();
	}
    }
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
