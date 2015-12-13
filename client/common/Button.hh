//
// Button.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:19:49 2015 Serge Heitzler
// Last update Sun Dec 13 13:36:09 2015 Nicolas Girardot
//

#ifndef BUTTON_HH_
#define BUTTON_HH_

#include <Text.hh>
#include <Sprite.hh>
#include <AMenuElement.hh>

class	        Button : public AMenuElement
{
public:
  Button();
  Button(Vector2 pos, Vector2 size, const std::string &title, const std::string &normal, const std::string &highlight, const std::string &select);
  ~Button();

  typedef enum e_stateButton
    {
      NORMAL,
      SELECTED,
      DISABLED
    }		StateButton;

  bool			mousePressEvent(sf::Event& event);
  bool			mouseReleaseEvent(sf::Event& event);
  bool			mouseEntered(sf::Event& event);
  bool			mouseLeft(sf::Event& event);
  void		        updateOnMove(std::pair<unsigned int, unsigned int> pair);
  bool		        updateOnPress(std::pair<unsigned int, unsigned int> pair);
  void			render();
  void			setState(StateButton state);

private:

  StateButton	       	_state;
  bool			_hover;

  Texture		*_normal;
  Texture		*_highlight;
};

#endif /* !BUTTON_HH_ */
