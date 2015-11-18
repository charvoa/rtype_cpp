//
// Volume.hh for Volume in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:49:58 2015 Viveka BARNEAUD
// Last update Mon Nov 30 09:52:37 2015 Viveka BARNEAUD
//

#ifndef VOLUME_H
#define VOLUME_H

class Volume
{
public:
    Volume(int, int, int);
    ~Volume();

    int getGlobal() const;
    int getEffects() const;
    int getMusic() const;

    void setGlobal(int);
    void setEffects(int);
    void setMusic(int);

private:
    int _global;
    int _effects;
    int _music;
};

#endif // VOLUME_H
