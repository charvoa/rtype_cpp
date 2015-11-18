//
// Size.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:20:28 2015 Serge Heitzler
// Last update Mon Nov 23 08:20:29 2015 Serge Heitzler
//

#ifndef SIZE_HH_
#define SIZE_HH_

class	        Size
{

  Size();
  ~Size();

private:

  unsigned int		_width;
  unsigned int		_height;
  
public:

  unsigned int		getWidth();
  unsigned int		getHeight();

};

#endif /* !SIZE_HH_ */
