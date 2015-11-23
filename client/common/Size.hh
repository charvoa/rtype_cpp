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
