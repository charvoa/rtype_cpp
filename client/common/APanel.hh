//
// APanel.hh for APanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:56 2015 Viveka BARNEAUD
// Last update Tue Dec  8 06:22:29 2015 Serge Heitzler
//

#ifndef APANEL_HH
#define APANEL_HH

#include <vector>
#include <string>
#include "AMenuElement.hh"
#include "Texture.hh"
#include "Text.hh"
#include "Sprite.hh"
#include "InputManager.hh"

class		APanel
{
public:

  APanel();
  ~APanel();

  virtual void		updateOnMove(std::pair<unsigned int, unsigned int> pair);
  virtual bool		updateOnPress(std::pair<unsigned int, unsigned int> pair);
  virtual void		update();
  virtual void		render();
  virtual void		hide();
  virtual void	        setUserInterface();
  
  std::vector<Sprite>			&getBackgrounds();
  std::vector<AMenuElement*>   		&getUserInterface();
  std::vector<Text>	  		&getLabels();
  std::vector<Sprite>			&getInGame();
  InputManager				&getInputManager();

  void					drawBackgrounds();
  void					drawUserInterface();
  void					drawLabels();
  void					drawInGame();
  
protected:

  std::vector<Sprite>	      		_backgrounds;
  std::vector<AMenuElement*>		_userInterface;
  std::vector<Text>			_labels;
  std::vector<Sprite>	      		_inGame;
  InputManager				_inputManager;

  typedef void(APanel::*funcs)();
  std::vector<funcs>			_functions;
  
};

#endif // APANEL_HH
