//
// Player.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:25:25 2015 Nicolas Charvoz
// Last update Tue Dec 22 06:23:12 2015 Antoine Garcia
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <ANetwork.hpp>
# include <Client.hh>
# include <AEntity.hh>
# include <string>
# include <iostream>
# include <Timer.hpp>

class Player : public AEntity
{

private:
  std::string _username;
  bool _isOwner;
  int _score;
  Client _client;
  int _missiles;
  int _laser;
  Timer	*_lastShoot;
  void sendShoot(E_Component, int);
public:
  Player(int id, const Client &);
  ~Player();
  Client &getClient();
  const std::string &getUsername() const;
  bool isOwner() const;
  int getScore() const;
  void setScore(int);
  void addSystem(E_Component);
  bool shoot(E_Component);
  Timer *getLastShoot();
};

#endif
