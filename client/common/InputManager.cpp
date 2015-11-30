//
// InputManager.cpp for InputManager in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Wed Nov 25 05:52:02 2015 Serge Heitzler
// Last update Wed Nov 25 05:57:57 2015 Serge Heitzler
//

#include "InputManager.hh"

InputManager::InputManager()
{
_functions.insert(std::make_pair(C_HANDSHAKE, &ProtocolClient::handshake));
  _functions.insert(std::make_pair(C_HANDSHAKE, &ProtocolClient::handshake));
  _functions.insert(std::make_pair(C_SUCCESS, &ProtocolClient::success));
  _functions.insert(std::make_pair(C_ERROR, &ProtocolClient::error));
  _functions.insert(std::make_pair(C_SIGNUP, &ProtocolClient::signup));
  _functions.insert(std::make_pair(C_SIGNIN, &ProtocolClient::signin));
  _functions.insert(std::make_pair(C_CALL_REQUEST, &ProtocolClient::callRequest));
  _functions.insert(std::make_pair(C_HANGUP, &ProtocolClient::hangUp));
  _functions.insert(std::make_pair(C_SEND_TEXT, &ProtocolClient::sendText));
  _functions.insert(std::make_pair(C_PONG, &ProtocolClient::pong));
  _functions.insert(std::make_pair(C_ACCEPT_CALL, &ProtocolClient::acceptCall));
  _functions.insert(std::make_pair(C_DECLINE_CALL, &ProtocolClient::declineCall));
  _functions.insert(std::make_pair(C_ADD_CONTACT, &ProtocolClient::addContact));
  _functions.insert(std::make_pair(C_ACCEPT_INVITATION, &ProtocolClient::acceptInvitation));
  _functions.insert(std::make_pair(C_DECLINE_INVITATION, &ProtocolClient::declineInvitation));
  _functions.insert(std::make_pair(C_MODIFY_STATUS, &ProtocolClient::modifyStatus));
  _functions.insert(std::make_pair(C_MODIFY_LOGIN, &ProtocolClient::modifyLogin));
  _functions.insert(std::make_pair(C_MODIFY_LOCATION, &ProtocolClient::modifyLocation));
  _functions.insert(std::make_pair(C_MUTE, &ProtocolClient::mute));
  _functions.insert(std::make_pair(C_ADD_PARTICIPANT_TO_CALL, &ProtocolClient::addParticipantToCall));
  _functions.insert(std::make_pair(C_ADD_TO_FAVORITES, &ProtocolClient::addToFavorites));
  _functions.insert(std::make_pair(C_REMOVE_FROM_FAVORITES, &ProtocolClient::removeFromFavorites));
  _functions.insert(std::make_pair(C_ADD_NICKNAME, &ProtocolClient::addNickname));
  _functions.insert(std::make_pair(C_REMOVE_CONTACT, &ProtocolClient::removeContact));
  _functions.insert(std::make_pair(C_MODIFY_PROFIL_PICTURE, &ProtocolClient::modifyProfilePicture));
  _functions.insert(std::make_pair(C_SEND_FILE, &ProtocolClient::sendFile));
  _functions.insert(std::make_pair(C_LISTEN_TO_MAIL, &ProtocolClient::listenToMail));

}

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

