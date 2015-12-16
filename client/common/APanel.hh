//
// APanel.hh for APanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:56 2015 Viveka BARNEAUD
// Last update Wed Dec 16 05:26:49 2015 Serge Heitzler
//

#ifndef APANEL_HH
#define APANEL_HH

#include <vector>
#include <string>
#include <AMenuElement.hh>
#include <Texture.hh>
#include <Text.hh>
#include <Sprite.hh>
#include <InputManager.hh>

class		APanel
{
public:

  APanel();
  ~APanel();

  virtual void		updateOnMove(std::pair<unsigned int, unsigned int> pair);
  virtual bool		updateOnPress(std::pair<unsigned int, unsigned int> pair);
  //  virtual bool		updateOnPressInGame(std::pair<unsigned int, unsigned int> pair);
  virtual void		updateOnRelease(std::pair<unsigned int, unsigned int> pair);
  virtual void		setKeyButton(sf::Event);
  virtual void		update();
  virtual void		render();
  virtual void		hide();
  virtual void		    setUserInterface();
  virtual void		setGlobalVolume(int);
  virtual void		setEffectsVolume(int);
  virtual void		setMusicVolume(int);

  std::vector<Sprite>			&getBackgrounds();
  std::vector<AMenuElement*>   		&getUserInterface();
  std::vector<Text>	  		&getLabels();
  std::vector<Sprite>			&getInGame();
  InputManager				&getInputManager();

  virtual void					drawBackgrounds();
  virtual void					drawUserInterface();
  virtual void					drawLabels();
  virtual void					drawInGame();
  
  typedef void(APanel::*funcs)();
  virtual std::vector<funcs>   			&getFunctions();
  
protected:

  std::vector<Sprite>	      		_backgrounds;
  std::vector<AMenuElement*>		_userInterface;
  std::vector<Text>			_labels;
  std::vector<Sprite>	      		_inGame;
  InputManager				_inputManager;

  std::vector<funcs>			_functions;

};

#endif // APANEL_HH
