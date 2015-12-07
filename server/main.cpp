//
// main.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Last update Mon Dec  7 14:38:36 2015 Nicolas Charvoz
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
#include <ANetwork.hpp>
#include <CreateRequest.hpp>
#include <chrono>
#include <thread>

AMutex *m;

void *save_page(void *s)
{
  m->lock();
  std::cout << "this thread is called" << std::endl;
  m->unlock();
  return s;
}

int		main(int ac, char **av)
{
  Server	*s = new Server();

  (void)ac;
  (void)av;


  /* TEST */
  m = new Mutex();

  // AThread *t1 = new Thread(1);
  // AThread *t2 = new Thread(2);

  std::unique_ptr<AThread> t1(new Thread(1));
  std::unique_ptr<AThread> t2(new Thread(2));

  char str1[] = "http://foo";
  char str2[] = "http://bar";

  t1->attach(&save_page, (void*)str1);
  t2->attach(&save_page, (void*)str2);

  t1->run();
  t2->run();
  t1->join();
  t2->join();

  ANetwork::t_frame frame;

  frame = CreateRequest::create(1, 12, 3, "data");

  std::cout << "frame data : " << CreateRequest::getData(frame) << std::endl;
  /* FIN DU GAME */

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
