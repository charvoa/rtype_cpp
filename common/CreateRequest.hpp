//
// CreateRequest.hpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Dec  4 23:35:41 2015 Nicolas Charvoz
// Last update Sun Dec  6 08:45:53 2015 Antoine Garcia
//

#ifndef _CREATEREQUEST_HPP_
# define _CREATEREQUEST_HPP_

# define KEY_PINTADE 2965

# include <cstring>
# include <string>
# include <iostream>
# include <E_Command.hh>
# include <ANetwork.hpp>

class CreateRequest {

public:

  CreateRequest() {};
  ~CreateRequest() {};

  static ANetwork::t_frame create(unsigned char id_, int crc_, int size_,
				  const std::string &data_)
  {
    ANetwork::t_frame frame;

    frame.keyPintade = KEY_PINTADE;
    frame.idRequest = id_;
    frame.crc = crc_;
    frame.sizeData = size_;
    strcpy(frame.data, data_.c_str());

    return frame;
  };

  static short int getKey(ANetwork::t_frame &frame) {
    return frame.keyPintade;
  };

  static unsigned int getId(ANetwork::t_frame &frame) {
    return frame.idRequest;
  };

  static int getCrc(ANetwork::t_frame &frame) {
    return frame.crc;
  };

  static int getSize(ANetwork::t_frame &frame) {
    return frame.sizeData;
  };

  static char *getData(ANetwork::t_frame &frame) {
    return frame.data;
  };

};

#endif
