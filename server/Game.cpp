//
// Game.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:45:38 2015 Nicolas Charvoz
//

#include <Game.hh>
#include <Random.hpp>

Game::Game()
{
}

Game::Game(const Parameters &params_, std::list<Client *> &client_,
	   const std::string &id_, int port_, std::list<Bot*> botList_)
  : _params(params_), _id(id_), _botList(botList_)
{
  srand(time(NULL));
  _canAddMonster = true;
  _mutex = new Mutex();
  this->_clients = client_;
  this->_network = new Network();
  this->_network->init(port_ + 1, ANetwork::UDP_MODE);
  this->_network->bind();
  this->addClients(client_);
  _stage = 1;
  _nbDisplay = 0;
  _isRunning = true;
  _nbLeft = 0;
  _nbInGame = client_.size();;
  this->_timestamp = time(NULL);
  _funcMap.insert(std::make_pair(C_HANDSHAKE_UDP, &Game::handleHandshakeUDP));
  _funcMap.insert(std::make_pair(C_MOVE, &Game::handleMove));
  _funcMap.insert(std::make_pair(C_SHOOT, &Game::handleShoot));
  _timerWave = new Timer(true);
  _botManager = new BotManager("../libs/");
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

Player *Game::getPlayerByClientTCP(Client *client)
{
  std::list<AEntity*> _players = _eM.getEntitiesByType(E_PLAYER);

  for (std::list<AEntity*>::iterator it = _players.begin();
       it != _players.end();
       ++it)
    {
      Player *ptmp = reinterpret_cast<Player*>(*it);
      if (ptmp->getClient().getSocket()->getFd() == client->getSocket()->getFd())
	return (ptmp);
    }
  throw std::logic_error("Cannot find this player by TCP client");
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
  else if (y < sizeInGame::HEIGHT_MIN - 16 || y > sizeInGame::HEIGHT_MAX + 16)
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
  if (pPlayer->getY() <= sizeInGame::HEIGHT_MIN ||
      pPlayer->getY() >= sizeInGame::HEIGHT_MAX)
    {
      std::cout << "JE RENTRE DEDANS" << std::endl;
      this->updateLife(player, 2);
    }
}

void Game::handleMove(void *data, Client *client)
{
  //  std::cout << "Game :: handleMove" << std::endl;
  ComponentPosition *pPlayer;
  try {
    Player *player = this->getPlayerByClient(client);
    ComponentHealth *health = dynamic_cast<ComponentHealth*>(player->getSystemManager()->getSystemByComponent(C_HEALTH)->getComponent());
    std::stringstream ss;
    if (health->getLife() != 0)
      {
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
	    //	if (reinterpret_cast<Mutex*>(_mutex)->try_lock()) {
	    player->update(pPlayer->getX() + newMove.first, pPlayer->getY() + newMove.second);
	    player->update(player->refreshHitboxEntity());
	    //      	} reinterpret_cast<Mutex*>(_mutex)->unlock();
	    this->checkWall(player);
	  }
      }
  } catch (const std::exception &e) {
    std::cout << "Cannot move : " << e.what() << std::endl;
  }
}

void Game::updateScore(Player *p, Game::scoreDef score)
{
  std::list <AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
  p->setScore(p->getScore() + score);
  std::cout << "Player current score : " << p->getScore()  << "; score added : " << score << std::endl;
  std::string sendData = p->getName() + ";" + std::to_string(p->getScore());
  ANetwork::t_frame frame = CreateRequest::create(S_SCORE, CRC::calcCRC(sendData), sendData.size(), sendData);
  for (std::list<AEntity *>::iterator it = _players.begin(); it != _players.end() ; ++it)
    {
      dynamic_cast<Player*>((*it))->getClient().getUDPSocket()->write(reinterpret_cast<void*>(&frame), sizeof(ANetwork::t_frame));
    }
}

void Game::updateLife(Player *p, int reset)
{
  //  std::cout << "UPDATE LIFE " << std::endl;
  ComponentHealth *hP =
    reinterpret_cast<ComponentHealth*>(p->getSystemManager()
				       ->getSystemByComponent(C_HEALTH)
				       ->getComponent());
  if (reset == 0)
    {
      int newlife = hP->getLife() - 1;
      p->update(newlife);
    }
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

  Player *p = this->getPlayerByClient(client);
  ComponentHealth *health = dynamic_cast<ComponentHealth*>(p->getSystemManager()->getSystemByComponent(C_HEALTH)->getComponent());
  if (health->getLife() != 0)
    {
      if (p->getLastShoot()->elapsedMilli().count() >= 500)
	{
	  //      std::cout << "Game :: handleShoot" << std::endl;
	  std::string weaponType =
	    ((reinterpret_cast<ANetwork::t_frame*>(data))->data);

	  E_EntityType type = E_INVALID;
	  E_Component component;
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
	  p->increaseShooted(weaponType, 1);
	  AEntity *bullet;

	  if (type != E_INVALID)
	    {
	      if (p->shoot(component) == true)
		{
		  id = _eM.createEntity(type, p);
		  bullet = _eM.getEntityById(id);
		  sendNewEntity(bullet->getName(), id); // Send  Bullet created

		  ComponentPosition *pPos = dynamic_cast<ComponentPosition *>(p->getSystemManager()->getSystemByComponent(C_POSITION)->getComponent());
		  bullet->update(pPos->getX(), pPos->getY()); // Position Bullet to Player position

		  std::stringstream ss;
		  ss << bullet->getName();

		  //   std::cout << "ss >> " << ss.str().c_str() << std::endl;

		  ANetwork::t_frame frameHealth = CreateRequest::create(S_SHOOT, CRC::calcCRC(ss.str().c_str()), ss.str().size(), ss.str().c_str());
		  std::list <AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
		  for (std::list<AEntity *>::iterator it = _players.begin(); it != _players.end() ; ++it)
		    {
		      dynamic_cast<Player*>((*it))->getClient().getUDPSocket()->write(reinterpret_cast<void*>(&frameHealth), sizeof(ANetwork::t_frame));
		    }
		  p->getLastShoot()->reset();
		}
	    }
	}
    }
}

void Game::handleCommand(void *data, Client *client)
{
  E_Command commandType =
    static_cast<E_Command>((reinterpret_cast<ANetwork::t_frame*>(data))->idRequest);

  try {
    Func fp = _funcMap[commandType];
    (this->*fp)(data, client);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
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
      //(*it)->update((*it)->refreshHitbox());
      if (pos->getX() < -10)
	{
	  deleteEntity(*it);
	  // _nbDisplay--;
	}
    }
}

void Game::addMonster()
{
  std::stringstream ss;

  if ((_nbDisplay < getNumberEnemyMax()) && _canAddMonster)
    {
      //      std::cout << "Add Monster" << std::endl;
      int id = _eM.createEntitiesFromFolder(_botManager->createBot(), 0);

      this->sendNewEntity(_eM.getEntityById(id)->getName(), id);
      _nbDisplay++;
    }
  else{
    _canAddMonster = false;
    //    std::cout << "Monster Full for this Stage" << std::endl;
  }
}

void Game::initPlayersPosition()
{

  int	x = 10;
  std::list<AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
  std::list<AEntity *>::iterator it;
  Random	rand(100, 800);

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
      (*it)->update((*it)->refreshHitboxEntity());
      if (p->getX() >= sizeInGame::LENGHT_MAX + 20)
	deleteEntity(*it);
    }
}

void Game::updateLaser()
{
  std::list<AEntity *> rifles = _eM.getEntitiesByType(E_LASER);
  for (std::list<AEntity *>::iterator it = rifles.begin(); it != rifles.end(); ++it)
    {
      ComponentPosition *p = reinterpret_cast<ComponentPosition *>((*it)->getSystemManager()->getSystemByComponent(C_POSITION)->getComponent());
      Player *player = reinterpret_cast<Player*>((*it)->getParent());
      ComponentPosition *pPlayer = reinterpret_cast<ComponentPosition *>((player)->getSystemManager()->getSystemByComponent(C_POSITION)->getComponent());

      (*it)->update(pPlayer->getX(), pPlayer->getY());
      (*it)->update((*it)->refreshHitboxEntity());

      auto startedAt = reinterpret_cast<Laser*>((*it))->getLaunchTime();
      auto now = std::chrono::system_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - startedAt);
      if (duration.count() >= 1000)
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
      (*it)->update((*it)->refreshHitboxEntity());
      if (p->getX() >= sizeInGame::LENGHT_MAX + 20)
	deleteEntity(*it);
    }
}

// std::pair<int, int> getMaxAndMinOfList(std::list<Case*> &listCase)
// {
//   int saveMax = 0;
//   int saveMin;

//   std::pair<int, int> final;

//   for (std::list<Case*>::iterator it = listCase.begin();
//        it != listCase.end();
//        ++it)
//     {
//       saveMax = ((*it)->y > saveMax) ? (*it)->y : saveMax;
//       saveMin = saveMax;
//       saveMin = ((*it)->y < saveMin) ? (*it)->y : saveMin;
//     }
//   std::cout << "Max hitboxY = " << saveMax << " Min hitboxY = " << saveMin << std::endl;
//   final = std::make_pair(saveMin, saveMax);
//   return final;
// }

void Game::checkHitBox()
{
  std::list<AEntity*> monsterList = _eM.getEntitiesByType(E_BOT);
  std::list<AEntity*> ammos = _eM.getAmmoEntities();

  bool isBreak = false;
  for (std::list<AEntity*>::iterator ammosIT  = ammos.begin();
       ammosIT != ammos.end();
       ++ammosIT)
    {
      for (std::list<AEntity*>::iterator monsterIT = monsterList.begin();
	   monsterIT != monsterList.end();
	   ++monsterIT)
	{
	  std::list<Case*> caseMonster = reinterpret_cast<ComponentHitbox*>((*monsterIT)->getSystemManager()->getSystemByComponent(C_HITBOX)->getComponent())->getHitbox();
	  std::list<Case*> caseAmmo = reinterpret_cast<ComponentHitbox*>((*ammosIT)->getSystemManager()->getSystemByComponent(C_HITBOX)->getComponent())->getHitbox();
	  for (std::list<Case*>::iterator case1 = caseAmmo.begin();
	       case1 != caseAmmo.end();
	       ++case1)
	    {
	      if (isBreak == true)
		break;
	      for (std::list<Case*>::iterator case2 = caseMonster.begin();
		   case2 != caseMonster.end();
		   ++case2)
		{
		  //std::pair<int, int> limitY = getMaxAndMinOfList(caseMonster);
		  //std::cout <<  " BOT : (" << (*case2)->x << " , " << (*case2)->y << ") | MISSILE : (" << (*case1)->x << " , " << (*case1)->y << "|" << std::endl;
 		  if ((*case1)->x >= (*case2)->x && (*case1)->y && (((*case1)->y >= caseMonster.front()->y) && ((*case1)->y <= caseMonster.back()->y)))
		    {
		      //		      std::cout << "J'ai pas toucheyyyy" << std::endl;
		      Player *p;
		      if ((p = reinterpret_cast<Player*>((*ammosIT)->getParent()))
			  != nullptr)
			{
			  this->updateScore(p, scoreDef::KILLED);
			  deleteEntity(*ammosIT);
			  //			  isBreakable = true;
			  std::stringstream ss;

			  ss << p->getId();
			  ss << ";";
			  ss << (*monsterIT)->getId();
			  ANetwork::t_frame frame = CreateRequest::create(S_DIE, CRC::calcCRC(ss.str().c_str()), ss.str().size(), ss.str().c_str());
			  std::list<AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
			  for (std::list<AEntity*>::iterator it = _players.begin(); it != _players.end(); ++it)
			    {
			      dynamic_cast<Player*>((*it))->getClient().getUDPSocket()->write(reinterpret_cast<void*>(&frame), sizeof(ANetwork::t_frame));
			    }
			  deleteEntity(*monsterIT);

			  isBreak = true;
			  break;
			}
		      //_nbDisplay--;
		    }
		}
	    }
	}
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

  //int i = 0;
  // while (std::chrono::high_resolution_clock::now() < _start + std::chrono::milliseconds(500));

  std::this_thread::sleep_for(std::chrono::seconds(2));
  while (_isRunning)
    {
      auto startTime = std::chrono::high_resolution_clock::now();
      if (!_canAddMonster)
	this->checkNewStage();
      if (timerMonster.elapsed().count() >= (speed/_stage) && timerMonster.elapsed().count() >= 1 && (_timerWave->elapsed().count() > 2) && startTime - _start > std::chrono::milliseconds(8000))
      	{
      	  timerMonster.reset();
	  this->addMonster();
	}
      this->updateRiffle();
      this->updateMissile();
      this->updateLaser();
      this->updateMonster();
      this->checkHitBox();
      this->sendGameData();
      while (std::chrono::high_resolution_clock::now() < startTime + std::chrono::milliseconds(16));
    }
  return true;
}

const std::string &Game::getId() const
{
  return _id;
}

std::list<Client*> &Game::getClients()
{
  return _clients;
}

void Game::deletePlayer(Client *c)
{
  _nbLeft++;
  Player *p;

  try {
    p = this->getPlayerByClientTCP(c);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::string sendData = p->getName();

  std::cout << p->getName() << " left the game ... Still " << _nbInGame - _nbLeft << " players remaining." << std::endl;

  ANetwork::t_frame frame = CreateRequest::create(S_PLAYER_LEFT_IG, CRC::calcCRC(sendData), sendData.size(), sendData);
  std::list<AEntity *> _players = _eM.getEntitiesByType(E_PLAYER);
  for (std::list<AEntity*>::iterator it = _players.begin(); it != _players.end(); ++it)
    {
      dynamic_cast<Player*>((*it))->getClient().getUDPSocket()->write(reinterpret_cast<void*>(&frame), sizeof(ANetwork::t_frame));
    }
  if (_nbLeft == _nbInGame || (_nbInGame - _nbLeft) < 0)
    {
      std::cout << " I will quit" << std::endl;
      _isRunning = false;
    }
}

void Game::checkNewStage()
{
  std::list<AEntity *> bots = _eM.getEntitiesByType(E_BOT);

  if (bots.size() == 0)
    {
      _canAddMonster = true;
      _nbDisplay = 0;
      _stage++;
      _timerWave->reset();
      std::cout << "I SEND NEW WAVE" << _stage << std::endl;
      std::list<AEntity *> players = _eM.getEntitiesByType(E_PLAYER);
      std::string sendData = std::to_string(_stage);
      ANetwork::t_frame frame = CreateRequest::create(S_NEW_WAVE, CRC::calcCRC(sendData), sendData.size(), sendData);
      for (std::list<AEntity*>::iterator it = players.begin(); it != players.end(); ++it)
	{
	  dynamic_cast<Player*>(*it)->getClient().getSocket()->write(reinterpret_cast<void*>(&frame), sizeof(ANetwork::t_frame));
	}
    }
}
