//
// Event.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Dec  2 02:33:19 2015 Serge Heitzler
// Last update Wed Dec  9 13:55:37 2015 Nicolas Girardot
//

#ifndef EVENT_HH_
#define EVENT_HH_

#include <IEvent.hh>

class  		      Event : public IEvent
{

  sf::Event		getEvent();

public:


  private:

    sf::Event		_event;

};

#endif /* !EVENT_HH_ */
