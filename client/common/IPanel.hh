//
// IPanel.hh for IPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:51:23 2015 Viveka BARNEAUD
// Last update Sun Dec 27 08:11:41 2015 Serge Heitzler
//

#ifndef IPANEL_HH
#define IPANEL_HH

class   IPanel
{
    virtual void render() = 0;
    virtual void hide() = 0;
};

#endif /* !IPANEL_HH */
