//
// Game.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:45:38 2015 Nicolas Charvoz
// Last update Sat Dec 12 00:05:17 2015 Nicolas Charvoz
//

#include <Game.hh>

Game::Game()
{
  _mutex = new Mutex();
}

Game::Game(const Parameters &params_, std::vector<Client *> &client_,
	   const std::string &id_, int port_) : _params(params_), _id(id_)
{
  //  srand(time(NULL));

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

void handleCommand(void *data)
{
  std::cout << "Game :: handleCommand" << std::endl;
  std::cout << std::string(((ANetwork::t_frame*)data)->data) << std::endl;
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
      if (!(data = client->getSocket()->read(sizeof(ANetwork::t_frame))))
	{
	  std::cout << "CA RENTRE DANS LE IF" << std::endl;
	  n->unlistenSocket(client->getSocket());
	  continue;
	}
      std::cout << "DATA : "<<
	std::string(((ANetwork::t_frame*)data)->data) << std::endl;
      handleCommand(data);
      client->getSocket()->write((void*)CreateRequest::create(1, 2, 3, "Thank You",
							      true),
	    sizeof(ANetwork::t_frame));
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
