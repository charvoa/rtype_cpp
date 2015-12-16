//
// Player.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:25:25 2015 Nicolas Charvoz
// Last update Wed Dec 16 06:07:49 2015 Louis Audibert
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <ANetwork.hpp>
# include <Client.hh>
# include <AEntity.hh>
# include <string>
# include <iostream>

class Player : public AEntity
{

private:
  std::string _username;
  bool _isOwner;
  int _score;
  Client _client;
  int _missiles;
  int _laser;

public:
  Player(int id, const Client &);
  ~Player();
  Client &getClient();
  const std::string &getUsername() const;
  bool isOwner() const;
  int getScore() const;
  void setScore(int);
  void addSystem(E_Component);
  void shoot(E_Component);
};

#endif
