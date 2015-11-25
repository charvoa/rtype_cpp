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
