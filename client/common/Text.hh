#ifndef TEXT_HH_
#define TEXT_HH_

#include "IText.hh"

class	        Text : public IText
{

  Text();
  ~Text();

  void			setFont(IFont& font);
  void			setColor(IColor& color);
  void			setSize(unsigned int size);
  void			setString(const std::string& title);

private :

  unsigned int		_fontSize;
  IFont			_font;
  IColor		_color;
  const std::string &	_string;

};

#endif /* !TEXT_HH_ */
