//
// IFont.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:19:35 2015 Serge Heitzler
// Last update Tue Dec  1 02:56:43 2015 Serge Heitzler
//

#ifndef IFONT_HH_
#define IFONT_HH_

#include <string>

class		      IFont
{

  virtual void		loadFromFile(const std::string &filename) = 0;

};

#endif /* !IFONT_HH_ */
