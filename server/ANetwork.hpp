//
// ANetwork.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:38:49 2015 Nicolas Charvoz
// Last update Mon Nov 30 17:55:15 2015 Nicolas Charvoz
//

#ifndef ANETWORK_HH_
# define ANETWORK_HH_

class ANetwork {

public :
  typedef struct s_frame {
    short int _keyPintade;
    unsigned char _requestType;
    unsigned int _idRequest;
    int _crc;
    int _sizeData;
    char _data[49];
  } t_frame;

};

#endif
