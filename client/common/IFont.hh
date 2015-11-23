#ifndef IFONT_HH_
#define IFONT_HH_

#include <string>

class	        IFont
{

  IFont();
  ~IFont();

  void		loadFromFile(const std::string &filename) = 0;

};

#endif /* !IFONT_HH_ */
