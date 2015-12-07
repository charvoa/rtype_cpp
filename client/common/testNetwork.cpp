#include "../../common/Network.hpp"

int	main()
{
  Network *net = new Network();
  net->init(4253, ANetwork::TCP_MODE);
  net->connect("10.16.253.141");
  net->write((void *)"Salut JOJO\r\n", (int)strlen("Salut JOJO\r\n"));
}
