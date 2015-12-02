//
// CRC.hpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Wed Dec  2 04:19:10 2015 Serge Heitzler
// Last update Wed Dec  2 04:19:22 2015 Serge Heitzler
//

#ifndef _CRC_HPP_
# define _CRC_HPP_

#include <string>

class			CRC
{
 public:
  explicitCRC() {}
  virtual~CRC() {}
  
  static bool		verifyCRC(int crc, const std::string &str)
  {
    if (crc == CRC::calcCRC(str))
      return(true);
    return (false);
  }
  
  static int		calcCRC(const std::string &str)
  {
    int		sum = 0;
    int		i = 0;

    while (str.c_str()[i])
      {
	sum += str.c_str()[i];
	i++;
      }
    return (sum);
  }
};

#endif /* !CRC_HPP_ */
