//
// IVideoMode.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:20:21 2015 Serge Heitzler
// Last update Mon Nov 23 08:20:22 2015 Serge Heitzler
//

#ifndef IVIDEOMODE_HH_
#define IVIDEOMODE_HH_

#include <string>

class	        IVideoMode
{

  IVideoMode(unsigned int modeWidth, unsigned int modeHeight, unsigned int modeBitsPerPixels=32);
  ~IVideoMode();

};

#endif /* !IVIDEOMODE_HH_ */
