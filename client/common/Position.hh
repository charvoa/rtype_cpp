//
// Position.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:20:25 2015 Serge Heitzler
// Last update Mon Nov 23 08:20:25 2015 Serge Heitzler
//

#ifndef POSITION_HH_
#define POSITION_HH_

class		Position
{

  Position();
  ~Position();
  
private:

  unsigned int		_x;
  unsigned int		_y;
  
public:

  unsigned int		getPosX();
  unsigned int		getPosY();

};

#endif /* !POSITION_HH_ */
