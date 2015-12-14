#include	<File.hpp>

void		my_cb(int percentage, void *data) {
  printf("\rSending ... %d%%  ", percentage);
  fflush(stdout);
}

int		main() {
  int		port = 6545, i = 1;

  while (1) {
    try {
      File		file("menuMusic.ogg");
      file.sendMe(port++);
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    printf("\nSent %d Finished !\n", i++);
  }
}
