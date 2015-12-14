//
// RoomPanel.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Thu Dec 10 02:20:53 2015 Serge Heitzler
// Last update Mon Dec 14 08:01:27 2015 Serge Heitzler
//

#ifndef ROOMPANEL_HH_
#define ROOMPANEL_HH_

#include <map>
#include <string>
#include <Button.hh>
#include <Settings.hh>
#include <APanel.hh>
#include <Player.hh>

class RoomPanel : public APanel
{
public:

  RoomPanel();
  ~RoomPanel();

  void			difficulty(Settings::Difficulty);
  static void  		playerLeft(std::vector<std::string> &vector);
  static void  		newPlayer(std::string &newUsername);
  void			launchGame();
  void			back();
  void			update();
  void			setUserInterface();
  void			updatePlayers(std::vector<std::string> &vector, int from);
  void			createPlayers();
  std::vector<Player*>	&getPlayers();
  unsigned int		getNbPlayers() const;
  void			minusNbPlayers();
  void			addNbPlayers();
  std::vector<Texture*> &getTextures();
  static void	       	receiveFiles(int i, int j);
  int	  		getCurrentPlayer();

private:

  std::vector<Player*> _players;
  std::string		_idRoom;
  std::vector<Texture*>	_spaceShipsTextures;
  unsigned int		_nbPlayers;
  int			_currentPlayer;
  std::map<std::string, Texture*>	_received;
};

#endif /* !ROOMPANEL_HH_ */
