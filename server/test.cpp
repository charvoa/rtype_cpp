#include	<File.hpp>

void		my_cb(int percentage, void *data) {
  printf("\rSending ... %d%%  ", percentage);
  fflush(stdout);
}

int		main() {
  File		file("menuMusic.ogg");

  try {
    file.sendMe(4565, my_cb, NULL);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  printf("\nFinished !\n");
}
