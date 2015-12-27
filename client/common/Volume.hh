//
// Volume.hh for Volume in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:49:58 2015 Viveka BARNEAUD
// Last update Sun Dec 27 08:01:13 2015 Serge Heitzler
//

#ifndef		VOLUME_H
#define		VOLUME_H

class		Volume
{
public:
  
  Volume();
  Volume(int, int, int);
  ~Volume();

  int		getGlobal() const;
  int		getEffects() const;
  int		getMusic() const;

  void		setGlobal(int);
  void		setEffects(int);
  void		setMusic(int);

private:
  int		_global;
  int		_effects;
  int		_music;
};

#endif /* !VOLUME_HH_ */
