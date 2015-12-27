//
// Player.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:29:32 2015 Nicolas Charvoz
//

# include <ProtocoleEnum.hh>
# include <ANetwork.hpp>
# include <Player.hh>
# include <CRC.hpp>
# include <CreateRequest.hpp>

Player::Player(int id, const Client &c) : AEntity(id)
{
  _client = c;
  _name = "player" + std::to_string(id);
  addSystem(C_POSITION);
  addSystem(C_HEALTH);
  addSystem(C_HITBOX);
  addSystem(C_MISSILE);
  addSystem(C_LASER);
  _missiles = 5;
  _laser = 1;
  _lastShoot = new Timer(true);
  _rifleShooted = 0;
  _missileShooted = 0;
  _laserShooted = 0;
}

Player::~Player() {}

Client &Player::getClient()
{
  return _client;
}

const std::string &Player::getUsername() const
{
  return _username;
}

bool Player::isOwner() const
{
  return _isOwner;
}

int Player::getScore() const
{
  return _score;
}

void Player::setScore(int s)
{
  _score = s;
}

void Player::addSystem(E_Component type)
{
  _systemManager->addSystemByType(type);
  if (type == C_MISSILE)
    _missiles = 5;
  else if (type == C_LASER)
    _laser = 1;
}

void	Player::sendShoot(E_EntityType type, int nb)
{
  std::string sendData = std::to_string(type) + ";" + std::to_string(nb);
  ANetwork::t_frame frame = CreateRequest::create(S_AMMO_LEFT, CRC::calcCRC(sendData), sendData.size(), sendData);
  _client.getUDPSocket()->write(reinterpret_cast<void*>(&frame), sizeof(ANetwork::t_frame));
}
bool Player::shoot(E_Component type)
{
  if (type == C_MISSILE)
    {
      if (_missiles >= 1)
	{
	  _missiles--;
	  sendShoot(E_MISSILE,_missiles);
	  return (true);
	}
      else
	return(false);
    }
  else if (type == C_LASER)
    {
      if (_laser >= 1)
	{
	  _laser--;
	  sendShoot(E_LASER,_laser);
	  return (true);
	}
      else
	return(false);
    }
  return true;
}

Timer	*Player::getLastShoot()
{
  return _lastShoot;
}

void	Player::increaseShooted(const std::string &weaponType, int i)
{
  if (weaponType == "E_RIFLE")
    _rifleShooted += i;
  else if (weaponType == "E_MISSILE")
    _missileShooted += i;
  else if (weaponType == "E_LASER")
    _laserShooted += i;
}

int	Player::getShooted(const std::string &weaponType)
{
  if (weaponType == "E_RIFLE")
    return (_rifleShooted);
  else if (weaponType == "E_MISSILE")
    return (_missileShooted);
  else if (weaponType == "E_LASER")
    return (_laserShooted);
  return 0;
}
