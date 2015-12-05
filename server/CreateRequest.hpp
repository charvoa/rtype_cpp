//
// CreateRequest.hpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Dec  4 23:35:41 2015 Nicolas Charvoz
// Last update Sat Dec  5 05:29:12 2015 Louis Audibert
//

#ifndef _CREATEREQUEST_HPP_
# define _CREATEREQUEST_HPP_

# include <string>
# include <iostream>
# include <E_Command.hh>
# include <ANetwork.hpp>


class CreateRequest {

public:

  CreateRequest() {};
  ~CreateRequest() {};

  static ANetwork::t_frame create(short int key_, unsigned char type_,
			   unsigned int id_, int crc_, int size_,
			   char data_[])
  {
    ANetwork::t_frame frame;

    frame.keyPintade = key_;
    frame.requestType = type_;
    frame.idRequest = id_;
    frame.crc = crc_;
    frame.sizeData = size_;
    strcpy(frame.data, data_);

    return frame;
  };

  static short int getKey(ANetwork::t_frame &frame) {
    return frame.keyPintade;
  };

  static unsigned char  getType(ANetwork::t_frame &frame) {
    return frame.requestType;
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
