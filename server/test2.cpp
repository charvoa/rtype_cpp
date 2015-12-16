#include	<MicrophoneReceiver.hpp>

int		main(int ac, char **av)
{
  MicrophoneReceiver	micro;

  try {
    micro.init();
    sleep(5);
    micro.play();
    while (micro.getStatus() == MicrophoneReceiver::Playing)
      sf::sleep(sf::seconds(0.1f));
  } catch (const std::exception &e) {
    std::cout << "Error catched : " << e.what() << std::endl;
  }
  return (0);
}
