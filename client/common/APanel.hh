//
// APanel.hh for APanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:50:56 2015 Viveka BARNEAUD
// Last update Wed Dec  2 07:50:20 2015 Serge Heitzler
//

#ifndef APANEL_HH
#define APANEL_HH

#include <vector>
#include "AMenuElement.hh"
#include "RenderWindow.hh"

class		APanel
{
public:
  
  APanel();
  ~APanel();

  void		render();
  void		hide();

private:

  std::vector<AMenuElement*>		_elements;
  std::vector<Texture*>			_textures;
  std::vector<Sprite*>	      		_sprites;

};

#endif // APANEL_HH
