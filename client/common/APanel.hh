//
// APanel.hh for APanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:56 2015 Viveka BARNEAUD
// Last update Sat Dec  5 02:15:05 2015 Serge Heitzler
//

#ifndef APANEL_HH
#define APANEL_HH

#include <vector>
#include <string>
#include "AMenuElement.hh"
#include "Texture.hh"
#include "Sprite.hh"

class		APanel
{
public:

  APanel();
  ~APanel();

  void		update();
  void		render();
  void		hide();
  std::vector<AMenuElement*>		&getElements();
  std::vector<Sprite>			&getSprites();

  std::vector<Sprite>	      		_sprites;
  std::vector<Texture>			_textures;
private:

  std::vector<AMenuElement*>		_elements;
};

#endif // APANEL_HH
