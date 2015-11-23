#ifndef IWINDOW_HH_
#define IWINDOW_HH_

#include <string>

class	        IWindow
{

  IWindow();
  ~IWindow();

  void		create(VideoMode) = 0;
  void		setColor(IColor& color) = 0;
  void		setSize(unsigned int size) = 0;
  void		setString(const std::string& title) = 0;

};

#endif /* !IWINDOW_HH_ */
