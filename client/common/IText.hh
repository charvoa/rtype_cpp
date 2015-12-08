//
// IText.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:20:17 2015 Serge Heitzler
// Last update Tue Dec  8 07:28:10 2015 Serge Heitzler
//

#ifndef ITEXT_HH_
#define ITEXT_HH_

#include <string>
#include "SFont.hh"
#include "Color.hh"

class		      IText
{
  
public:
  virtual void		setFont(SFont& font) = 0;
  virtual void		setColor(Color::Tint color) = 0;
  virtual void		setSize(unsigned int size) = 0;
  virtual void		setString(const std::string& title) = 0;
  virtual void 	        setStyle(uint32_t style) = 0;

};

#endif /* !ITEXT_HH_ */
