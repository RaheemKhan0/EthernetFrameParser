#include "ethernet.h"
#include "tap.h"
#include <stdint.h>
#include <stdio.h>

int main() {

  int fd = tap_open("tap0");
  if (fd < 0) {
    return 1;
  }
  printf("TAP device opened, listening...\n");
  uint8_t buffer[1514];

  while (1) {
    int n = tap_read(fd, buffer, sizeof(buffer));
    if (n < 0)
      break;
    if (n < 14)
      continue;
    parse_ethernet_frame(buffer, n);
  }
  tap_close(fd);
  return 0;
}
