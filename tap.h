#ifndef TAP_H
#define TAP_H

#include <stdint.h>
int tap_open(const char* dev);
int tap_read(int fd, uint8_t *buf, int buflen);
int tap_write(int fd, uint8_t *buf, int buflen);
void tap_close(int fd);



#endif // !DEBUG
