#include <fcntl.h> // open, O_RDWR
#include <linux/if.h>
#include <linux/if_tun.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h> // ioctl
#include <unistd.h>    // close
int tap_open(const char *dev) {
  int fd = open("/dev/net/tun", O_RDWR);

  if (fd < 0) {
    perror("open /dev/net/tun");
    return -1;
  }
  struct ifreq ifr;
  memset(&ifr, 0, sizeof(ifr));

  ifr.ifr_flags = IFF_TAP | IFF_NO_PI;

  strncpy(ifr.ifr_name, dev, IFNAMSIZ);
  if (ioctl(fd, TUNSETIFF, &ifr) < 0) {
    perror("ioctl TUNSETIFF");
    close(fd);
    return -1;
  }

  return fd;
}
int tap_read(int fd, uint8_t *buf, int buflen) {
  int n = read(fd, buf, buflen);
  if (n < 0) {
    perror("tap read");
    return -1;
  }
  return n;
}

