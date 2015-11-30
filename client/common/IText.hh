//
// IText.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:20:17 2015 Serge Heitzler
// Last update Wed Nov 25 06:31:43 2015 Serge Heitzler
//

#ifndef ITEXT_HH_
#define ITEXT_HH_

#include <string>
#include "IFont.hh"
#include "IColor.hh"

class		      IText
{

  IText();
  ~IText();

  virtual void		setFont(IFont& font) = 0;
  virtual void		setColor(IColor& color) = 0;
  virtual void		setSize(unsigned int size) = 0;
  virtual void		setString(const std::string& title) = 0;

};

#endif /* !ITEXT_HH_ */
