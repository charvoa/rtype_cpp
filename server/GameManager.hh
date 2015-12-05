//
// GameManager.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:41:04 2015 Nicolas Charvoz
// Last update Sat Dec  5 16:46:55 2015 Nicolas Charvoz
//

#ifndef GAMEMANAGER_HH_
# define GAMEMANAGER_HH_

# include <Game.hh>

class GameManager {

private:

  std::vector<Game> _games;

  public:

  GameManager();
  ~GameManager();
  void createGame(const Parameters&, std::vector<Client>&, const std::string&);
  Game &getGameById(const std::string&);
  Game &getGameByClient(const Client &);
};

#endif
