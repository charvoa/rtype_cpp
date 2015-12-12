#include	<File.hpp>
#include <stdio.h>

void		my_cb(int p, void *data) {
  printf("\rReceived : %d%%  ", p);
  fflush(stdout);
}

int	main() {
  int	port = 6545, i = 1;

  while (1) {
    File	file;

    file.receiveMe("10.16.252.249", port++, "./recv/", my_cb, NULL);
    printf("\nSent %d Finished !\n", i++);
  }
}
