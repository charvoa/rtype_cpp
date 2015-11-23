#ifndef IPARSER_H
#define IPARSER_H

class IParser
{
public:
    virtual std::string getValueOf(std::string const&) = 0;
    virtual void    setValueOf(std::string const&, std::string const&) = 0;
};

#endif // IPARSER_H
