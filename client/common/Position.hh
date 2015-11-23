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
