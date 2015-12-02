//
// VideoMode.hh for R-type in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Nov 25 17:23:47 2015 Nicolas Girardot
// Last update Wed Dec  2 11:39:53 2015 Nicolas Girardot
//

#ifndef VIDEOMODE_HH_
#define VIDEOMODE_HH_

class VideoMode
{
public:
  VideoMode(unsigned int width, unsigned int height, unsigned int bitsPerPixel = 32);
  ~VideoMode();

  unsigned int width;
  unsigned int height;
  unsigned int bitsPerPixel;
}

#endif
