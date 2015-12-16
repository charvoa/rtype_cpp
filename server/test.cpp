#include	<Microphone.hpp>

int		main(int ac, char **av)
{
  Microphone	micro;

  try {
    micro.init();
    micro.start(44100);
    sleep(30);
    micro.stop();
    // sf::Sound	    sound;

    // sound.setBuffer(micro.getBuffer());
    // sound.play();
    // sleep(20);
  } catch (const std::exception &e) {
    std::cout << "Error catched " << e.what() << std::endl;
  }
 return (0);
}

