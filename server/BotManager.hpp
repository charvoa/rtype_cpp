//
// BotManager.hpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Sat Dec 12 02:10:01 2015 Joris Bertomeu
// Last update Tue Dec 22 14:43:38 2015 Antoine Garcia
//

#ifndef			_BOTMANAGER_HPP_
# define		_BOTMANAGER_HPP_

# include      		<FileManager.hpp>
# include		<string>
# include		<list>
# include		<Bot.hpp>
# include		<EntityFactory.hh>
# include <Random.hpp>
class			BotManager
{
private:
  std::string		_dir;
  std::list<Bot*>	_botList;
  FileManager		*_fileManager;
  EntityFactory		_ef;

public:
  explicit		BotManager(const std::string &dir) : _dir(dir) {
    std::list<File*>	list;
    int			id = 1;

    this->_fileManager = new FileManager(dir);
# ifdef			_WIN32
    list = this->_fileManager->getFileListByExtension("dll");
# else
    list = this->_fileManager->getFileListByExtension("so");
# endif
    for (std::list<File*>::iterator it = list.begin(); it != list.end(); ++it) {
      this->_botList.push_back((Bot*) this->_ef.createEntity((*it)->getFullPath(), id));
    }
  }

  std::list<Bot*>	getBotList() {
    return (this->_botList);
  }

  std::list<Bot*>	createBot()
  {
    std::list<Bot*>	list;
    std::list<File *> fileList;
    std::list<File*> fileBots;
    int			id = 1;
# ifdef			_WIN32
    fileList = this->_fileManager->getFileListByExtension("dll");
# else
    fileList = this->_fileManager->getFileListByExtension("so");
# endif
    for (auto it = fileList.begin(); it != fileList.end(); ++it)
      {
	if (!((*it)->getFullPath().find("boss") != std::string::npos))
	  {
	    fileBots.push_back(*it);
	  }
      }
    Random rand(0 ,fileBots.size());
    int i = rand.generate<int>();
    auto it = fileBots.begin();
    std::advance(it, i);
    list.push_back((Bot*) this->_ef.createEntity((*it)->getFullPath(), id));
    return list;
  }

std::list<Bot*>	createBoss()
{
  std::list<Bot*>	list;
  std::list<File *> fileList;
  int			id = 1;
# ifdef			_WIN32
  fileList = this->_fileManager->getFileListByExtension("dll");
# else
  fileList = this->_fileManager->getFileListByExtension("so");
# endif
  for (auto it = fileList.begin(); it != fileList.end(); ++it)
    {
      if ((*it)->getFullPath().find("boss") != std::string::npos)
	{
	  std::cout << "FIND BOSS" << std::endl;
	  list.push_back((Bot*) this->_ef.createEntity((*it)->getFullPath(), id));
	}
    }
  return list;
}
};
#endif
