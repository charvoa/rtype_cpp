//
// CreateRequest.hpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Dec  4 23:35:41 2015 Nicolas Charvoz
// Last update Fri Dec  4 23:54:21 2015 Nicolas Charvoz
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

    frame._keyPintade = key_;
    frame._requestType = type_;
    frame._idRequest = id_;
    frame._crc = crc_;
    frame._sizeData = size_;
    strcpy(frame._data, data_);

    return frame;
  };

  static short int getKey(ANetwork::t_frame &frame) {
    return frame._keyPintade;
  };

  static unsigned char  getType(ANetwork::t_frame &frame) {
    return frame._requestType;
  };

  static unsigned int getId(ANetwork::t_frame &frame) {
    return frame._idRequest;
  };

  static int getCrc(ANetwork::t_frame &frame) {
    return frame._crc;
  };

  static int getSize(ANetwork::t_frame &frame) {
    return frame._sizeData;
  };

  static char *getData(ANetwork::t_frame &frame) {
    return frame._data;
  };

};

#endif
