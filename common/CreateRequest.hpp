//
// CreateRequest.hpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Dec  4 23:35:41 2015 Nicolas Charvoz
// Last update Mon Dec 14 17:51:08 2015 Joris Bertomeu
//

#ifndef _CREATEREQUEST_HPP_
# define _CREATEREQUEST_HPP_

# define KEY_PINTADE 2965

# include <cstring>
# include <string>
# include <iostream>
# include <ProtocoleEnum.hh>
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
    memset(frame.data, 0, 49);
    memcpy(frame.data, data_.c_str(), data_.size());

    return frame;
  };

  static ANetwork::t_frame *create(unsigned char id_, int crc_, int size_,
				   const std::string &data_, bool ret)
  {
    (void)ret;
    ANetwork::t_frame *frame = (ANetwork::t_frame*)
      malloc(sizeof(ANetwork::t_frame));

    memset(frame, 0, sizeof(ANetwork::t_frame));
    frame->keyPintade = KEY_PINTADE;
    frame->idRequest = id_;
    frame->crc = crc_;
    frame->sizeData = size_;
    memset(frame->data, 0, 49);
    memcpy(frame->data, data_.c_str(), data_.size());

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
