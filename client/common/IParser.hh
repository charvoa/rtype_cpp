//
// IParser.hh for IParser in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:49:47 2015 Viveka BARNEAUD
// Last update Thu Dec  3 16:57:37 2015 Nicolas Girardot
//

#ifndef IPARSER_H
#define IPARSER_H

#include <string>

class IParser
{
public:
    virtual std::string getValueOf(const std::string &) const = 0;
};

#endif // IPARSER_H
