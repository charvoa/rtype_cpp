//
// ButtonFactory.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Dec  7 03:02:15 2015 Serge Heitzler
// Last update Thu Dec 10 14:18:53 2015 Serge Heitzler
//

#ifndef BUTTONFACTORY_HH_
#define BUTTONFACTORY_HH_

#include <string>
#include <Vector2.hh>
#include <Button.hh>
#include <Text.hh>
#include <RenderWindow.hh>
#include <Color.hh>

class	        ButtonFactory
{
public:

  static void			create(Vector2 pos, std::string &title);

private:

};

#endif /* !BUTTONFACTORY_HH_ */
