//
// Game.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:45:38 2015 Nicolas Charvoz
// Last update Sat Dec 12 18:25:24 2015 Nicolas Charvoz
//

#include <Game.hh>

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
  std::vector<AEntity*> _players = _eM->getEntitiesByType(E_PLAYER);

  for (std::vector<AEntity*>::iterator it = _players.begin();
       _players.end();
       ++it)
    {
      if ((reinterpret_cast<Player*>(*it))->getClient().getUDPSocket()->getFd()
	   == client->getUDPSocket()->getFd())
	{

	}
    }
}

void handleHandshakeUDP(void *data, void *sData, Client *client)
{
  Game::dataThread *s = reinterpret_cast<Game::dataThread*>(sData);

  ANetwork *n = s->network;
  Game *me = s->game;

  std::cout << "Data: |" << std::string(((ANetwork::t_frame*)data)->data)
	    << "|"
	    << std::endl;

  for (std::vector<Client*>::iterator it = me->_clients.begin();
       it != me->_clients.end() ; ++it)
    {
      if ((*it)->getSocket()->getFd() == std::atoi(((ANetwork::t_frame*)data)->data))
	{
	  (*it)->setUDPSocket(client->getUDPSocket());
	}
    }
}

void handleMove(void *data, void *sData, Client *client)
{
  std::cout << "handleMove" << std::endl;
}

void handleCommand(void *data, void *sData, Client *client)
{
  Game::dataThread *s = reinterpret_cast<Game::dataThread*>(sData);

  ANetwork *n = s->network;
  Game *me = s->game;

  std::cout << "Game :: handleCommand" << std::endl;
  std::cout << "ID Request: |" << ((ANetwork::t_frame*)data)->idRequest
	    << "|" << std::endl;
  if (((ANetwork::t_frame*)data)->idRequest == C_HANDSHAKE_UDP)
    {
      handleHandshakeUDP(data, sData, client);
    }
  else if (((ANetwork::t_frame*)data)->idRequest == C_MOVE)
    {
      std::cout << "he wants to move" << std::endl;
      handleMove(data, sData, client);
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
      handleCommand(data, sData, client);
      std::stringstream ss;
      ss << "0;30;30";
      while (1)
	{
	  try {
	    ANetwork::t_frame frameToSend = CreateRequest::create((unsigned char)S_DISPLAY, CRC::calcCRC(ss.str().c_str()), 0, ss.str().c_str());
	    client->getSocket()->write(reinterpret_cast<void*>(&frameToSend), sizeof(ANetwork::t_frame));
	    ss.str("");
	    ss.clear();
	  }
	  catch (const std::exception &e) {
	    exit(0);
	  }
	}
    }
}

bool Game::run()
{
  int nbEnemy = 5;
  int stage = 1;

  std::cout << "Game :: run() " << std::endl;

  ThreadFactory *tF = new ThreadFactory;
  std::unique_ptr<AThread> t1(tF->createThread());

  Game::dataThread *dT = new Game::dataThread;

  dT->game = this;
  dT->network = this->_network;
  t1->attach(&readThread, reinterpret_cast<void*>(dT));

  t1->run();
  while (true)
    {
      //      std::cout << "nb of enemy = " << nbEnemy << std::endl;
      nbEnemy = 5 * stage * nbEnemy;
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
