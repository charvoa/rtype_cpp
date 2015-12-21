//
// Laser.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sun Dec 13 05:05:58 2015 Louis Audibert
// Last update Sun Dec 20 14:35:25 2015 Nicolas Charvoz
//

#ifndef _LASER_HH_
# define _LASER_HH_

# include <AEntity.hh>

class Laser : public AEntity
{

private :

  std::chrono::time_point<std::chrono::system_clock> _launchTime;

public:
  Laser(int id);
  ~Laser();
  std::chrono::time_point<std::chrono::system_clock> getLaunchTime() const;
};

#endif /* _LASER_HH_  */
