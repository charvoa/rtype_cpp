#include	<File.hpp>
#include <stdio.h>

void		my_cb(int p, void *data) {
  printf("\rReceived : %d%%  ", p);
  fflush(stdout);
}

int	main() {
  File	file;

  file.receiveMe("10.16.252.249", 4565, "./recv/", my_cb, NULL);
  printf("\nFinished !\n");
}
