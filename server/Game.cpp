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
  _isRunning = true;

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
    final = std::make_pair(0, -16);
  else if (dir == "3")
    final = std::make_pair(16, -16);
  else if (dir == "2")
    final = std::make_pair(16, 0);
  else if (dir == "6")
    final = std::make_pair(16, 16);
  else if (dir == "4")
    final = std::make_pair(0, 16);
  else if (dir == "12")
    final = std::make_pair(-16, 16);
  else if (dir == "8")
    final = std::make_pair(-16, 0);
  else if (dir == "9")
    final = std::make_pair(-16, -16);
  else
    final = std::make_pair(0, 0);
  return final;
}

bool Game::checkMove(int x, int y)
{
  if (x < sizeInGame::LENGHT_MIN || x > sizeInGame::LENGHT_MAX)
    return false;
  else if (y < sizeInGame::HEIGHT_MIN || y > sizeInGame::HEIGHT_MAX)
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
  if (pPlayer->getY() <= sizeInGame::HEIGHT_MIN||
      pPlayer->getY() >= sizeInGame::HEIGHT_MAX)
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
	player->update(player->refreshHitbox());
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
    std::string sendData = std::to_string(p->getId()) + ";" + std::to_string(p->getId());
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

void Game::sendNewEntity(const std::string &str, int id)
{
  std::list<AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
  ANetwork::t_frame	frame;
  std::string	sendData = str + ";" + std::to_string(id);

  frame = CreateRequest::create(S_NEW_ENTITY, CRC::calcCRC(sendData), sendData.size(),sendData);
  for (std::list<AEntity*>::iterator it = _players.begin(); it != _players.end(); ++it)
    {
      dynamic_cast<Player*>((*it))->getClient().getUDPSocket()->write(reinterpret_cast<void*>(&frame), sizeof(ANetwork::t_frame));
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

  std::cout << "Game :: handleShoot" << std::endl;
  std::string weaponType =
    ((reinterpret_cast<ANetwork::t_frame*>(data))->data);

  Player *p = this->getPlayerByClient(client);
  E_EntityType type = E_INVALID;
  E_Component component = C_INVALID;
  int	id;

  if (weaponType == "E_RIFLE")
    {
      type = E_RIFLE;
      component = C_RIFLE;
    }
  else if (weaponType == "E_MISSILE")
    {
      type = E_MISSILE;
      component = C_MISSILE;
    }
  else if (weaponType == "E_LASER")
    {
      type = E_LASER;
      component = C_LASER;
    }

  std::cout << "Before create entity" << std::endl;
  if (type != E_INVALID)
    id = _eM.createEntity(type, p);

  std::cout << "After create entity " << std::endl;

  sendNewEntity(type, id); // Send  Bullet created

  std::cout << "Id I want to get in game : " << id << std::endl;
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
  return NULL;
}

int Game::getNumberEnemyMax()
{
  int	nbEnemy = 5 * _stage * _params.getDifficulty() * _eM.getEntitiesByType(E_PLAYER).size();
  return nbEnemy;
}

void Game::updateMonster()
{
  std::list<AEntity *> bots = _eM.getEntitiesByType(E_BOT);

  for (std::list<AEntity *>::iterator it = bots.begin(); it != bots.end(); ++it)
    {
      ComponentPosition *pos = reinterpret_cast<ComponentPosition*>((*it)->getSystemManager()->getSystemByComponent(C_POSITION)->getComponent());
      reinterpret_cast<Bot*>(*it)->update();
    }
}

void Game::addMonster()
{
  std::stringstream ss;

  if (_nbDisplay < getNumberEnemyMax())
    {
      std::cout << "Add Monster" << std::endl;
      Random r(0, _botList.size());

      int id = _eM.createEntitiesFromFolder(_botList, r.generate<int>());

      this->sendNewEntity(_eM.getEntityById(id)->getName(), id);
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
  Random	rand(40, 850);

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
      (*it)->update(p->getX() + 24, p->getY());
      if (p->getX() >= sizeInGame::LENGHT_MAX + 20)
	deleteEntity(*it);
    }
}

void Game::updateMissile()
{
  std::list<AEntity *> rifles = _eM.getEntitiesByType(E_MISSILE);
  for (std::list<AEntity *>::iterator it = rifles.begin(); it != rifles.end(); ++it)
    {
      ComponentPosition *p = reinterpret_cast<ComponentPosition *>((*it)->getSystemManager()->getSystemByComponent(C_POSITION)->getComponent());
      (*it)->update(p->getX() + 8, p->getY());
      if (p->getX() >= sizeInGame::LENGHT_MAX + 20)
	deleteEntity(*it);
    }
}

bool Game::run()
{
  int	speed = 3;
  Timer timerMonster(true);
  ThreadFactory *tF = new ThreadFactory;
  std::unique_ptr<AThread> t1(tF->createThread());

  Game::dataThread *dT = new Game::dataThread;

  dT->game = this;
  dT->network = this->_network;
  t1->attach(&readThread, reinterpret_cast<void*>(dT));

  t1->run();
  initPlayersPosition();

  _start = std::chrono::system_clock::now();

  int i = 0;
  while (std::chrono::high_resolution_clock::now() < _start + std::chrono::milliseconds(500));
  while (_isRunning)
    {
      auto startTime = std::chrono::high_resolution_clock::now();
      if (timerMonster.elapsed().count()>= (speed/_stage))
      	{
      	  timerMonster.reset();
      	  this->addMonster();
      	}
      this->updateMonster();
      this->updateRiffle();
      this->updateMissile();
      this->sendGameData();
      while (std::chrono::high_resolution_clock::now() < startTime + std::chrono::milliseconds(16));
      i++;
    }
  return true;
}


const std::string &Game::getId() const
{
  return _id;
}

void Game::deletePlayer()
{
  _nbLeft++;
  if (_nbLeft >= static_cast<int>(_clients.size()))
    {
      _isRunning = false;
    }
}
