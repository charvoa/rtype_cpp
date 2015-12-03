//
// main.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Last update Thu Dec  3 05:18:57 2015 Louis Audibert
// Last update Mon Nov 30 05:50:36 2015 Antoine Garcia
//

# include	<Server.hh>
# include	<EntityManager.hh>
#ifdef __unix__
# include	"../common/Thread/ThreadUnix.hpp"
#elif defined(_WIN32) || defined(WIN32)
# include 	"../common/Thread/ThreadWin.hpp"
#endif

#include <Mutex.hpp>
#include <chrono>
#include <thread>

std::map<std::string, std::string> g_pages;
AMutex *m;

void *save_page(void *s)
{

  std::string result = "fake content";

  m->lock();
  g_pages[(const std::string&)s] = result;
  m->unlock();

  return s;
}

void save_page2(const std::string &url)
{

  std::string result = "fake content";

  m->lock();
  g_pages[url] = result;
  m->unlock();
}


int		main(int ac, char **av)
{
  Server	*s = new Server();

  (void)ac;
  (void)av;

  m = new Mutex();

  std::thread t1(save_page2, "http://foo");
  std::thread t2(save_page2, "http://bar");

  t1.join();
  t2.join();

  // AThread *t1 = new Thread(1);
  // AThread *t2 = new Thread(2);

  // char *str1 = "http://foo";
  // char *str2 = "http://bar";

  // t1->attach(&save_page, (void*)str1);
  // t2->attach(&save_page, (void*)str2);

  // t1->run();
  // t2->run();
  // t1->join();
  // t2->join();

  m->lock();
  for (const auto &pair : g_pages) {
    std::cout << pair.first << " => " << pair.second << '\n';
  }
  m->unlock();

  try {
    s->init();
    std::cout << "You've launched the Server of the RType" << std::endl;

    std::cout << "Made by La Pintade" << std::endl;
    s->run();
  } catch (const std::exception &e) {
    std::cout << "Error catched : " << e.what() << std::endl;
  }
  return (0);
}
