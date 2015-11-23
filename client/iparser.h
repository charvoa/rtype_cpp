#ifndef IPARSER_H
#define IPARSER_H


class IParser
{
public:
    virtual void parseFile(std::string const& filename) = 0;
};

#endif // IPARSER_H
