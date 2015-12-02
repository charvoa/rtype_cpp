//
// GameManager.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:26:52 2015 Nicolas Charvoz
// Last update Wed Dec  2 13:31:58 2015 Nicolas Charvoz
//

#include "GameManager.hh"

GameManager::GameManager() {}

GameManager::~GameManager() {}

Game &GameManager::createGame() {
  Game *g = new Game();
  return *g;
}

Game &GameManager::getGameById(const std::string &s) {
  (void)s;
  Game *g = new Game();
  return *g;
}

Game &GameManager::getGameByClient(Client &c) {
  (void)c;
  Game *g = new Game();
  return *g;
}
