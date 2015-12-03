//
// APanel.hh for APanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:56 2015 Viveka BARNEAUD
// Last update Thu Dec  3 16:13:21 2015 Nicolas Girardot
//

#ifndef APANEL_HH
#define APANEL_HH

#include <vector>
#include "AMenuElement.hh"
#include "Texture.hh"
#include "Sprite.hh"

class		APanel
{
public:

  APanel();
  ~APanel();

  void		render();
  void		hide();
  std::vector<AMenuElement*>		getElements();

private:

  std::vector<AMenuElement*>		_elements;
  std::vector<Texture*>			_textures;
  std::vector<Sprite*>	      		_sprites;
};

#endif // APANEL_HH
